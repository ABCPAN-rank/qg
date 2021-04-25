//
// Created by ABCPAN on 2021/4/25.
//

#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>

LinkQueue *InitQueue() {
    LinkQueue *queue = (LinkQueue *) malloc(sizeof(LinkQueue));
    if (!queue)
        return NULL;
    queue->front = (QueueNode *) malloc(sizeof(QueueNode));
    queue->front->next = NULL;
    queue->rear = queue->front;
    return queue;
}

void DestoryQueue(LinkQueue *queue) {
    while (queue->front) {
        queue->rear = queue->front->next;
        free(queue->front);
        queue->front = queue->rear;
    }
}

void EnQueue(LinkQueue *queue, NodePtr node) {
    QueueNode *queueNode = (QueueNode *) malloc(sizeof(QueueNode));
    queueNode->data=node;
    queueNode->next=NULL;
    queue->rear->next=queueNode;
    queue->rear=queueNode;
}

NodePtr popQueue(LinkQueue* queue){
    if (queue->front==queue->rear)  // 此时队列为空，返回NULL
        return NULL;
    QueueNode *p=queue->front->next;
    NodePtr node=p->data;
    queue->front=p;
    return node;
}