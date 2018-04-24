#include<stdio.h>
#define MAX 65536
char arr[MAX];
int index = 0;
int debug[5];
int flag = 0;
void print(int i){

    if(i == 0){

        printf("S()");
    }
    else if(i == 1){

        printf("T()");
    }
    else if(i == 2){

        printf("G()");
    }
    else if(i == 3){

        printf("F()");
    }
    else if(i == 4){

        printf("S()");
    }
}
void mprint(){

    if(flag == 0){

        return;
    }
    for(int i = 0; i < 5;++i){

        if(debug[i] == 1){

            print(i);
        }

    }
    printf("\n");
}
void E(){

    debug[0] = 1;

    mprint();
    T();
    G();
    debug[0] = 0;
}

void T(){

    debug[1] = 1;
    mprint();


    F();
    S();

    debug[1] = 0;
}

void G(){


    debug[2] = 1;
    mprint();
    if(arr[index] == '+'){
        ++index;
        T();
        G();

    }
    else if(arr[index] == '-'){
        ++index;
        T();
        G();

    }
    else{
        debug[2] = 0;
        return ;
    }

    debug[2] = 0;

}

void F(){

    debug[3] = 1;

    mprint();
    if(arr[index] == '('){

        ++index;
        E();
        if(arr[index] == ')'){
            ++index;
            debug[3] = 0;
            return;
        }
        else{

            printf("%s:非法的符号串",arr);
            exit(0);
        }

    }
    else if(arr[index] =='i' || arr[index] == 'I'){


        ++index;
        debug[3] = 0;
        return;
    }
    else{


        printf("%s:非法的符号串",arr);
        exit(0);
    }
    debug[3] = 0;
}

void S(){

    debug[4] = 1;
    mprint();


    if(arr[index] == '*'){

        ++index;
        F();
        S();

    }
    else if(arr[index] == '/'){

        ++index;
        F();
        S();
    }
    else{

        debug[4] = 0;
        return;
    }
    debug[4] = 0;
    return ;
}
int main(void){

   // flag = 1;
    if(gets(arr) == NULL){

        printf("没有输入！\n");
    }

    printf("递归下降分析程序，编制人：李文啸，学号:201501060314，班级:计算机15-3\n");
    E();

    printf("%s为合法字符串",arr);
    return 0;
}
