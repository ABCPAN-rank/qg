//
// Created by ABCPAN on 2021/4/10.
//

#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InitAQueue(AQueue *Q)
{
    Q->length=MAXQUEUE;
    for (int i = 0; i < MAXQUEUE; i++) {
        Q->data[i]=(void  *)malloc(11); // double 的大小为8,所以我觉得留够了
    }
    Q->rear=Q->front=0;
    printf("初始化成功\n");
}

void DestoryAQueue(AQueue *Q){
    if (Q->data[0] == NULL)
    {
        printf("队列没初始化\n");
        return;
    }
    for (int i = 0; i < MAXQUEUE; i++) {
        free(Q->data[i]);
    }
    Q->data[0]=NULL;
    printf("毁灭成功\n");
    return;
}

int LengthAQueue(AQueue *Q){
    int lenth=((Q->rear)-(Q->front)+(Q->length))%Q->length;
    return lenth;
}

Status IsEmptyAQueue(const AQueue *Q){
    if (Q->data[0] == NULL)
    {
        printf("队列没初始化\n");
        return FALSE;
    }
    if (LengthAQueue(Q)==0)
        return TRUE;
    else
        return FALSE;
}

Status IsFullAQueue(const AQueue *Q){
    if (Q->data[0] == NULL)
    {
        printf("队列没初始化\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
        return FALSE;
    if (LengthAQueue(Q)==MAXQUEUE-1)
    {
        return TRUE;
    }
    else{
        return FALSE;
    }
}


Status GetHeadAQueue(AQueue *Q, void *e){
    if (IsEmptyAQueue(Q)==TRUE){
        printf("队列为空\n");
        return FALSE;
    }
    memcpy(e,Q->data[Q->front],10);
    return TRUE;
}


Status EnAQueue(AQueue *Q, void *data){
    if (IsFullAQueue(Q)==TRUE){
        printf("队列满了\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)){
        memcpy(Q->data[Q->front],data,10);
        Q->rear=(Q->rear+1)%Q->length;
        printf("插入成功\n");
        return TRUE;
    }
    memcpy(Q->data[Q->rear], data, 10);
    Q->rear = (Q->rear + 1) % Q->length;
    printf("插入成功\n");
    return TRUE;
}


Status DeAQueue(AQueue *Q){
    if (IsEmptyAQueue(Q)){
        printf("队列为空，出不了队了\n");
        return FALSE;
    }
    Q->front=(Q->front+1)%Q->length;
    printf("出队成功\n");
    return TRUE;
}


void ClearAQueue(AQueue *Q){
    if (IsEmptyAQueue(Q)){
        printf("队列以空\n");
        return;
    }
    Q->front=Q->rear=0;
    printf("清除队列成功\n");
    return;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int),int a[],int head){  // 传入a为数组，方便得到队列每个元素的种类
    if (Q->data[0]==NULL){
        printf("队列未初始化\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)==TRUE){
        printf("队列为空\n");
        return FALSE;
    }
    int i =0;
    int count=head;
    while (i<(MAXQUEUE-Q->front+Q->rear)%MAXQUEUE){
        foo(Q->data[Q->front+i],a[count++]);
        i=(i+1)%MAXQUEUE;
    }
    return TRUE;
}

void APrint(void *q,int a){
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
    printf("你想干什么\ni.初始化队列\nf.判断队列是否满\ne.判断队列是否空\nt.遍历队列\nc.清除队列\nl,获得队列长度\na.插入队列\np.弹出队列\ng.得到队列头\nq.离开\n");
}