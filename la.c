#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 65536

/*
keep source code every line including less word than 65536
*/

/**
1.标识符
2.常量
3.保留字 if else while for int float string
4.运算符 + - * / = += -= *= /= == <= >= < >
5.界符 ; SPACE
**/

char map[7][7] = {"if","else","while","for","int","float","string"};
int lineCounter = 0;

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


    for(;!isFrontier(code[j]);++j){



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
void analyse(char* code){

    int i;
    int j;
    for(i = 0; isStrNotEnd(code[i]); ++i){

        if(isFrontier(code[i])){


            continue;
        }

        if(isalpha(code[i])){

            j = findNextFrontier(code,i);

            char* p = (char*)malloc(j-i + 1);
            int k;
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

                i = j - 1;
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
                    continue;
                }
                else{


                    continue;
                }
            }
        }
        else if(isdigit(code[i])){

            char* p = (char*) malloc(256);
            int counter = 1;
            int num = 256;
            p[0] = code[i];
            int status = 0;
            for(j = i + 1;isStrNotEnd(code[j]); ++j){

                if(isdigit(code[j])){

                    if(num = counter){

                        enlargeArray(p,&num);

                    }
                    p[counter++] = code[j];
                    continue;
                }
                else if(isFrontier(code[j])){

                    break;
                }
                else if(isalpha(code[j])){

                    /**输出错误信息**/

                    p[counter++] = code[j];
                    p[counter] = 0;
                    constentDigitError(p);
                    //找到下一个界符，继续词法分析

                    i = findNextFrontier(code,j) - 1;
                    status = 1;
                    break;

                }

                else if(isOperator(code[j])){

                    break;

                }
            }

            if(status == 0){

                i = j-1;
            }
            else{


            }

            free(p);

        }
        else if(isOperator(code[i])){

            if(!isStrNotEnd(code[i+1])){

                continue;
            }
            if(!isOperator(code[i+1])){


                continue;
            }
            int isSame = isSameOperator(code[i],code[i+1]);

            if(!isSame && (code[i] == '+' || code[i] == '-' || code[i] == '*' || code[i] == '/' || code[i] == '=' || code[i] == '<' || code[i] == '>') && code[i+1] == '='){

                ++i;
                continue;
            }
            if(!isSame){

                /**输出错误信息**/

                operatorError(code[i],code[i+1]);
                //找到下一个界符，继续词法分析
                i = findNextFrontier(code,i+1) -1 ;
                continue;
            }
            if(code[i] == '+' || code[i] == '-' ){

                ++i;
                continue;
            }
            else{

                /**输出错误信息**/
                operatorError(code[i],code[i+1]);
                i = findNextFrontier(code,i+1) - 1;
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

            }
            else{

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

    while(fgets(buffer,MAXLINE,fp) != NULL){

        analyse(buffer);
        ++lineCounter;
    }


    return 0;
}
