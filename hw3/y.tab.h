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
extern YYSTYPE yylval;
