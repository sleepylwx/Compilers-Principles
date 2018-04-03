#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXLINE 65536

/*
keep source code every line including less word than 65536
*/
#define IDENTIFIER 1
#define CONSTENT 2
#define RESERVEDWORD 3
#define OPERATOR 4
#define BOUND 5
/**
1.标识符 type = 1
2.常量   type = 2 *
3.保留字 if else while for int float string  type = 3
4.运算符 + - * / = += -= *= /= == <= >= < >  type = 4 *()
5.界符 ; SPACE  type = 5
6.区域限定符 {}
**/

/**

if else while for 后面()的完整性判定放语法分析
多个语句的语句块区域限定符{}的完整性判定放语法分析


 **/

struct Word{


    int type;
    char* word;
    int length;

};
struct Error{


    int type;
    char* description;
    int lineNumber;

};

struct String{

    char* str;
    int length;

};
struct Word* wordTable;
int wordTableLimit;
int wordTableCurrent;

char map[7][7] = {"if","else","while","for","int","float","string"};
int lineCounter = 1;

int isOperator(char ch){


    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<'){

        return 1;
    }

    return 0;
}

int isFrontier(char ch){


    if(ch == ' ' || ch == ';'){

        return 1;
    }

    return 0;
}
int isStrNotEnd(char ch){

    if(ch == 0){

        return 0;
    }

    return 1;
}

int isSameOperator(char ch1,char ch2){

    // ch1 and ch2 are ensured to be operator
    if(ch1 == ch2){

        return 1;
    }

    return 0;
}

int findNextFrontier(char* code,int j){


    for(;isStrNotEnd(code[j]) && !isFrontier(code[j]);++j){



    }

    return j;
}

int isString(char ch){


    if(ch == '"'){

        return 1;
    }

    return 0;
}
void enlargeArray(char*p,int* num){


    char* temp = (char*)malloc(2*(*num));
    strcat(temp,p);
    free(p);
    p = temp;
    (*num) *= 2;

}

void enLargeWordTable(struct Word* p,int* num){


    struct Word* temp = (struct Word*)malloc(2*sizeof(struct Word)*(*num));
    int i;
    for(i = 0; i < *num ; ++i ){


        temp[i].type = p[i].type;
        temp[i].word = p[i].word;
        temp[i].length = p[i].length;
    }

    free(p);
    p = temp;

    (*num) *= 2;
}

int isWordTableFull(){


    return wordTableCurrent >= wordTableLimit ? 1 : 0;

}

void prepareWordTable(){


    if(isWordTableFull()){

        enLargeWordTable(wordTable,&wordTableLimit);
    }

}
void variableNameError(char* p){


    printf("Error(Line:%d):'%s' unlegal variable name!\n",lineCounter,p);

}
void constentDigitError(char* p){


    printf("Error(Line:%d):'%s' unlegal constent !\n",lineCounter,p);

}
void operatorError(char ch1,char ch2){

    printf("Error(Line:%d):'%c%c' unlegal operator!\n",ch1,ch2);
}

void stringError(){

    printf("Error(Line:%d): string leak '\"'");
}

int findNextOperator(char* code,int i){

    for(;isStrNotEnd(code[i]) && !isOperator(code[i]);++i){


    }

    return i;

}

int findNextNotOperator(char* code,int i){



    for(;isStrNotEnd(code[i]) && isOperator(code[i]);++i){


    }

    return i;
}

int min(int x,int y){



    return x > y ? y : x;

}

int encodeTypeId(int kind){


    return kind;

}

void addWordTable(int type, char* str){

    int i;
    for(i = 0; str[i] != 0; ++i){


    };

    prepareWordTable();
    wordTable[wordTableCurrent].type = encodeTypeId(type);
    wordTable[wordTableCurrent].word = (char*)malloc(sizeof(char)*i);
    strcat(wordTable[wordTableCurrent].word,str);
    wordTable[wordTableCurrent].length = i;
    ++wordTableCurrent;

}
int isRealFrontier(char ch){


    if(ch == ';'){

        return 1;
    }

    return 0;
}


