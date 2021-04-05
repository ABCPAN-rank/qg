//
// Created by ABCPAN on 2021/4/3.
//

#include <stdlib.h>
#include <stdio.h>
#include "LinkStack.h"


Status initLStack(LinkStack *s){
    if (s == NULL){
        printf("传入指针错误\n");
        return ERROR;
    }
    s->top=NULL;
    s->count=0;
    printf("成功初始化\n");
    return SUCCESS;
}
Status isEmptyLStack(LinkStack *s){
    if (s == NULL){
        printf("传入指针错误\n");
        return ERROR;
    }
    if (s->count==0)
    {
        printf("栈是空的\n");
        return SUCCESS;
    }
    printf("栈非空\n");
    return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){
    if (s ==NULL||e==NULL||s->count==0)
    {
        printf("传入指针出错\n");
        return ERROR;
    }
    *e=s->top->data;
    printf("获取完成\n");
    return SUCCESS;
}
Status clearLStack(LinkStack *s){
    LinkStackPtr L;
    s->count=0;
    if (s->top!=NULL)
    {
        L=s->top;
        s->top=s->top->next;
        free(L);
    }
    printf("clear over\n");
    return SUCCESS;
}
Status destroyLStack(LinkStack **s){
    clearLStack(*s);
    free(*s);
    printf("摧毁完成\n");
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length){
    if (s ==NULL)
    {
        printf("指针有误\n");
        return ERROR;
    }
    *length = s->count;
    printf("成功获得长度\n");
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){
    if (s ==NULL)
    {
        printf("指针有误\n");
        return ERROR;
    }
    StackNode  *S = (StackNode *)malloc(sizeof(StackNode));
    S->data = data;
    S->next = s->top;
    s->top = S;
    s->count++;
    printf("成功插入\n");
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data){
    LinkStackPtr p;
    if (isEmptyLStack(s))
    {
        printf("此栈为空\n");
        return ERROR;
    }
    *data = s->top->data;
    p=s->top;
    s->top=s->top->next;
    free(p);
    s->count--;
    printf("成功弹出");
    return SUCCESS;
}
void menu(){
    printf("请选择你想干什么\n");
    printf("q,离开\ni，初始化链栈\na，将数据压入链栈\n");
    printf("e，判断链栈是否为非空\nc,清空链栈\nd,从链栈中弹出首元素\nt，得到链栈的首元素\nl，得到链栈的长度\n");
    return;
}

