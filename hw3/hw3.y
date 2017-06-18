%{
// header files.
#include <stdio.h>
#include <stdlib.h>
#include "SymbolTable.h"
extern int lineCount;
extern char* yytext;	
extern void print_line(); 

FILE *f_asm;

 int FunctionNum = 0;
    int LocalOffset = 0;
    int LabelNum = 2;

%}

%start start_point

%union { 
         int       token ;
		 // char value
		 int 	   intv;
         char      charv ;
         char      *ident;
       }
	   
/* all identifiers that are not reserved words
   and are not declared typedefs in the current block */	   
%token IDENTIFIER INTEGER FLOAT

/* reserved words that specify storage class.
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token SCSPEC

/* reserved words that specify type.
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token TYPESPEC VOIDTYPE TRUEFALSE

/* reserved words that modify type: "const" or "volatile".
   yylval contains an IDENTIFIER_NODE which indicates which one.  */
%token TYPEMOD	
%token CONSTANT CHAR String

/* the reserved words */
%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT_TOKEN
%token BREAK CONTINUE RETURN 

%type <ident> notype_declarator IDENTIFIER primary expr_no_commas whether_return 
%type <token> CONSTANT String

%type <ident> multiple_define single_define initialize initialize_item many
%type <ident> switch_f case_f switch_default_f case_expr
%type <ident> if_f else_f while_f do_f for_f for_stmt stmts_or_null notype_declarator_void notype_declarator_para
%type <ident> start_point INT_CONSTANT simple_stmt add_expr mul_expr primary_expr

%type <charv> CHAR

//my code
%type <ident> arrays array

/* Define the operator tokens and their precedences.
   The value is an integer because, if used, it is the tree code
   to use in the expression made from the operator.  */
%left  <charv> ';' 
%left IDENTIFIER  SCSPEC TYPESPEC TYPEMOD VOIDTYPE 
%left  <charv> ','
%right <charv> '='
%right <token> ASSIGN


%left <token> PLUSPLUS_OP MINUSMINUS_OP
%left <token> MUL_OP DIV_OP MOD_OP
%left <token> MINUS_OP PLUS_OP
%left <token> LT_OP LE_OP GT_OP GE_OP EQUAL_OP NEQUAL_OP
%left <token> NOT_OP
%left <token> AND_OP
%left <token> OR_OP


%left <charv> OROR
%left <charv> ANDAND
%left <token> '!'
%left <token> EQCOMPARE
%left <token> ARITHCOMPARE  '>' '<' 
%left <charv> '+' '-'
%left <token> '*' '/' '%'
%left <token> TRUEFALSE DOUBLEDOUBLE
%left <token> '[' ']'
%right <token> UNARY 	   
 
 
%{

int TRACEON = 0;
int function_call_amount = 0;


%}      
 
	   
%%
start_point: TYPESPEC IDENTIFIER 
			{
				install_symbol($2);
				cur_scope++;
			} 
		  '(' ')' '{' xdecls stmts RETURN CONSTANT ';' '}'
          { if (TRACEON) printf("1\n ");
				cur_scope--;
		  }
	;
	
xdecls:
	/* empty */
           { if (TRACEON) printf("102 ") ; }
	| decls
           { if (TRACEON) printf("103 ") ; }
	;
	
decls:
	decl
           { if (TRACEON) printf("104 ") ;}
	| decls decl
           { if (TRACEON) printf("106 ") ;}
	;
	
decl:	 
	TYPESPEC notype_declarator ';'
            { 
				if (TRACEON) printf("110 ") ;
			}
			
notype_declarator:
	IDENTIFIER '=' INT_CONSTANT
			{   
                          install_symbol($1);
                          int index = look_up_symbol($1);

                          /* Setting, use set_local_vars will be too late */
                          table[index].offset = LocalOffset++;
                          table[index].mode  = LOCAL_MODE;

                          /* Pop Expression to $r0 */
                          PopReg(0);

                          /* Store it to var */
                          fprintf(f_asm, "    swi $r0, [$sp+%d]\n",table[index].offset*4);
				
			}
	;
	