void analyse(char* code){

    int i;
    int j;
    for(i = 0; isStrNotEnd(code[i]); ++i){

        if(isFrontier(code[i])){

            if(isRealFrontier(code[i])){

                char temp[2];
                temp[0] = ';';
                temp[1] = 0;
                addWordTable(BOUND,temp);
            }
            continue;
        }

        if(isalpha(code[i])){

            j = findNextFrontier(code,i);
            int k = findNextOperator(code,i);
            j = min(k,j);
            char p[j-i+1];
            //char* p = (char*)malloc(j-i + 1);

            for(k = 0; k < j - i; ++k){

                p[k] = code[i+k];
            }
            p[k] = 0;

            int status = 0;
            for(k = 0; k < 7; ++k){

                if(strcmp(p,map[k])== 0){

                    status = 1;
                    break;
                }
            }

            if(status == 1){
                /** 是保留字 **/
                i = j - 1;
                addWordTable(RESERVEDWORD,p);

                //free(p);
                continue;
            }
            else{

                int status = 0;
                for(k = i; k < j; ++k){

                    if(!(isalpha(code[k])||isdigit(code[k]))){


                        status = 1;
                        break;
                    }
                }

                if(status ==  1){


                    /**输出错误信息**/
                    variableNameError(p);
                    i = j - 1;
                    //free(p);
                    continue;
                }
                else{

                    //free(p);
                    addWordTable(IDENTIFIER,p);

                    continue;
                }
            }
        }
        else if(isdigit(code[i])){

            j = findNextFrontier(code,i);
            int k = findNextOperator(code,i);
            j = min(k,j);
            int status = 0;

            int eNumber = 0;
            int dotNumber = 0;
            for(k = i;k < j; ++k){

                k = i+-k;
                if(!isdigit(code[k])){

                    if(eNumber == 0 && code[k] == 'e'){

                        ++eNumber;
                    }
                    if(eNumber == 0 && dotNumber == 0 && code[k] == '.'){

                        ++dotNumber;
                    }
                    status = 1;
                    break;
                }
            }

            char temp[j - i + 1];
            for(k = 0; k < j - i; ++k){


                temp[k] = code[i+k];
            }
            temp[k] = 0;
            if(status == 1){

                /**输出错误信息**/

                constentDigitError(temp);


            }
            else{

                addWordTable(CONSTENT,temp);

            }
            i = j - 1;



        }
        else if(isOperator(code[i])){


            if(!isStrNotEnd(code[i+1])){


                char temp[2];
                temp[0] = code[i];
                temp[1] = 0;
                addWordTable(OPERATOR,temp);
                continue;
            }
            if(!isOperator(code[i+1])){

                char temp[2];
                temp[0] = code[i];
                temp[1] = 0;
                addWordTable(OPERATOR,temp);
                continue;
            }
            int isSame = isSameOperator(code[i],code[i+1]);

            if(!isSame && (code[i] == '+' || code[i] == '-' || code[i] == '*' || code[i] == '/' || code[i] == '=' || code[i] == '<' || code[i] == '>') && code[i+1] == '='){

                char temp[3];
                temp[0] = code[i];
                temp[1] = code[i+1];
                temp[2] = 0;
                addWordTable(OPERATOR,temp);
                ++i;

                continue;
            }
            if(!isSame){

                /**输出错误信息**/

                operatorError(code[i],code[i+1]);
                //找到下一个界符，继续词法分析
                i = findNextNotOperator(code,i+1) - 1;
                //i = findNextFrontier(code,i+1) -1 ;
                continue;
            }
            if(code[i] == '+' || code[i] == '-' ){

                char temp[3];
                temp[0] = code[i];
                temp[1] = code[i+1];
                temp[2] = 0;
                addWordTable(OPERATOR,temp);
                ++i;

                continue;
            }
            else{

                /**输出错误信息**/
                operatorError(code[i],code[i+1]);
                i = findNextNotOperator(code,i+1) - 1;
                //i = findNextFrontier(code,i+1) - 1;
                continue;
            }
        }
        else if(isString(code[i])){

            int status = 0;

            for(j = i+1; isStrNotEnd(code[j]);++j){

                if(code[j] == '"' && code[j-1] != '\\'){

                    status = 1;
                    break;
                }

            }
            if(status == 0){

                /**输出错误信息**/
                stringError();
                break;
            }
            else{

                char temp[j-i];
                int k;
                for(k = 0 ; k < j - i; ++k){

                    temp[k] = code[i+k+1];
                }
                temp[k] = 0;
                addWordTable(CONSTENT,temp);
                i = j;
                continue;
            }
        }




    }


}


int main(int argc,char** argv){

    if(argc < 2){

        printf("input source file name!\n");
        return 0;
    }

    FILE* fp = fopen(argv[1],"r");

    if(fp == NULL){

        printf("source file is nonexistent!\n");
        return 0;
    }

    char buffer[MAXLINE];

    int k;
    wordTable = (struct Word*)malloc(sizeof(struct Word)*20);
    wordTableCurrent = 0;
    wordTableLimit = 20;
    while(fgets(buffer,MAXLINE,fp) != NULL){


        for(k = 0 ; buffer[k]!= 0;++k){

            if(buffer[k] == '\n'){

                buffer[k] = 0;
            }
        }
        analyse(buffer);
        ++lineCounter;
    }
    putchar('\n');

    for(k = 0 ; k < wordTableCurrent ; ++k) {


        printf("[%d] : \"%s\"\n",wordTable[k].type,wordTable[k].word);
    }


    for(k = 0 ; k < wordTableCurrent ; ++k){


        free(wordTable[k].word);
    }
    free(wordTable);
    return 0;
}
