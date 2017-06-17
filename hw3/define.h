/* define.h */

typedef struct {
   char *name;
   unsigned int value;
} KWORD;

KWORD k_tab[]= {	/* keyword table */
   {	"break", 	BREAK	},
   {	"case", 	CASE	},
   {	"char", 	TYPESPEC	},
   {	"const",	TYPEMOD	},
   {    "continue", 	CONTINUE},
   {	"default", 	DEFAULT_TOKEN	},
   {    "do",       	DO      },
   {	"double", 	TYPESPEC	},
   {	"else", 	ELSE	},
   {    "for",      	FOR     },
   {    "if",       	IF      },
   {	"int", 		TYPESPEC	},
   {	"return", 	RETURN	},
   {	"switch", 	SWITCH	},
   {	"void", 	VOIDTYPE	},
   {	"while", 	WHILE	},
   {	"bool", 	TYPESPEC	}
};   