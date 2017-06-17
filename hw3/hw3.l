%{
#include <stdio.h>
#include "y.tab.h"
#include "define.h"
#include "SymbolTable.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char *copys();

void insert_printline(char* yytext, int length);
void print_line();

//  indicate line now
int	lineCount = 1;
int I = 0;

char line_array[3000];

int line_start = 0;
int line_end = 0;
char* yytext_string;

extern FILE *f_asm;	

// 0 off 1 on
//int source_condition = 1;
//int token_condition = 1;
int source_condition = 1;
int token_condition = 0;


%}


identifier	[A-Za-z][A-Za-z|0-9|_]*
integer		([1-9][0-9]*|0)
double		([1-9][0-9]*|0)\.[0-9]+
sci2			{double}(e|E)(-)?(\+)?{integer}
sci				{integer}(e|E)(-)?(\+)?{integer}


key			void|for|printf|bool|char|null|while|do|if|else|switch|return|break|true|continue|const|false|struct|case|default|fclose|clearerr|feof|ferror|fflush|fgetpos|fopen|fread|freopen|fseek|fsetpos|ftell|fwrite|remove|rename|rewind|setbuf|setvbuf|tmpfile|tmpnam|fprintf|sprintf|vfprintf|vprintf|vsprintf|fscanf|scanf|sscanf|fgets|fgetc|fputc|getc|getchar|gets|putc|putchar|puts|ungetc|perror
operation		[(\<\=) ">=" (\=\=) \= \< \> (\+\+) \+ (\-\-) \- \* \/   (!=) (&&) (||) \!]
punc			[\[ \] \{ \} \( \) \; \: \, \.]
strange			[\\][\"]

%x			STRING
%x			COMMENT_A
%x 			COMMENT_B
%x  		DIGITALWRITE
%x  		DELAY

%%


"#pragma source on"	{source_condition = 1; insert_printline(yytext, strlen(yytext));}
"#pragma source off"	{source_condition = 0;}
"#pragma token on" {token_condition = 1; insert_printline(yytext, strlen(yytext));}
"#pragma token off" {token_condition = 0; insert_printline(yytext, strlen(yytext));}

"#"[" "|A-Za-z|0-9|_]+				  {fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext);exit(1);}





"digitalWrite(" {
        /* Special function from Andes */
        BEGIN(DIGITALWRITE);
    }

<DIGITALWRITE>"LOW" {
        fprintf(f_asm, "    movi $r1, 0\n");
    }

<DIGITALWRITE>"HIGH" {
        fprintf(f_asm, "    movi $r1, 1\n");

    }

<DIGITALWRITE>{identifier} {
        int index = look_up_symbol(yytext);

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
    }

<DIGITALWRITE>{integer} {
        int num = atoi(yytext);
        fprintf(f_asm, "    movi $r0, %d\n",num);
    }
<DIGITALWRITE>";" {
        fprintf(f_asm, "    bal digitalWrite\n");
        BEGIN(INITIAL);
    }

"delay(" {
        /* Special function from Andes */
        BEGIN(DELAY);
    }
	
<DELAY>{integer} {
        int num = atoi(yytext);
        fprintf(f_asm, "    movi $r0, %d\n",num);
    }
	
<DELAY>{identifier} {
        int index = look_up_symbol(yytext);

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
    }
<DELAY>";" {
        fprintf(f_asm, "    bal delay\n");
        BEGIN(INITIAL);
    }
	
	
	
	

"+"			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('+');
			}
			
"-"			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('-');
			}
			
"="			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('=');
			}
			
"*"			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('*');
			}
			
"/"			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('/');
			}
			
"%"			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('%');
			}
			


";"		{
				if (token_condition == 1)
					fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return(';');
			}

"("			{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return('(');                  }
						  
")"			{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(')');                  }
						  
"{"			{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return('{');                  }
						  
"}" 		{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));;
                          return('}');                  }
						  
"["			{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return('[');                  }
						  
"]"			{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(']');                  }
				
","			{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(',');                  }
						  
":"			{ if (token_condition == 1)
				fprintf(stdout, "#punc:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(':');                  }

						  
">"			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('>');  
			}					

						 
"<"			{
				if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
				return('<');  
			}	


">="			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(GE_OP);         }
						
"<="			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(LE_OP);         }
						  
						  
"=="			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(EQUAL_OP);         }
						  
"!="			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(NEQUAL_OP);         }
						  
"&&"			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(AND_OP);         }
						  
"||"			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(OR_OP);         }
			
"++"			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(PLUSPLUS_OP);         }

"--"			{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(MINUSMINUS_OP);         }
						  
