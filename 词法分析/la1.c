#include<stdio.h>
#include<ctype.h>
#define MAXLINE 65536
#define RESERVEDWORD 1
#define IDENTIFIER 2
#define INTEGERCONSTENT 3
#define FLOATCONSTENT 4
#define STRINGCONSTENT 5
#define BOUNDER 6
#define OPERATOR 7

int isOperator(char* code,int i,int* operatorState){


    if(code[i+1] != 0 && code[i] == '<' && code[i+1] == '='){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '>' && code[i+1] == '='){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '|' && code[i+1] == '|'){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '&' && code[i+1] == '&'){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '=' && code[i+1] == '='){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '+' && code[i+1] == '='){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '-' && code[i+1] == '='){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '*' && code[i+1] == '='){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '/' && code[i+1] == '='){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '+' && code[i+1] == '+'){

        *operatorState = 2;
        return 1;
    }
    else if(code[i+1] != 0 && code[i] == '-' && code[i+1] == '-'){

        *operatorState = 2;
        return 1;
    }
    else if(code[i] == '+' || code[i] == '-' || code[i] == '*' || code[i] == '/' || code[i] == '=' || code[i] == '>' || code[i] == '<'){

        *operatorState = 1;
        return 1;
    }
    else{

        return 0;
    }


}

int isBounder(char ch){


    if(ch == ';' || ch == '(' || ch == ')' || ch =='{' || ch == '}'){

        return 1;
    }
    else{

        return 0;
    }
}


char* reservedWordList[10] = {"string","float","int","if","else","for","while","return","break","continue"};
const int RESERVEDWORDLISTNUM = 10;

int checkReserveWord(char* temp){

    int i = 0;
    for(;i < RESERVEDWORDLISTNUM ;++i){

        if(strcmp(reservedWordList[i],temp) == 0){

            return 1;
        }
    }

    return 0;

}
int isEnd(char* code,int i){

    int flag = 0;
    if(isBounder(code[i])){

        return 1;
    }
    else if(isspace(code[i])){

        return 1;
    }
    else if(isOperator(code,i,&flag)){

        return 1;
    }
    else{

        return 0;
    }

}

int nextEnd(char* code,int i){

    int flag = 0;
    for(; code[i] != 0;++i){

        if(isspace(code[i])){

            return i-1;
        }
        else if(isBounder(code[i])){

            return i-1;
        }
        else if(isOperator(code,i,&flag)){

            return i-1;
        }
    }

    return i-1;
}
void printWord(char* str,int type){


    printf("%s : %d \n",str,type);

}