INT_CONSTANT:	
	CONSTANT 	{
							$$ = NULL;
                            /* Move num to $r0 and push to stack */
                            fprintf(f_asm, "    movi $r0, %d\n",$1);
                            PushReg(0);
				}
	;

stmt_list:
	// null {}
	| stmts {}
	;

stmts:
	stmt
               { if (TRACEON) printf("29 ") ;  }
	| stmts stmt
               { if (TRACEON) printf("30 ") ;  }
	;
	
stmt:
	simple_stmt{}
	|	 IF_Statement{}
	|	 While_Statement{}
	;

While_Statement:
                        WHILE
                        {
                            /* Label for checking expression */
                            fprintf(f_asm, ".L%d:\n", LabelNum);
                        }
                        '(' Expression ')'
                        {
                            /* Pop expression, if false go to end */
                            PopReg(0);
                            fprintf(f_asm, "    beqz $r0, .L%d\n", LabelNum+1);
                        }
                        Compound_Statement
                        {
                            /* Jump back to check expression */
                            fprintf(f_asm, "    j .L%d\n", LabelNum);

                            /* End , if false , branch to here */
                            fprintf(f_asm, ".L%d:\n", LabelNum+1);
                            LabelNum += 2;
                        }
	
	
IF_Statement:   IF '(' Expression ')'
                        {
                            /* Pop expression to r0 */
                            PopReg(0);

                            fprintf(f_asm, "    beqz $r0, .L%d\n", LabelNum);
                            /* If true, continue to compound statment */
                        }
                Compound_Statement Selection_Statement_Tail	

Selection_Statement_Tail:    /* empty, only if */
                             {
                                 /* If false, ignore the compound statement. Branch to End */
                                 fprintf(f_asm, ".L%d:\n", LabelNum);
                                 LabelNum++;
                             }
                        |    ELSE
                             {
                                 /* If true, after compound statement. Must ignore else and branch to End */
                                 fprintf(f_asm, "    j .L%d\n", LabelNum+1);

                                 /* If false, ignore the compound statement. Branch to ELSE */
                                 fprintf(f_asm, ".L%d:\n", LabelNum);
                             }
                             Compound_Statement
                             {
                                 /* End */
                                 fprintf(f_asm, ".L%d:\n", LabelNum+1);
                                 LabelNum += 2;
                             }
                        ;
				
Compound_Statement:   '{'
                      {
                          cur_scope++;
                          //LocalOffset = 0;
                      }
                      xdecls
                      {
						
                      }
                      stmt_list '}'
                      {
                          cur_scope--;
                      }
                  ;		
				
		
Expression:   Logical_Expression
          ;
	
