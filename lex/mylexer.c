/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 1 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.c
* C source file generated from mylexer.l.
* 
* Date: 04/17/18
* Time: 17:50:10
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mylexer.l"

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


#line 59 "mylexer.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 34 ".\\mylexer.l"
printf("%s:%d\n",filter(yytext),RESERVEDWORD);
#line 180 "mylexer.c"
		}
		break;
	case 2:
		{
#line 35 ".\\mylexer.l"
printf("%s:%d\n",filter(yytext),IDENT);
#line 187 "mylexer.c"
		}
		break;
	case 3:
		{
#line 36 ".\\mylexer.l"
printf("%s:%d\n",filter(yytext),INTEGERCONSTENT);
#line 194 "mylexer.c"
		}
		break;
	case 4:
		{
#line 37 ".\\mylexer.l"
printf("%s:%d\n",filter(yytext),STRINGCONSTENT);
#line 201 "mylexer.c"
		}
		break;
	case 5:
		{
#line 38 ".\\mylexer.l"
printf("%s:%d\n",filter(yytext),OPERATOR);
#line 208 "mylexer.c"
		}
		break;
	case 6:
		{
#line 39 ".\\mylexer.l"
printf("%s:%d\n",filter(yytext),BOUND);
#line 215 "mylexer.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 162;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 17, 10 },
	{ 19, 11 },
	{ 15, 4 },
	{ 18, 10 },
	{ 0, 14 },
	{ 21, 12 },
	{ 22, 13 },
	{ 4, 1 },
	{ 5, 1 },
	{ 20, 11 },
	{ 5, 1 },
	{ 16, 9 },
	{ 4, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 6, 1 },
	{ 23, 16 },
	{ 7, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 4, 1 },
	{ 14, 14 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 6, 6 },
	{ 24, 17 },
	{ 19, 18 },
	{ 8, 19 },
	{ 19, 20 },
	{ 25, 21 },
	{ 26, 22 },
	{ 19, 23 },
	{ 20, 24 },
	{ 27, 25 },
	{ 23, 26 },
	{ 28, 27 },
	{ 15, 5 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 9, 1 },
	{ 10, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 11, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 12, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 13, 1 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 19, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 },
	{ 8, 28 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 25, -33, 0 },
	{ 1, 0, 0 },
	{ 14, 0, 0 },
	{ 0, -57, 5 },
	{ 6, -9, 5 },
	{ 0, -17, 3 },
	{ 0, 0, 6 },
	{ 19, 0, 2 },
	{ 26, -95, 2 },
	{ 26, -106, 2 },
	{ 27, -99, 2 },
	{ 20, -109, 2 },
	{ 19, -96, 2 },
	{ -3, -4, 4 },
	{ 0, 0, 5 },
	{ 19, -90, 2 },
	{ 19, -70, 2 },
	{ 21, -72, 2 },
	{ 28, -60, 1 },
	{ 19, -72, 2 },
	{ 19, -69, 2 },
	{ 25, -59, 2 },
	{ 19, -54, 2 },
	{ 19, -49, 2 },
	{ 19, -56, 2 },
	{ 19, -58, 2 },
	{ 19, -59, 2 },
	{ 0, 39, 2 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 40 ".\\mylexer.l"

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


