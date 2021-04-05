//
// Created by ABCPAN on 2021/4/5.
//
#include <stdio.h>
#include "SqStack.h"
#include "tool.h"
#include <stdlib.h>

int main() {
    int fl = 0;
    while (1) {
        char str[MAXSIZE];
        printf("输入你要计算的表达式\n");
        scanf("%s", str);
        printf("按q退出\n");
        if (str[0] == 'q') {
            break;
        }
        int i = 0;
        int value = 0;
        int flag = 0;
        int oope;
        SqStack *snum, *sope;
        snum = (SqStack *) malloc(sizeof(SqStack));
        sope = (SqStack *) malloc(sizeof(SqStack));
        initStack(snum, MAXSIZE);
        initStack(sope, MAXSIZE);
        while (str[i] != '\0') {
            if (str[i] >= '0' && str[i] <= '9')  //  处理数字
            {
                value = value * 10 + str[i] - '0'; // 由于是一个一个的读取数，所以要将操作数还原
                flag = 1;
            } else // 对符号操作
            {
                if (flag == 1) {
                    pushStack(snum, value); // 遇到一个空格/符号表示这些数字为一个操作数，压入栈中
                    flag = 0;
                    value = 0;
                }
                if (str[i] == ')') {
                    meet_right(snum, sope);
                } else {
                    get_ope(snum, sope, str[i]);
                }
            }
            i++;
        }
        if (flag == 1) {
            pushStack(snum, value);
        }
        while (isEmptyStack(sope) != 1) {
            popStack(sope, &oope);
            compute(snum, oope);
        }
        popStack(snum, &value);
        system("clear");
        printf("%s = %d\n", str, value);

    }
    return 0;
}