Logical_Expression:
		add_expr
		{}
	|	Logical_Expression OR_OP add_expr	
		{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    or $r0, $r0, $r1\n");
                              PushReg(0);
		}
	|	Logical_Expression AND_OP add_expr	
		{
                               PopReg(0);
                               PopReg(1);
                               fprintf(f_asm, "    and $r0, $r0, $r1\n");
                               PushReg(0);
		}
	|	NOT_OP Logical_Expression	
		{
							   PopReg(0);
							   fprintf(f_asm, "    addi $r0, $r0, 0\n"); /* ??? */
							   fprintf(f_asm, "    slti $r0, $r0, 1\n");
							   fprintf(f_asm, "    zeb $r0, $r0\n");
							   PushReg(0);
		}
	|	Logical_Expression '<' add_expr	
		{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r1, $r0\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
	|	Logical_Expression LE_OP  add_expr	
		{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r0, $r1\n"); /* $r1 > $r0 ? */
                              fprintf(f_asm, "    xori $r0, $r0, 1\n"); /* if $r0 == 1, $r0 = 0 */
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
	|	Logical_Expression '>'   add_expr	
		{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r0, $r1\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
	|	Logical_Expression GE_OP   add_expr	
		{
                               PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r1, $r0\n"); /* $r1 < $r0 ? */
                              fprintf(f_asm, "    xori $r0, $r0, 1\n"); /* if $r0 == 1, $r0 = 0 */
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
	|	Logical_Expression EQUAL_OP   add_expr	
		{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    xor $r0, $r0, $r1\n"); /* If $r0 == $r1 , then result of xor will be 0 --> < 1 */
                              fprintf(f_asm, "    slti $r0, $r0, 1\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
	|	Logical_Expression NEQUAL_OP   add_expr	
		{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    xor $r0, $r0, $r1\n"); /* If $r0 != $r1 , then result of xor will be > 0 */
                              fprintf(f_asm, "    movi $r1, 0\n");
                              fprintf(f_asm, "    slt $r0, $r1, $r0\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
	;
		

		  

simple_stmt:
	IDENTIFIER '=' add_expr ';'
		{
                         int index = look_up_symbol($1);

                         /* Pop Expression to $r0 */
                         PopReg(0);

                         /* Store it to var */
                         fprintf(f_asm, "    swi $r0, [$sp+%d]\n",table[index].offset*4);
		}
	;
	
add_expr: 
	mul_expr 
		{
		
		}
	| add_expr '+' mul_expr
		{
                            PopReg(0);
                            PopReg(1);
                            fprintf(f_asm, "    add $r0, $r1, $r0\n");
                            PushReg(0);
		}
	| add_expr '-' mul_expr
		{
                            PopReg(0);
                            PopReg(1);
                            fprintf(f_asm, "    sub $r0, $r1, $r0\n");
                            PushReg(0);
		}
	;

mul_expr: 
	primary_expr
		{
			
		}
	|	mul_expr '*' primary_expr
		{
                                  PopReg(0);
                                  PopReg(1);
                                  fprintf(f_asm, "    mul $r0, $r1, $r0\n");
                                  PushReg(0);	
		}
	|	mul_expr '/' primary_expr
		{
                                  PopReg(2);
                                  PopReg(3);
                                  fprintf(f_asm, "    divsr $r0, $r1, $r3, $r2\n");
                                  PushReg(0);
		}
	;
	
primary_expr:
	IDENTIFIER
		{
                                 int index = look_up_symbol($1);

                                 /* Load to r0 */
                                 switch(table[index].mode)
                                 {
                                     case ARGUMENT_MODE:
                                         fprintf(f_asm, "    lwi $r0, [$sp+%d]\n",table[index].offset*4);
                                         break;
                                     case LOCAL_MODE:
                                         fprintf(f_asm, "    lwi $r0, [$sp+%d]\n",table[index].offset*4);
                                         break;
                                     /* global */
                                 }

                                 /* Push to stack */
                                 PushReg(0);
		}
	|	CONSTANT 
		{
                                $$ = NULL;

                                /* Move num to $r0 and push to stack */
                                fprintf(f_asm, "    movi $r0, %d\n",$1);
                                PushReg(0);
		}
	 |    '(' Expression ')'
		{
		
		}
		;
	
	
primary:
    IDENTIFIER
		{   int index;
            if (TRACEON) printf("20 ") ;
         }
	| CONSTANT
        { 
			if (TRACEON) printf("21 ") ;

                }
        ;
	


	


%%
int main(void) {
  init_symbol_table();
  
  if( (f_asm = fopen("assembly", "w")) == NULL )
        fprintf(stderr, "Can not open the file %s for writing.\n", "assembly");
  
  yyparse();
  if (function_call_amount == 0){
				//close now
				//yyerror(yytext);
		  }
		  
  printf("No syntax error!\n");
  //	printTable();	
  
  fclose(f_asm);
  return 0;
}

int yyerror(char *s) {
  fprintf( stderr, "*** Error at line ");
  print_line();
  fprintf( stderr, "\n" );
  fprintf( stderr, "Unmatched token: %s\n", yytext );
  fprintf( stderr, "*** syntax error\n");
  exit(-1);
}
