

#include<stdio.h>
#include<ctype.h>
#define MAXLINE 65536;




void analyse(char* code){

    int i = 0;
    int state = 0;
    char* temp[MAXLINE];
    int counter = 0;
    for(i = 0; code[i] != 0; ++i){

        switch(state){

            case 0:{

                if(isalpha(code[i])){

                    state = 1;
                    temp[counter++] = code[i];
                }
                else if(code[i] == '+' || code[i] == '-'){

                    state = 3;

                }

                else{

                    error(0);
                }

                break;
            }
            case 1:{

                if(isStrBounder(code[i])){

                    state = 2;
                    break;
                }
                else if(!isalpha(code[i]) && !isdigit(code[i])){


                    state = 0;
                    afterErrorFindNewStart(code,&i);/** **/
                    break;
                }
                temp[counter++] = code[i];
                break;
            }
            case 2:{

                temp[counter] = 0;
                counter = 0;
                judgeReserverOrIdent();
                state = 0;
                break;

            }
            case 3:{

                if(isdigit(code[i])){


                    state = 5;
                }
                else{

                    state = 4;
                }
                break;
            }
            case 4:{

                /** + - hao **/

            }
            case 5:{




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

    }

    return 0;
}