void printError(char* temp,int type){

    printf("Error:[%s] ",temp);
    if(type == -1){

        printf("unknown character");
    }
    else if(type == RESERVEDWORD){

        printf("error reservedword");
    }
    else if(type == IDENTIFIER){

        printf("error identifier");
    }
    else if(type == INTEGERCONSTENT){

        printf("error integer constent");
    }
    else if(type == FLOATCONSTENT){

        printf("error float constent");
    }
    else if(type == STRINGCONSTENT){

        printf("error string constent");
    }
    else if(type == BOUNDER){

        printf("error bounder");
    }
    else if(type == OPERATOR){

        printf("error operator");
    }
    else{

        printf("inner error!");
    }

    printf("\n");
}
void copyWord(char* str1,char* str2,int first ,int last){


    int k = 0;
    int j;
    for(j = first; j <= last; ++j){

        str1[k++] = str2[j];
    }
    str1[k] = 0;

    return;
}
void changeI(int* i){

    *i = *i -1;
}
/**state

    0
    1 标识符
**/
void analyse(char* code){

    int i = 0;
    int state = 0;
    int first;
    int last;

    char temp[MAXLINE];
    int operatorState = 0;
    for(i = 0; code[i] != 0; ++i){

        if(state == 0){

            if(isalpha(code[i])){

                state = 1;
                first = i;

            }
            else if(isdigit(code[i])){


                state = 2;
                first = i;
            }
            else if(code[i] == '\"'){

                state = 7;
                first = i;
                continue;
            }
            else if(isBounder(code[i])){

                state = 8;
            }
            else if(isOperator(code,i,&operatorState)){

                state = 9;
            }
            else if(isspace(code[i])){

                continue;
            }
            else{


                temp[0] = code[i];
                temp[1] = 0;
                printError(temp,-1);
                i = nextEnd(code,i);
                state = 0;

            }


        }

        switch(state){


            case 1:{

                if(isdigit(code[i]) || isalpha(code[i])){


                    state = 1;
                    last = i;

                }
                else if(isEnd(code,i)){

                    copyWord(temp,code,first,last);
                    if(checkReserveWord(temp)){

                        printWord(temp,RESERVEDWORD);

                    }
                    else{

                        printWord(temp,IDENTIFIER);
                    }

                    state = 0;
                    changeI(&i);
                }
                else{

                    copyWord(temp,code,first,i);
                    printError(temp,IDENTIFIER);
                    i = nextEnd(code,i);
                    state = 0;
                }


                break;
            }
            case 2:{

                if(isdigit(code[i])){


                    state = 2;
                    last = i;
                }
                else if(code[i] == '.'){

                    state = 3;

                }
                else if(isEnd(code,i)){


                    copyWord(temp,code,first,last);
                    printWord(temp,INTEGERCONSTENT);
                    state = 0;
                    changeI(&i);
                }
                else{

                    copyWord(temp,code,first,i);
                    printError(temp,INTEGERCONSTENT);
                    i = nextEnd(code,i);
                    state = 0;

                }
                break;
            }
            case 3:{

                if(isdigit(code[i])){

                    state = 4;
                    last = i;

                }
                else{

                    copyWord(temp,code,first,i);
                    printError(temp,FLOATCONSTENT);
                    i = nextEnd(code,i);
                    state = 0;
                }
                break;

            }
            case 4:{

                if(isdigit(code[i])){

                    state = 4;
                    last = i;
               }
               else if(code[i] == '+' || code[i+1] == '-'){

                    state = 5;
                    last = i;
               }
               else if(code[i] =='e' || code[i] == 'E'){

                    state = 6;
                    last = i;

               }
               else if(isEnd(code,i)){

                    copyWord(temp,code,first,last);
                    printWord(temp,FLOATCONSTENT);
                    state = 0;
                    changeI(&i);

                }
               else{

                    copyWord(temp,code,first,i);
                    printError(temp,FLOATCONSTENT);
                    i = nextEnd(code,i);
                    state = 0;
               }

               break;
            }
            case 5:{

                if(code[i] =='e' || code[i] == 'E'){

                    state = 6;
                    last = i;

               }
               else{

                    copyWord(temp,code,first,i);
                    printError(temp,FLOATCONSTENT);
                    i = nextEnd(code,i);
                    state = 0;

               }

                break;
            }
            case 6:{


                if(isdigit(code[i])){

                    state = 6;
                    last = i;
                }
                else if(isEnd(code,i)){

                    copyWord(temp,code,first,last);
                    printWord(temp,FLOATCONSTENT);
                    state = 0;
                    changeI(&i);
                }
                else{

                    copyWord(temp,code,first,i);
                    printError(temp,FLOATCONSTENT);
                    i = nextEnd(code,i);
                    state = 0;
                }
                break;
            }
            case 7:{

                if(code[i] == '\"'){

                    copyWord(temp,code,first,last);
                    printWord(temp,STRINGCONSTENT);
                    state = 0;

                }
                else{

                    state = 7;
                    last = i;
                }
                break;
            }

            case 8:{

                copyWord(temp,code,i,i);
                printWord(temp,BOUNDER);
                state = 0;
                break;
            }
            case 9:{


                copyWord(temp,code,i,i+operatorState-1);
                printWord(temp,OPERATOR);
                state = 0;
                if(operatorState == 2){

                    ++i;
                }
                break;
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

        int k;
        for(k = 0 ; buffer[k]!= 0;++k){

            if(buffer[k] == '\n'){

                buffer[k] = 0;
            }
        }
        analyse(buffer);

    }

    return 0;
}
