//
// Created by ABCPAN on 2021/4/25.
//

#ifndef INC_LQUEUE_H
#define INC_LQUEUE_H
#include "binary_sort_tree.h"
typedef struct QueueNode {
    NodePtr data;
    struct QueueNode *next;
}QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
}LinkQueue;

LinkQueue *InitQueue();
void DestoryQueue(LinkQueue*);
void EnQueue(LinkQueue*,NodePtr);
NodePtr popQueue(LinkQueue*);

#endif //INC_LQUEUE_H