"!"				{ if (token_condition == 1)
					fprintf(stdout, "#op:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(NOT_OP);         }

true			{ if (token_condition == 1)
					fprintf(stdout, "#key:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(TRUEFALSE);         }		
						  
false			{ if (token_condition == 1)
					fprintf(stdout, "#key:%s\n", yytext);
				insert_printline(yytext, strlen(yytext));
                          return(TRUEFALSE);         }								  
						  
						  

["]			{
				insert_printline(yytext, strlen(yytext)); 
				//printf("start string!\n");
				BEGIN STRING;
			}		



	
<STRING>[{punc}|A-Za-z|0-9|_|" "|\%|{operatoin}|\[|\]|\=|{strange}]*{strange} {
			fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext); exit(1);
			}
			
<STRING>\n  {
			fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext); exit(1);
}

<STRING>[{punc}|A-Za-z|0-9|_|" "|\\|\%|{operatoin}|\[|\]|\=]*[\"] {
			
			yytext_string = (char *)malloc(3000 * sizeof(char));
		
			strncpy(yytext_string , yytext, strlen(yytext) - 1);
			if (token_condition == 1)
				fprintf(stdout, "#string:%s\n", yytext_string);
			insert_printline(yytext, strlen(yytext)); 
			
			//printf("strlen(yytext) - 1 = %d\n", strlen(yytext) - 1);
			//printf("end string!\n");
			
			BEGIN 0;
			yylval.token= atoi(yytext);
			return String;
			
			}
			


"//"		{
				insert_printline(yytext, strlen(yytext));
				BEGIN COMMENT_A;
			}
<COMMENT_A>[A-Za-z|0-9|_|" "|\\|\%|{operatoin}|{punc}|\*]* {
			insert_printline(yytext, strlen(yytext)); 
			}

<COMMENT_A>\n {
			print_line();
			BEGIN 0;
			}
			
\/\*		{
				insert_printline(yytext, strlen(yytext));
			//printf("Start comment B\n");		
			BEGIN COMMENT_B;
			}
				
<COMMENT_B>[" "]*\*\/ {
			insert_printline(yytext, strlen(yytext)); 
			//printf("End comment B\n");
			BEGIN 0;
			}
<COMMENT_B>\* {
			insert_printline(yytext, strlen(yytext));
			BEGIN COMMENT_B;
	      }	
<COMMENT_B>[A-Za-z|0-9|_|" "|\\|\%|{operatoin}|{punc}|\=]* {
			//printf("start comment B\n");	
			insert_printline(yytext, strlen(yytext)); 
				BEGIN COMMENT_B;
			}
			
<COMMENT_B>\n {
			print_line();
			
				BEGIN COMMENT_B;
			}
			
			
			
			
'[A-Za-z]' 	{
			if (token_condition == 1)
				fprintf(stdout, "#char:%s\n", yytext);
			insert_printline(yytext, strlen(yytext));
			//yylval.charv = atoi(yytext);
			//return CHAR;
				return CONSTANT;
			}
			
'\\n' 	{
			if (token_condition == 1)
				fprintf(stdout, "#char:%s\n", yytext);
			insert_printline(yytext, strlen(yytext));				
			}

'\\t' 	{
			if (token_condition == 1)
				fprintf(stdout, "#char:%s\n", yytext);
			insert_printline(yytext, strlen(yytext));				
			}		
	
			

			
" "+		{insert_printline(yytext, strlen(yytext));}
[\t]+		{insert_printline(yytext, strlen(yytext));}
\n			{print_line();}
int 		{	if (token_condition == 1)
					printf("#key:int\n"); 
				insert_printline(yytext, strlen(yytext));
				int value = id_or_keyword(yytext);
				return(value);
			}
double 		{
				if (token_condition == 1)
					printf("#key:double\n"); 
				insert_printline(yytext, strlen(yytext));
				int value = id_or_keyword(yytext);
				return(value);
			}

{sci2}			{
	if (token_condition == 1)
		fprintf(stdout, "#sci:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
	yylval.token= atoi(yytext);
	return CONSTANT;
}	
			
{sci}			{
	if (token_condition == 1)
		fprintf(stdout, "#sci:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
	yylval.token= atoi(yytext);
	return CONSTANT;
}	

	
		
{integer}		{
	if (token_condition == 1)
		fprintf(stdout, "#integer:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
	
	yylval.token= atoi(yytext);
	return CONSTANT;
	}

{double}		{
	if (token_condition == 1)
		fprintf(stdout, "#double:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
	yylval.token= atoi(yytext);
	return CONSTANT;
	}


{key}	{
	if (token_condition == 1)
		fprintf(stdout, "#key:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
	
	//hw2
	int value = id_or_keyword(yytext);
	return(value);
	
}


{identifier}	{
	if (token_condition == 1)
		fprintf(stdout, "#id:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
	int value;
	value = IDENTIFIER;	
    yylval.ident= copys(yytext);
	return(value);
}

{punc}	{
	if (token_condition == 1)
		fprintf(stdout, "#punc:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
}



{operation} {
	if (token_condition == 1)
		fprintf(stdout, "#op:%s\n", yytext);
	insert_printline(yytext, strlen(yytext));
}


[0-9][A-Za-z|0-9|_]*  {fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext);exit(1);}



[.]+ {
    fprintf(stderr, "Error at line %d: %s\n", lineCount, yytext);
    exit(1);
}


%%

int id_or_keyword(char* text)
{
 int i;
 for (i=0; i<(sizeof(k_tab)/sizeof(KWORD)); i++) {
    if (!strcmp(text, k_tab[i].name))
       return k_tab[i].value;
 }
}





int yywrap() {
	return 1; 
}

void insert_printline(char* yytext, int length){
	int i;
	int j = 0;
	for (i = line_end; i < line_end + length; i++){
		line_array[i] = yytext[j];
		j++;
	}
	line_end += length;	
}

void print_line(){
	int i;
	
	if (source_condition == 1){
	
		printf("%d:", lineCount);
		
		for (i = line_start; i < line_end; i++){
			printf("%c", line_array[i]);
		}
		printf("\n");
	}
	lineCount++;
	line_start = line_end;
	
}

char   *
copyn(n, s)
	register int n;
	register char *s;
{
	register char *p, *q;
	//char   *calloc();

	p = q = calloc(1,n);
	while (--n >= 0)
		*q++ = *s++;
	return (p);
}

char   *
copys(s)
	char   *s;
{
	return (copyn(strlen(s) + 1, s));
}

