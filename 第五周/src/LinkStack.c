//
// Created by ABCPAN on 2021/4/24.
//

#include "LinkStack.h"
#include <stdlib.h>
#include <stdio.h>
//#include "LinkStack.h"


LStatus initLStack(LinkStack *s){
    if (s == NULL){
//        printf("传入指针错误\n");
        return ERROR;
    }
    s->top=NULL;
    s->count=0;
//    printf("成功初始化\n");
    return SUCCESS;
}
LStatus isEmptyLStack(LinkStack *s){
    if (s == NULL){
//        printf("传入指针错误\n");
        return ERROR;
    }
    if (s->count==0)
    {
//        printf("栈是空的\n");
        return SUCCESS;
    }
//    printf("栈非空\n");
    return ERROR;
}
LStatus getTopLStack(LinkStack *s, LElemType *e){
    if (s ==NULL||e==NULL||s->count==0)
    {
//        printf("传入指针出错\n");
        return ERROR;
    }
    *e=s->top->data;
//    printf("获取完成\n");
    return SUCCESS;
}
LStatus clearLStack(LinkStack *s){
    LinkStackPtr L;
    s->count=0;
    if (s->top!=NULL)
    {
        L=s->top;
        s->top=s->top->next;
        free(L);
    }
//    printf("clear over\n");
    return SUCCESS;
}
LStatus destroyLStack(LinkStack **s){
    clearLStack(*s);
    free(*s);
//    printf("摧毁完成\n");
    return SUCCESS;
}
LStatus LStackLength(LinkStack *s, int *length){
    if (s ==NULL)
    {
//        printf("指针有误\n");
        return ERROR;
    }
    *length = s->count;
//    printf("成功获得长度\n");
    return SUCCESS;
}
LStatus pushLStack(LinkStack *s, LElemType data){
    if (s ==NULL)
    {
//        printf("指针有误\n");
        return ERROR;
    }
    StackNode  *S = (StackNode *)malloc(sizeof(StackNode));
    S->data = data;
    S->next = s->top;
    s->top = S;
    s->count++;
//    printf("成功插入\n");
    return SUCCESS;
}
LStatus popLStack(LinkStack *s, LElemType *data){
    LinkStackPtr p;
    if (isEmptyLStack(s))
    {
//        printf("此栈为空\n");
        return ERROR;
    }
    *data = s->top->data;
    p=s->top;
    s->top=s->top->next;
    free(p);
    s->count--;
//    printf("成功弹出");
    return SUCCESS;
}