//
// Created by ABCPAN on 2021/4/3.
//
#include "SqStack.h"
#include <stdlib.h>
#include <stdio.h>

Status initStack(SqStack *s,int sizes){
    if (s == NULL)
    {   printf("指针传入错误\n");
        return ERROR;}
    if (sizes<1)
    {
        printf("数字无效\n");
        return ERROR;
    }
    s->size=sizes;
    s->top=-1;
    s->elem=(int *)malloc(sizeof (int)*sizes);
    if (s->elem==NULL)
    {
        printf("Error\n");
        return ERROR;
    }
    printf("初始化完成\n");
    return SUCCESS;
}


Status isEmptyStack(SqStack *s){
    if (s == NULL)
    {   printf("指针传入错误\n");
        return ERROR;}

    if (s->top==-1)
    {printf("此顺序栈为空\n");
        return SUCCESS;}
    else {
        printf("此顺序栈不为空\n");
        return ERROR;
    }
}
Status getTopStack(SqStack *s,ElemType *e) {
    if (s == NULL || e == NULL) {
        printf("指针传入错误\n");
        return ERROR;
    }
    if (isEmptyStack(s) == SUCCESS)
    {
        printf("栈空\n");
        return ERROR;
    }
    *e=s->elem[s->top];
    printf("获得成功\n");
    return SUCCESS;
}


Status clearStack(SqStack *s){
    if (s == NULL){
        printf("指针传入错误\n");
        return ERROR;
    }
    s->top=-1;
    printf("清空成功\n");
    return SUCCESS;
}
Status destroyStack(SqStack *s){
    if (s == NULL){
        printf("指针传入错误\n");
        return ERROR;
    }
    free(s->elem);
    s->top=-1;
    printf("销毁成功\n");
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length){
    if (s == NULL){
        printf("指针传入错误\n");
        return ERROR;
    }
    *length=s->top+1;
    printf("成功返回长度\n");
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data){
    if (s == NULL){
        printf("指针传入错误\n");
        return ERROR;
    }
    if (s->top>=s->size-1)
    {
        printf("栈以满\n");
        return ERROR;
    }
    s->top++;
    s->elem[s->top]=data;
    printf("成功插入\n");
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data){
    if (s == NULL||data==NULL){
        printf("指针传入错误\n");
        return ERROR;
    }
    if (s->top==-1)
    {
        printf("栈空\n");
        return ERROR;
    }
    *data=s->elem[s->top];
    s->top--;
    printf("弹出成功\n");
    return SUCCESS;
}
void menu(){
    printf("\n请选择你想干什么\n");
    printf("q,离开\ni，初始化链栈\na，将数据压入链栈\n");
    printf("e，判断链栈是否为非空\nc,清空链栈\nd,从链栈中弹出首元素\nt，得到链栈的首元素\nl，得到链栈的长度\n");
    return;
}
