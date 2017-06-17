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
#line 93 "hw3.y"


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
#define PLUSPLUS_OP 302
#define MINUSMINUS_OP 303
#define MUL_OP 304
#define DIV_OP 305
#define MOD_OP 306
#define MINUS_OP 307
#define PLUS_OP 308
#define LT_OP 309
#define LE_OP 310
#define GT_OP 311
#define GE_OP 312
#define EQUAL_OP 313
#define NEQUAL_OP 314
#define NOT_OP 315
#define AND_OP 316
#define OR_OP 317
#define OROR 318
#define ANDAND 319
#define EQCOMPARE 320
#define ARITHCOMPARE 321
#define DOUBLEDOUBLE 322
#define UNARY 323
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    8,    0,    9,    9,   11,   11,   12,    1,    3,   13,
   13,   10,   10,   14,   14,   18,   15,   19,   20,   19,
   21,   22,   17,   16,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,    4,    5,    5,    5,    6,    6,
    6,    7,    7,    7,    2,    2,
};
static const short yylen[] = {                            2,
    0,   12,    0,    1,    1,    2,    3,    3,    1,    0,
    1,    1,    2,    1,    1,    0,    7,    0,    0,    3,
    0,    0,    6,    1,    1,    3,    3,    2,    3,    3,
    3,    3,    3,    3,    4,    1,    3,    3,    1,    3,
    3,    1,    1,    3,    1,    1,
};
static const short yydefred[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    5,    0,    0,    0,    0,   14,    0,   12,   15,    6,
    0,    7,    0,    0,    0,   13,    9,    8,   42,   43,
    0,    0,    0,   39,    0,    0,    0,    0,    0,    0,
   35,    0,    0,    0,    0,    0,   16,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   44,    0,    0,   40,
   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,   21,    0,    0,   19,   17,   22,    0,    0,   20,
    0,    0,   23,
};
static const short yydgoto[] = {                          2,
   13,    0,   28,   16,   36,   33,   34,    4,    9,   17,
   10,   11,   82,   18,   19,   37,   73,   62,   76,   78,
   74,   79,   38,
};
static const short yysindex[] = {                      -228,
 -220,    0,    0,    5,    7,  -69, -205, -196, -234, -205,
    0,    1,   10,    6,   24,    0, -225,    0,    0,    0,
 -199,    0,  -39,  -37, -195,    0,    0,    0,    0,    0,
  -37,  -28,  -17,    0,  -37,   -3,   31,  -55,   15,   34,
    0,  -39,  -39,  -39,  -39,  -51,    0,  -39,  -39,  -39,
  -39,  -39,  -39,  -39,  -39,  -48,    0,  -17,  -17,    0,
    0,  -45,   -3,   -3,   -3,   -3,   -3,   -3,   -3,   -3,
    0,    0, -187, -205,    0,    0,    0,  -45, -234,    0,
 -234,  -42,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0, -222,    0,    0, -112,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -41,    0,    0,  -13,    0,   44,    0,    0,
    0,    0,    0,    0,    0,   59,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -33,  -21,    0,
    0,    0,   -5,    3,   11,   19,   27,   35,   43,   51,
    0,    0, -119, -111,    0,    0,    0,    0,  -34,    0,
  -32,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,   67,    8,   14,    0,   12,    9,
    0,   84,    0,   -1,    0,   65,   20,    0,    0,    0,
    0,    0,   64,
};
#define YYTABLESIZE 373
static const short yytable[] = {                         36,
   31,   36,   31,   36,   55,   18,   54,   37,   55,   37,
   54,   37,    4,    3,   42,   26,   43,   36,   36,   38,
   36,   38,   14,   38,   44,   37,   37,   25,   37,   45,
   41,   14,    1,   15,    3,   30,    3,   38,   38,   42,
   38,   43,   15,   32,    5,    3,   25,    6,   25,   58,
   59,   33,   25,    7,   30,    8,   30,   60,   61,   34,
   12,   21,   32,   24,   32,   27,   23,   27,   22,   39,
   33,   47,   33,   56,   57,   26,   71,   72,   34,   26,
   34,   75,   83,   31,   24,   77,   27,   81,   27,   32,
   10,   29,   11,   20,   26,   40,   26,   80,   46,   28,
    0,    0,   31,    0,   31,    0,    0,    0,    0,    0,
   29,    0,   29,    0,   63,   64,   65,   66,   67,   68,
   69,   70,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   18,    0,    0,
    0,    0,    0,    0,    4,    3,    0,    0,   18,    0,
    0,    0,    0,    0,    0,    4,    3,    0,   18,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,   29,
    0,    0,    0,    0,    0,   30,    0,   30,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   48,    0,   49,   50,   51,    0,
   52,   53,    0,    0,   52,   53,    0,    0,   36,    0,
   36,   36,   36,    0,   36,   36,   37,   35,   37,   37,
   37,    0,   37,   37,    0,    0,    0,    0,   38,    0,
   38,   38,   38,    0,   38,   38,   25,    0,   25,   25,
   25,    0,   25,   25,   30,    0,   30,   30,   30,    0,
   30,   30,   32,    0,   32,   32,   32,    0,   32,   32,
   33,    0,   33,   33,   33,    0,   33,   33,   34,    0,
   34,   34,   34,    0,   34,   34,   27,    0,   27,   27,
   27,    0,   27,   27,   26,    0,   26,   26,   26,    0,
   26,   26,   31,    0,   31,   31,   31,    0,   31,   31,
   29,    0,   29,   29,   29,    0,   29,   29,   28,    0,
   28,   28,   28,
};
static const short yycheck[] = {                         41,
   40,   43,   40,   45,   60,  125,   62,   41,   60,   43,
   62,   45,  125,  125,   43,   17,   45,   59,   60,   41,
   62,   43,  257,   45,   42,   59,   60,   41,   62,   47,
   59,  257,  261,  268,  257,   41,  257,   59,   60,   43,
   62,   45,  268,   41,   40,  268,   60,   41,   62,   42,
   43,   41,  278,  123,   60,  261,   62,   44,   45,   41,
  257,   61,   60,   40,   62,  265,   61,   41,   59,  265,
   60,   41,   62,   59,   41,   41,  125,  123,   60,   81,
   62,  269,  125,   41,   41,   74,   60,   79,   62,   23,
  125,   41,  125,   10,   60,   31,   62,   78,   35,   41,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   60,   -1,   62,   -1,   48,   49,   50,   51,   52,   53,
   54,   55,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  257,   -1,   -1,  268,   -1,
   -1,   -1,   -1,   -1,   -1,  268,  268,   -1,  278,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,  257,
   -1,   -1,   -1,   -1,   -1,  265,   -1,  265,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  310,   -1,  312,  313,  314,   -1,
  316,  317,   -1,   -1,  316,  317,   -1,   -1,  310,   -1,
  312,  313,  314,   -1,  316,  317,  310,  315,  312,  313,
  314,   -1,  316,  317,   -1,   -1,   -1,   -1,  310,   -1,
  312,  313,  314,   -1,  316,  317,  310,   -1,  312,  313,
  314,   -1,  316,  317,  310,   -1,  312,  313,  314,   -1,
  316,  317,  310,   -1,  312,  313,  314,   -1,  316,  317,
  310,   -1,  312,  313,  314,   -1,  316,  317,  310,   -1,
  312,  313,  314,   -1,  316,  317,  310,   -1,  312,  313,
  314,   -1,  316,  317,  310,   -1,  312,  313,  314,   -1,
  316,  317,  310,   -1,  312,  313,  314,   -1,  316,  317,
  310,   -1,  312,  313,  314,   -1,  316,  317,  310,   -1,
  312,  313,  314,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 323
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
"PLUSPLUS_OP","MINUSMINUS_OP","MUL_OP","DIV_OP","MOD_OP","MINUS_OP","PLUS_OP",
"LT_OP","LE_OP","GT_OP","GE_OP","EQUAL_OP","NEQUAL_OP","NOT_OP","AND_OP",
"OR_OP","OROR","ANDAND","EQCOMPARE","ARITHCOMPARE","DOUBLEDOUBLE","UNARY",
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
"stmt_list :",
"stmt_list : stmts",
"stmts : stmt",
"stmts : stmts stmt",
"stmt : simple_stmt",
"stmt : IF_Statement",
"$$2 :",
"IF_Statement : IF '(' Expression ')' $$2 Compound_Statement Selection_Statement_Tail",
"Selection_Statement_Tail :",
"$$3 :",
"Selection_Statement_Tail : ELSE $$3 Compound_Statement",
"$$4 :",
"$$5 :",
"Compound_Statement : '{' $$4 xdecls $$5 stmt_list '}'",
"Expression : Logical_Expression",
"Logical_Expression : add_expr",
"Logical_Expression : Logical_Expression OR_OP add_expr",
"Logical_Expression : Logical_Expression AND_OP add_expr",
"Logical_Expression : NOT_OP Logical_Expression",
"Logical_Expression : Logical_Expression '<' add_expr",
"Logical_Expression : Logical_Expression LE_OP add_expr",
"Logical_Expression : Logical_Expression '>' add_expr",
"Logical_Expression : Logical_Expression GE_OP add_expr",
"Logical_Expression : Logical_Expression EQUAL_OP add_expr",
"Logical_Expression : Logical_Expression NEQUAL_OP add_expr",
"simple_stmt : IDENTIFIER '=' add_expr ';'",
"add_expr : mul_expr",
"add_expr : add_expr '+' mul_expr",
"add_expr : add_expr '-' mul_expr",
"mul_expr : primary_expr",
"mul_expr : mul_expr '*' primary_expr",
"mul_expr : mul_expr '/' primary_expr",
"primary_expr : IDENTIFIER",
"primary_expr : CONSTANT",
"primary_expr : '(' Expression ')'",
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
#line 420 "hw3.y"

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
#line 437 "y.tab.c"

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
#line 104 "hw3.y"
	{
				install_symbol(yystack.l_mark[0].ident);
				cur_scope++;
			}
break;
case 2:
#line 109 "hw3.y"
	{ if (TRACEON) printf("1\n ");
				cur_scope--;
		  }
break;
case 3:
#line 116 "hw3.y"
	{ if (TRACEON) printf("102 ") ; }
break;
case 4:
#line 118 "hw3.y"
	{ if (TRACEON) printf("103 ") ; }
break;
case 5:
#line 123 "hw3.y"
	{ if (TRACEON) printf("104 ") ;}
break;
case 6:
#line 125 "hw3.y"
	{ if (TRACEON) printf("106 ") ;}
break;
case 7:
#line 130 "hw3.y"
	{ 
				if (TRACEON) printf("110 ") ;
			}
break;
case 8:
#line 136 "hw3.y"
	{   
                          install_symbol(yystack.l_mark[-2].ident);
                          int index = look_up_symbol(yystack.l_mark[-2].ident);

                          /* Setting, use set_local_vars will be too late */
                          table[index].offset = LocalOffset++;
                          table[index].mode  = LOCAL_MODE;

                          /* Pop Expression to $r0 */
                          PopReg(0);

                          /* Store it to var */
                          fprintf(f_asm, "    swi $r0, [$sp+%d]\n",table[index].offset*4);
				
			}
break;
case 9:
#line 154 "hw3.y"
	{
							yyval.ident = NULL;
                            /* Move num to $r0 and push to stack */
                            fprintf(f_asm, "    movi $r0, %d\n",yystack.l_mark[0].token);
                            PushReg(0);
				}
break;
case 11:
#line 164 "hw3.y"
	{}
break;
case 12:
#line 169 "hw3.y"
	{ if (TRACEON) printf("29 ") ;  }
break;
case 13:
#line 171 "hw3.y"
	{ if (TRACEON) printf("30 ") ;  }
break;
case 14:
#line 175 "hw3.y"
	{}
break;
case 15:
#line 176 "hw3.y"
	{}
break;
case 16:
#line 180 "hw3.y"
	{
                            /* Pop expression to r0 */
                            PopReg(0);

                            fprintf(f_asm, "    beqz $r0, .L%d\n", LabelNum);
                            /* If true, continue to compound statment */
                        }
break;
case 18:
#line 190 "hw3.y"
	{
                                 /* If false, ignore the compound statement. Branch to End */
                                 fprintf(f_asm, ".L%d:\n", LabelNum);
                                 LabelNum++;
                             }
break;
case 19:
#line 196 "hw3.y"
	{
                                 /* If true, after compound statement. Must ignore else and branch to End */
                                 fprintf(f_asm, "    j .L%d\n", LabelNum+1);

                                 /* If false, ignore the compound statement. Branch to ELSE */
                                 fprintf(f_asm, ".L%d:\n", LabelNum);
                             }
break;
case 20:
#line 204 "hw3.y"
	{
                                 /* End */
                                 fprintf(f_asm, ".L%d:\n", LabelNum+1);
                                 LabelNum += 2;
                             }
break;
case 21:
#line 212 "hw3.y"
	{
                          cur_scope++;
                          /*LocalOffset = 0;*/
                      }
break;
case 22:
#line 217 "hw3.y"
	{
						
                      }
break;
case 23:
#line 221 "hw3.y"
	{
                          cur_scope--;
                      }
break;
case 25:
#line 232 "hw3.y"
	{}
break;
case 26:
#line 234 "hw3.y"
	{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    or $r0, $r0, $r1\n");
                              PushReg(0);
		}
break;
case 27:
#line 241 "hw3.y"
	{
                               PopReg(0);
                               PopReg(1);
                               fprintf(f_asm, "    and $r0, $r0, $r1\n");
                               PushReg(0);
		}
break;
case 28:
#line 248 "hw3.y"
	{
								PopReg(0);
							   fprintf(f_asm, "    addi $r0, $r0, 0\n"); /* ??? */
							   fprintf(f_asm, "    slti $r0, $r0, 1\n");
							   fprintf(f_asm, "    zeb $r0, $r0\n");
							   PushReg(0);
		}
break;
case 29:
#line 256 "hw3.y"
	{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r1, $r0\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
break;
case 30:
#line 264 "hw3.y"
	{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r0, $r1\n"); /* $r1 > $r0 ? */
                              fprintf(f_asm, "    xori $r0, $r0, 1\n"); /* if $r0 == 1, $r0 = 0 */
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
break;
case 31:
#line 273 "hw3.y"
	{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r0, $r1\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
break;
case 32:
#line 281 "hw3.y"
	{
                               PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    slts $r0, $r1, $r0\n"); /* $r1 < $r0 ? */
                              fprintf(f_asm, "    xori $r0, $r0, 1\n"); /* if $r0 == 1, $r0 = 0 */
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
break;
case 33:
#line 290 "hw3.y"
	{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    xor $r0, $r0, $r1\n"); /* If $r0 == $r1 , then result of xor will be 0 --> < 1 */
                              fprintf(f_asm, "    slti $r0, $r0, 1\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
break;
case 34:
#line 299 "hw3.y"
	{
                              PopReg(0);
                              PopReg(1);
                              fprintf(f_asm, "    xor $r0, $r0, $r1\n"); /* If $r0 != $r1 , then result of xor will be > 0 */
                              fprintf(f_asm, "    movi $r1, 0\n");
                              fprintf(f_asm, "    slt $r0, $r1, $r0\n");
                              fprintf(f_asm, "    zeb $r0, $r0\n");
                              PushReg(0);
		}
break;
case 35:
#line 315 "hw3.y"
	{
                         int index = look_up_symbol(yystack.l_mark[-3].ident);

                         /* Pop Expression to $r0 */
                         PopReg(0);

                         /* Store it to var */
                         fprintf(f_asm, "    swi $r0, [$sp+%d]\n",table[index].offset*4);
		}
break;
case 36:
#line 328 "hw3.y"
	{
		
		}
break;
case 37:
#line 332 "hw3.y"
	{
                            PopReg(0);
                            PopReg(1);
                            fprintf(f_asm, "    add $r0, $r1, $r0\n");
                            PushReg(0);
		}
break;
case 38:
#line 339 "hw3.y"
	{
                            PopReg(0);
                            PopReg(1);
                            fprintf(f_asm, "    sub $r0, $r1, $r0\n");
                            PushReg(0);
		}
break;
case 39:
#line 349 "hw3.y"
	{
			
		}
break;
case 40:
#line 353 "hw3.y"
	{
                                  PopReg(0);
                                  PopReg(1);
                                  fprintf(f_asm, "    mul $r0, $r1, $r0\n");
                                  PushReg(0);	
		}
break;
case 41:
#line 360 "hw3.y"
	{
                                  PopReg(2);
                                  PopReg(3);
                                  fprintf(f_asm, "    divsr $r0, $r1, $r3, $r2\n");
                                  PushReg(0);
		}
break;
case 42:
#line 370 "hw3.y"
	{
                                 int index = look_up_symbol(yystack.l_mark[0].ident);

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
break;
case 43:
#line 389 "hw3.y"
	{
                                yyval.ident = NULL;

                                /* Move num to $r0 and push to stack */
                                fprintf(f_asm, "    movi $r0, %d\n",yystack.l_mark[0].token);
                                PushReg(0);
		}
break;
case 44:
#line 397 "hw3.y"
	{
		
		}
break;
case 45:
#line 405 "hw3.y"
	{   int index;
            if (TRACEON) printf("20 ") ;
         }
break;
case 46:
#line 409 "hw3.y"
	{ 
			if (TRACEON) printf("21 ") ;

                }
break;
#line 983 "y.tab.c"
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
