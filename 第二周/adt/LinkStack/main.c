#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int flag=0;
    char ch;
    int sign=0;
    LinkStack *s;
    menu();
    while (1){
        ch=getchar();
        int push_value,pop_value,top_value,lenth;
        switch (ch) {
            case 'q':
                flag = 1;
                system("clear");
                printf("退出成功\n");
                break;
            case 'i':
                s=(LinkStack *)malloc(sizeof(struct LinkStack));
                sign=1;
                system("clear");
                initLStack(s);
                menu();
                break;
            case 'a':
                system("clear");
                printf("输入想要压入栈的值:");
                scanf("%d",&push_value);
                pushLStack(s,push_value);
                menu();
                break;
            case 'e':
                system("clear");
                isEmptyLStack(s);
                menu();
                break;
            case 'c':
                system("clear");
                clearLStack(s);
                menu();
                break;
            case 'd':
                system("clear");
                if(popLStack(s,&pop_value)==ERROR)
                {   menu();
                    break;
                }
                printf("弹出的元素值为%d\n",pop_value);
                menu();
                break;
            case 't':
                system("clear");
                if(getTopLStack(s,&top_value)==ERROR)
                {   menu();
                    break;
                }
                printf("顶部的元素值为%d\n",top_value);
                menu();
                break;
            case 'l':
                system("clear");
                LStackLength(s,&lenth);
                printf("栈的长度为%d\n",lenth);
                menu();
                break;
        }
        if (flag == 1)
            break;
    }
    if (sign == 1)
        destroyLStack(&s);
    return 0;

}