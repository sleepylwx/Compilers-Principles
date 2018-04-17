%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018Äê4ÔÂ10ÈÕ
****************************************************************************/
#include <stdio.h>
#include "myparser.h"
char* filter(char* str);
int IDENT = 1;
int INTEGERCONSTENT = 2;
int STRINGCONSTENT = 3;
int RESERVEDWORD = 4;
int OPERATOR = 5;
int BOUND = 6;

%}

RESERVEDWORD if|else|while|for|int|float|string
IDENT [a-zA-Z][a-zA-Z0-9]*
INTEGER_CONSTENT [+-][0-9]+|[0-9]+
STRING_CONSTENT ["].*["]
OPERATOR [+]|[-]|[*]|[/]|[=]|[+][=]|[-][=]|[*][=]|[/][=]|[=][=]|[<][=]|[>][=]|[<]|[>]

BOUND ;

/////////////////////////////////////////////////////////////////////////////
// declarations section

// place any declarations here

%%
{RESERVEDWORD} {printf("%s:%d\n",filter(yytext),RESERVEDWORD);}
{IDENT} {printf("%s:%d\n",filter(yytext),IDENT);}
{INTEGER_CONSTENT} {printf("%s:%d\n",filter(yytext),INTEGERCONSTENT);}
{STRING_CONSTENT} {printf("%s:%d\n",filter(yytext),STRINGCONSTENT);}
{OPERATOR} {printf("%s:%d\n",filter(yytext),OPERATOR);}
{BOUND} {printf("%s:%d\n",filter(yytext),BOUND);}
%%
int main(void)
{
	int n = yylex();
	return n;
}

int yywrap(void)
{
	
	return 1;
}

char* filter(char* str){


	int i = 0;
	for(i = 0; str[i] != 0; ++i){
	
		if(str[i] == ' '){
		
			int j = i;
			for(;str[j+1] != 0 ; ++j){
			
				str[j] = str[j+1];
				
				
			}
			
			str[j] = 0;
		}
		
	}
	
	return str;
}

