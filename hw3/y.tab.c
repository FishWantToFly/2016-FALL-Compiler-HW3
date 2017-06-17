#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "hw3.y"

/* header files.*/
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

#line 20 "hw3.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { 
         int       token ;
		 /* char value*/
		 int 	   intv;
         char      charv ;
         char      *ident;
       } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 83 "hw3.y"


int TRACEON = 0;
int function_call_amount = 0;


#line 57 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENTIFIER 257
#define INTEGER 258
#define FLOAT 259
#define SCSPEC 260
#define TYPESPEC 261
#define VOIDTYPE 262
#define TRUEFALSE 263
#define TYPEMOD 264
#define CONSTANT 265
#define CHAR 266
#define String 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define DO 271
#define FOR 272
#define SWITCH 273
#define CASE 274
#define DEFAULT_TOKEN 275
#define BREAK 276
#define CONTINUE 277
#define RETURN 278
#define expr_no_commas 279
#define whether_return 280
#define multiple_define 281
#define single_define 282
#define initialize 283
#define initialize_item 284
#define many 285
#define switch_f 286
#define case_f 287
#define switch_default_f 288
#define case_expr 289
#define if_f 290
#define else_f 291
#define while_f 292
#define do_f 293
#define for_f 294
#define for_stmt 295
#define stmts_or_null 296
#define notype_declarator_void 297
#define notype_declarator_para 298
#define arrays 299
#define array 300
#define ASSIGN 301
#define OROR 302
#define ANDAND 303
#define EQCOMPARE 304
#define ARITHCOMPARE 305
#define DOUBLEDOUBLE 306
#define UNARY 307
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    8,    0,    9,    9,   11,   11,   12,    1,    3,   10,
   10,   13,    4,    5,    5,    5,    6,    6,    6,    7,
    7,    2,    2,
};
static const short yylen[] = {                            2,
    0,   12,    0,    1,    1,    2,    3,    3,    1,    1,
    2,    1,    4,    1,    3,    3,    1,    3,    3,    1,
    1,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    5,    0,    0,    0,   12,    0,   10,    6,    0,    7,
    0,    0,   11,    9,    8,   20,   21,    0,    0,   17,
    0,   13,    0,    0,    0,    0,    0,    0,    0,   18,
   19,    2,
};
static const short yydgoto[] = {                          2,
   13,    0,   25,   15,   28,   29,   30,    4,    9,   16,
   10,   11,   17,
};
static const short yysindex[] = {                      -247,
 -241,    0,    0,  -15,  -17,  -97, -234, -229, -228, -234,
    0,  -31,  -28,  -29,    0, -257,    0,    0, -232,    0,
 -252, -231,    0,    0,    0,    0,    0,  -42,  -32,    0,
  -24,    0, -252, -252, -252, -252,  -89,  -32,  -32,    0,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0, -241,    0,    0, -220,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -41,    0,
    0,    0,    0,    0,    0,    0,    0,  -37,  -36,    0,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,    0,  -22,  -16,    0,    0,    0,
    0,   28,   23,
};
#define YYTABLESIZE 39
static const short yytable[] = {                         14,
   33,   14,   34,   14,   26,   15,   16,   15,   16,   35,
   38,   39,   27,    1,   36,    3,   32,   14,   40,   41,
   22,   15,   16,    6,    5,    7,    8,   12,   14,   19,
   20,   21,   24,   31,   37,   42,    4,   18,   23,
};
static const short yycheck[] = {                        257,
   43,   43,   45,   45,  257,   43,   43,   45,   45,   42,
   33,   34,  265,  261,   47,  257,   59,   59,   35,   36,
  278,   59,   59,   41,   40,  123,  261,  257,  257,   61,
   59,   61,  265,  265,   59,  125,  257,   10,   16,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDENTIFIER","INTEGER","FLOAT","SCSPEC",
"TYPESPEC","VOIDTYPE","TRUEFALSE","TYPEMOD","CONSTANT","CHAR","String","IF",
"ELSE","WHILE","DO","FOR","SWITCH","CASE","DEFAULT_TOKEN","BREAK","CONTINUE",
"RETURN","expr_no_commas","whether_return","multiple_define","single_define",
"initialize","initialize_item","many","switch_f","case_f","switch_default_f",
"case_expr","if_f","else_f","while_f","do_f","for_f","for_stmt","stmts_or_null",
"notype_declarator_void","notype_declarator_para","arrays","array","ASSIGN",
"OROR","ANDAND","EQCOMPARE","ARITHCOMPARE","DOUBLEDOUBLE","UNARY",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : start_point",
"$$1 :",
"start_point : TYPESPEC IDENTIFIER $$1 '(' ')' '{' xdecls stmts RETURN CONSTANT ';' '}'",
"xdecls :",
"xdecls : decls",
"decls : decl",
"decls : decls decl",
"decl : TYPESPEC notype_declarator ';'",
"notype_declarator : IDENTIFIER '=' INT_CONSTANT",
"INT_CONSTANT : CONSTANT",
"stmts : stmt",
"stmts : stmts stmt",
"stmt : simple_stmt",
"simple_stmt : IDENTIFIER '=' add_expr ';'",
"add_expr : mul_expr",
"add_expr : add_expr '+' mul_expr",
"add_expr : add_expr '-' mul_expr",
"mul_expr : primary_expr",
"mul_expr : mul_expr '*' primary_expr",
"mul_expr : mul_expr '/' primary_expr",
"primary_expr : IDENTIFIER",
"primary_expr : CONSTANT",
"primary : IDENTIFIER",
"primary : CONSTANT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 284 "hw3.y"

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
  printTable();	
  
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
#line 310 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 94 "hw3.y"
	{
				install_symbol(yystack.l_mark[0].ident);
				cur_scope++;
			}
break;
case 2:
#line 99 "hw3.y"
	{ if (TRACEON) printf("1\n ");
				cur_scope--;
		  }
break;
case 3:
#line 106 "hw3.y"
	{ if (TRACEON) printf("102 ") ; }
break;
case 4:
#line 108 "hw3.y"
	{ if (TRACEON) printf("103 ") ; }
break;
case 5:
#line 113 "hw3.y"
	{ if (TRACEON) printf("104 ") ;}
break;
case 6:
#line 115 "hw3.y"
	{ if (TRACEON) printf("106 ") ;}
break;
case 7:
#line 120 "hw3.y"
	{ 
				if (TRACEON) printf("110 ") ;
			}
break;
case 8:
#line 126 "hw3.y"
	{   
				install_symbol(yystack.l_mark[-2].ident);
				int index = look_up_symbol(yystack.l_mark[-2].ident);
				
				table[index].offset = LocalOffset++;
                table[index].mode  = LOCAL_MODE;
				
				fprintf(f_asm, "    lwi $r0, [$sp+0]\n");
                fprintf(f_asm, "    addi $sp, $sp, 4\n");
				fprintf(f_asm, "    swi $r0, [$fp-%d]\n",table[index].offset*4);
				
			}
break;
case 9:
#line 141 "hw3.y"
	{
					yyval.ident = NULL;
					fprintf(f_asm, "    movi $r0, %d\n",yystack.l_mark[0].token);
                    fprintf(f_asm, "    addi $sp, $sp, -4\n");
                    fprintf(f_asm, "    swi $r0, [$sp+0]\n");
				}
break;
case 10:
#line 151 "hw3.y"
	{ if (TRACEON) printf("29 ") ;  }
break;
case 11:
#line 153 "hw3.y"
	{ if (TRACEON) printf("30 ") ;  }
break;
case 12:
#line 158 "hw3.y"
	{
        }
break;
case 13:
#line 164 "hw3.y"
	{
			int index = look_up_symbol(yystack.l_mark[-3].ident);

            /* Pop Expression to $r0 */
            fprintf(f_asm, "    lwi $r0, [$sp+0]\n");
            fprintf(f_asm, "    addi $sp, $sp, 4\n");

            /* Store it to var */
            fprintf(f_asm, "    swi $r0, [$fp-%d]\n",table[index].offset*4);
		}
break;
case 14:
#line 178 "hw3.y"
	{
		
		}
break;
case 15:
#line 182 "hw3.y"
	{
			fprintf(f_asm, "    lwi $r0, [$sp+0]\n");
			fprintf(f_asm, "    lwi $r1, [$sp+4]\n");
			fprintf(f_asm, "    addi $sp, $sp, 8\n");

			fprintf(f_asm, "    add $r0, $r1, $r0\n");

			fprintf(f_asm, "    addi $sp, $sp, -4\n");
			fprintf(f_asm, "    swi $r0, [$sp+0]\n");
		}
break;
case 16:
#line 193 "hw3.y"
	{
			fprintf(f_asm, "    lwi $r0, [$sp+0]\n");
			fprintf(f_asm, "    lwi $r1, [$sp+4]\n");
			fprintf(f_asm, "    addi $sp, $sp, 8\n");

			fprintf(f_asm, "    sub $r0, $r1, $r0\n");

			fprintf(f_asm, "    addi $sp, $sp, -4\n");
			fprintf(f_asm, "    swi $r0, [$sp+0]\n");
		}
break;
case 17:
#line 207 "hw3.y"
	{
			
		}
break;
case 18:
#line 211 "hw3.y"
	{
            fprintf(f_asm, "    lwi $r0, [$sp+0]\n");
            fprintf(f_asm, "    lwi $r1, [$sp+4]\n");
            fprintf(f_asm, "    addi $sp, $sp, 8\n");

            fprintf(f_asm, "    mul $r0, $r1, $r0\n");

            fprintf(f_asm, "    addi $sp, $sp, -4\n");
            fprintf(f_asm, "    swi $r0, [$sp+0]\n");		
		}
break;
case 19:
#line 222 "hw3.y"
	{
            fprintf(f_asm, "    lwi $r2, [$sp+0]\n");
            fprintf(f_asm, "    lwi $r3, [$sp+4]\n");
            fprintf(f_asm, "    addi $sp, $sp, 8\n");

            fprintf(f_asm, "    divsr $r0, $r1, $r3, $r2\n");

            fprintf(f_asm, "    addi $sp, $sp, -4\n");
            fprintf(f_asm, "    swi $r0, [$sp+0]\n");		
		}
break;
case 20:
#line 236 "hw3.y"
	{
			int index = look_up_symbol(yystack.l_mark[0].ident);

            /* Load to r0 */
             switch(table[index].mode)
                {
                    case ARGUMENT_MODE:
                            fprintf(f_asm, "    lwi $r0, [$sp+%d]\n",table[index].offset*4);
                            break;
                    case LOCAL_MODE:
                            fprintf(f_asm, "    lwi $r0, [$fp-%d]\n",table[index].offset*4);
                            break;
                     /* global */
                            }

            /* Push to stack */
             fprintf(f_asm, "    addi $sp, $sp, -4\n");
             fprintf(f_asm, "    swi $r0, [$sp+0]\n");
		}
break;
case 21:
#line 256 "hw3.y"
	{
			yyval.ident = NULL;

            /* Move num to $r0 and push to stack */
            fprintf(f_asm, "    movi $r0, %d\n",yystack.l_mark[0].token);
            fprintf(f_asm, "    addi $sp, $sp, -4\n");
            fprintf(f_asm, "    swi $r0, [$sp+0]\n");
		}
break;
case 22:
#line 269 "hw3.y"
	{   int index;
            if (TRACEON) printf("20 ") ;
         }
break;
case 23:
#line 273 "hw3.y"
	{ 
			if (TRACEON) printf("21 ") ;

                }
break;
#line 707 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
