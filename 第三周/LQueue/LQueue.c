//
// Created by ABCPAN on 2021/4/10.
//

#include "LQueue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void InitLQueue(LQueue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
    Q->length=0;
    printf("初始化成功\n");
}

void DestoryLQueue(LQueue *Q) {
    if (Q==NULL)
        return;
    Node *p = Q->front;
    while (p) {
        Q->front = p->next;
        free(p);
        p = Q->front;
    }
    printf("队列销毁成功\n");
}

Status IsEmptyLQueue(const LQueue *Q) {
    if (Q == NULL)
        return TRUE;
    if ((Q->length==0))
        return TRUE;
    return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e){
//    if (Q == NULL)
//        return FALSE;
    if (IsEmptyLQueue(Q)==TRUE){
        printf("队列为空\n");
        return FALSE;
    }
    memcpy(e,Q->front->data,10);
    return TRUE;
}

int LengthLQueue(LQueue *Q){
    if (Q == NULL)
        return FALSE;
    if (IsEmptyLQueue(Q)==TRUE)
    {
        return 0;
    }
    return Q->length;
}

Status EnLQueue(LQueue *Q, void *data){
    if (Q == NULL)
        return FALSE;
    if (IsEmptyLQueue(Q)==TRUE){
        Q->front=(Node *)malloc(sizeof(struct node));
        Q->front->data=malloc(10);
        memcpy(Q->front->data,data,10);
        Q->rear=Q->front;
        Q->length++;
        printf("插入成功\n");
        return TRUE;
    }
    Node *L=(Node *)malloc(sizeof(struct node));
    L->data=malloc(10);
    L->next=NULL;
    Q->rear->next=L;
    Q->rear=L;
    memcpy(Q->rear->data,data,10);
    Q->length++;
    printf("插入成功\n");
    return TRUE;
}

Status DeLQueue(LQueue *Q){
    if (Q->length==0){
        printf("队列为空，无法弹出\n");
        return FALSE;
    }
    Q->length--;
    Node * L=Q->front;
    Q->front=Q->front->next;
    free(L);
    printf("出队成功\n");
    return TRUE;
}

void ClearLQueue(LQueue *Q){
    if (Q == NULL)
        return ;
    if (IsEmptyLQueue(Q)==TRUE){
        printf("队列为空\n");
        return;
    }
    Q->length=0;
    Node * L=Q->front;
    while (L != NULL){

        Node *p=L;
        L=L->next;
        free(p);
    }
//    free(Q);
    printf("清除队列成功\n");
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int),int a[],int head){
    if (Q==NULL)
        return FALSE;
    if (Q->front==NULL){
        printf("队列未初始化\n");
        return FALSE;
    }
    if (IsEmptyLQueue(Q)==TRUE)
    {
        printf("队列为空\n");
        return FALSE;
    }
    int i =0;
    int count=head;
    Node *L=Q->front;
    while (L !=NULL){
        foo(L->data,a[count++]);
        L=L->next;
    }
    return TRUE;
}

void LPrint(void *q,int a){
    if (a==1)
    {
        printf("%d\n",*(int*) q);
        return;
    }
    else  if (a==2)
    {
        printf("%f\n",*(double*) q);
        return;
    }
    else  if (a==3){
        printf("%c\n",*(char *) q);
        return;
    }

}



void type_menu(){
    printf("请问你要输入什么值\n1.整型\n2.浮点型\n3.字符\n");
}

void menu(){
    printf("你想干什么\ni.初始化队列\ne.判断队列是否空\nt.遍历队列\nl,获得队列长度\na.插入队列\np.弹出队列\ng.得到队列头\nc.清除队列\nq.离开\n");
}