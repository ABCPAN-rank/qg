//
// Created by ABCPAN on 2021/4/3.
//
#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int flag = 0;
    char ch;
    int sign = 0;
    int len = 0;
    printf("你想创建的栈最大size为:");
    while (scanf("%d", &len) == 0) {
        printf("输入格式错误,请重输入\n");
        while (getchar() != '\n');      /* clear buffer area */
    }
    SqStack *s;
    menu();
    while (1) {
        ch = getchar();
        int push_value, pop_value, top_value, lenth;
//        system("clear");
        switch (ch) {
            case 'q':
                flag = 1;
                system("clear");
                printf("退出成功\n");
                break;
            case 'i':
                s = (SqStack *) malloc(sizeof(struct SqStack));
                sign = 1;
                system("clear");
                if (initStack(s, len) == ERROR)
                    flag = 1;
                menu();
                break;
            case 'a':
                system("clear");
                printf("输入想要压入栈的值:");
                scanf("%d", &push_value);
                pushStack(s, push_value);
                menu();
                break;
            case 'e':
                system("clear");
                isEmptyStack(s);
                menu();
                break;
            case 'c':
                system("clear");
                clearStack(s);
                menu();
                break;
            case 'd':
                system("clear");
                if (popStack(s, &pop_value) == ERROR) {
                    menu();
                    break;
                }
                printf("弹出的元素值为%d", pop_value);
                menu();
                break;
            case 't':
                system("clear");
                if (getTopStack(s, &top_value) == ERROR) {
                    menu();
                    break;
                }
                printf("顶部的元素值为%d", top_value);
                menu();
                break;
            case 'l':
                system("clear");
                stackLength(s, &lenth);
                printf("栈的长度为%d", lenth);
                menu();
                break;
        }
        if (flag == 1)
            break;
    }
    if (sign == 1)
        destroyStack(s);
    return 0;

}