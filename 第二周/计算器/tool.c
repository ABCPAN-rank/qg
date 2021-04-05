//
// Created by ABCPAN on 2021/4/5.
//
#include "SqStack.h"
int get_pri(int ope)
{
    switch(ope)
    {
        case '(':   return 0;
        case '+':
        case '-':   return 1;
        case '*':
        case '/':   return 2;
        default :   return -1;
    }
}

void compute(SqStack *snum,int ope){
    int n,n1,n2;
    popStack(snum,&n1);
    popStack(snum,&n2);
    switch (ope) {
        case '+': n=n1+n2; break;
        case '-': n=n2-n1; break;
        case '*': n=n1*n2; break;
        case '/': n=n2/n1; break;
    }
    pushStack(snum,n);
}

void get_ope(SqStack *snum,SqStack *sope,int ope){
    int oope;
    if (isEmptyStack(sope)||ope == '(') {
        pushStack(sope, ope);
        return;
    }
    getTopStack(sope,&oope);
    if (get_pri(ope)>get_pri(oope)){
        pushStack(sope,ope);
        return;;
    }
    while (get_pri(ope)<=get_pri(oope)){
        popStack(sope,&oope);
        compute(snum,oope);
        if (isEmptyStack(sope))
            break;
        getTopStack(sope,&oope);
    }
    pushStack(sope,ope);
}

void meet_right(SqStack *snum,SqStack *sope){
    int oope;  // 栈内字符串全部以ascii码储存
    getTopStack(sope,&oope);
    while (oope!='('){
        popStack(sope,&oope);  // 弹出符号，进行计算
        compute(snum,oope);
        getTopStack(sope,&oope); // 得到操作符栈内的首符号
    }
    popStack(sope,&oope); // 去除左括号
}