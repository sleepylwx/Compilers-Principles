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
* Date: 04/10/18
* Time: 20:47:18
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
int IDENT = 1;
int INTEGERCONSTENT = 2;
int STRINGCONSTENT = 3;
int RESERVEDWORD = 4;
int OPERATOR = 5;
int BOUND = 6;


#line 58 "mylexer.c"
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
#line 32 ".\\mylexer.l"
printf("%s:%d\n",yytext,IDENT);
#line 179 "mylexer.c"
		}
		break;
	case 2:
		{
#line 33 ".\\mylexer.l"
printf("%s:%d\n",yytext,INTEGER_CONSTENT);
#line 186 "mylexer.c"
		}
		break;
	case 3:
		{
#line 34 ".\\mylexer.l"
printf("%s:%d\n",yytext,STRING_CONSTENT);
#line 193 "mylexer.c"
		}
		break;
	case 4:
		{
#line 35 ".\\mylexer.l"
printf("%s:%d\n",yytext,RESERVEDWORD);
#line 200 "mylexer.c"
		}
		break;
	case 5:
		{
#line 36 ".\\mylexer.l"
printf("%s:%d\n",yytext,BOUND);
#line 207 "mylexer.c"
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
	{ 15, 9 },
	{ 0, 13 },
	{ 18, 11 },
	{ 16, 9 },
	{ 19, 12 },
	{ 14, 8 },
	{ 20, 14 },
	{ 21, 15 },
	{ 4, 1 },
	{ 22, 18 },
	{ 4, 1 },
	{ 23, 19 },
	{ 17, 21 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 5, 1 },
	{ 24, 22 },
	{ 6, 1 },
	{ 13, 13 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 5, 5 },
	{ 20, 23 },
	{ 25, 24 },
	{ 17, 10 },
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
	{ 8, 1 },
	{ 9, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 10, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 11, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 12, 1 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 },
	{ 7, 25 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 25, -33, 0 },
	{ 1, 0, 0 },
	{ 13, 0, 0 },
	{ 5, 0, 0 },
	{ 0, -20, 2 },
	{ 0, 0, 5 },
	{ 25, 0, 1 },
	{ 25, -101, 1 },
	{ 25, -106, 1 },
	{ 25, -70, 1 },
	{ 25, -112, 1 },
	{ 25, -98, 1 },
	{ -3, -7, 3 },
	{ 25, -107, 1 },
	{ 25, -102, 1 },
	{ 25, 0, 1 },
	{ 25, 0, 1 },
	{ 25, -103, 1 },
	{ 25, -92, 1 },
	{ 25, 0, 1 },
	{ 25, -83, 1 },
	{ 25, -80, 1 },
	{ 25, -70, 1 },
	{ 25, -71, 1 },
	{ 0, 39, 1 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0
};

#line 37 ".\\mylexer.l"

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



