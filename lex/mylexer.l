%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018Äê4ÔÂ10ÈÕ
****************************************************************************/
#include <stdio.h>
#include "myparser.h"
int IDENT = 1;
int INTEGERCONSTENT = 2;
int STRINGCONSTENT = 3;
int RESERVEDWORD = 4;
int OPERATOR = 5;
int BOUND = 6;

%}
IDENT [a-zA-Z][a-zA-Z0-9]*
INTEGER_CONSTENT [+-][0-9]+|[0-9]+
STRING_CONSTENT ["].*["]
RESERVEDWORD if|else|while|for|int|float|string
OPERATOR +|-|*|/|=|+=|-=|*=|/=|==|<=|>=|<|>
BOUND ;

/////////////////////////////////////////////////////////////////////////////
// declarations section

// place any declarations here

%%

{IDENT} {printf("%s:%d\n",yytext,IDENT);}
{INTEGER_CONSTENT} {printf("%s:%d\n",yytext,INTEGER_CONSTENT);}
{STRING_CONSTENT} {printf("%s:%d\n",yytext,STRING_CONSTENT);}
{RESERVEDWORD} {printf("%s:%d\n",yytext,RESERVEDWORD);}
{BOUND} {printf("%s:%d\n",yytext,BOUND);}
%%
#pragma comment(lib,"yl.lib")
int main(void)
 {
 yyin=stdin;
 yylex(); /* start the
 analysis*/
 printf(" No of words:
 %d\n", wordCount);
 return yylex();
 }
 
int yywrap(){
 return 1;
}


