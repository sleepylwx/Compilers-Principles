#include<stdio.h>
#define MAX 65536
char* arr[5][8];
char buffer[MAX];
int stack[MAX];
int index;
int top = 0;
char cur[MAX];
int map(char ch){

    int res;
    if(ch == 'i' || ch == 'I'){

        res = 0;
    }
    else if(ch == '+'){

        res = 1;
    }
    else if(ch == '-'){

        res = 2;
    }
    else if(ch == '*'){

        res = 3;
    }
    else if(ch == '/'){

        res = 4;
    }
    else if(ch == '('){

        res = 5;
    }
    else if(ch == ')'){

        res = 6;
    }
    else if(ch == '#'){

        res = 7;
    }
    else{

        res = -1;
    }

    return res;
}
char demap(int num){

    if(num == '0'){

        return 'E';
    }
    else if(num == '1'){

        return 'T';
    }
    else if(num == '2'){

        return 'G';
    }
    else if(num == '3'){

        return 'F';
    }
    else if(num == '4'){

        return 'S';
    }
    else if(num == 'i'){

        return 'i';
    }
    else if(num == 'I'){

        return 'I';
    }
    else if(num == '('){

        return '(';
    }
    else if(num == ')'){

        return ')';
    }
    else if(num == '+'){

        return '+';
    }
    else if(num == '-'){

        return '-';
    }
    else if(num == ' '){

        return '^';
    }
    else if(num == '#'){

        return '#';
    }

}
void makeTable(void){

    int i;
    int j;
    arr[0][0] = "21";

    for(j = 0; j < 2; ++j){

        for(i = 1; i < 5; ++i){

            arr[j][i] = "q";
        }
    }

    arr[0][5] = "21";
    arr[0][6] = "q";
    arr[0][7] = "q";
    arr[1][0] = "43";
    arr[1][5] = "43";
    arr[1][6] = "q";
    arr[1][7] = "q";

    arr[2][0] = "q";
    arr[2][1] = "21+";
    arr[2][2] = "21-";
    for(i = 3; i < 6; ++i){

        arr[2][i] = "q";
    }
    arr[2][6] = " ";
    arr[2][7] = " ";

    arr[3][0] = "i";
    for(i = 1; i < 5; ++i){

        arr[3][i] = "q";
    }
    arr[3][5] = ")0(";
    arr[3][6] = "q";
    arr[3][7] = "q";
    arr[4][0] = "q";
    arr[4][1] = " ";
    arr[4][2] = " ";
    arr[4][3] = "43*";
    arr[4][4] = "43/";
    arr[4][5] = "q";
    arr[4][6] = " ";
    arr[4][7] = " ";

}
void print(int num,int type){


    printf("%5d",num);
    int i = 0;
    char temp[MAX];
    for(;i + 1< top; ++i){

        temp[i] = demap(stack[i+1]);
    }
    temp[i] = 0;

    printf("%25s",temp);

    char temp1[MAX];
    int j = 0;
    for(i = index ; buffer[i] !=0; ++i){

        temp1[j++] = buffer[i];
    }

    temp1[j] = 0;

    printf("%25s",temp1);

    if(type == 0){

        printf("\n\n");
    }
    else{

        printf("%25s\n\n",cur);
    }


}
void analyse(){


    char ch;
    ch = buffer[index];

    stack[top++] = '#';
    stack[top++] = '0';
    int flag = 0;
    print(1,1);
    int loopNum = 1;
    while(top > 0){

        ++loopNum;

        if(stack[top-1] == ch){

            --top;
            ch = buffer[++index];
            if(top != 0){

                print(loopNum,0);
            }

            continue;
        }

        char topCh = demap(stack[top-1]);
        char* temp = arr[stack[top-1]-'0'][map(ch)];

        --top;
        if(temp[0]== 'q'){


            flag = 1;
            break;
        }
        //
        cur[0] = topCh;
        cur[1] = '-';
        cur[2] = '>';

        int i;
        int j = 3;
        for(i = 0; temp[i] != 0 ;++i){


        }
        for(i = i -1 ; i > -1 ; --i){

            cur[j++] = demap(temp[i]);
        }
        cur[j] = 0;

        //
        if(temp[0] == ' '){

            print(loopNum,1);
            continue;

        }

        for(i = 0 ;temp[i] != 0;++i){

            stack[top++] = temp[i];

        }

        print(loopNum,1);


    }

    if(flag == 1){

        printf("Error:非法符号串\n");
    }


}
int main(void){

    makeTable();
    gets(buffer);

    stack[0] = '#';
    index = 0;

    printf("%5s%25s%25s%25s\n\n","步骤","分析栈","剩余输入串","所用产生式");

    analyse();
    return 0;
}
