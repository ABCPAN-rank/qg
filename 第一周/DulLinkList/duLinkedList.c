#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    *L = (DuLinkedList) malloc(sizeof(DuLNode));
    if (*L == NULL)return ERROR;
    (*L)->next = NULL;
    (*L)->prior = NULL;
    printf("创造头节点完成\n");
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p, q;
    if (p == NULL) {
        printf("此表为空\n");
        return;
    }
    p = (*L)->next;
    while (p != NULL) {
        q = p->next;
        p->prior=NULL;
        free(p);
        p = q;
    }
    free(p);
    L = NULL;
    printf("全表删除完毕\n");
    return;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    DuLinkedList f;
    if (p == NULL || q == NULL) {
        printf("传入的表有问题\n");
        return ERROR;
    }
    f = p->prior;
    f->next = q;
    q->next = p;
    q->prior = f;
    p->prior = q;
    printf("向前插入完成\n");
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    DuLinkedList r;
    if (p == NULL || q == NULL) {
        printf("传入的表有问题\n");
        return ERROR;
    }
    r = p->next;
    if (r == NULL) {
        p->next = q;
        q->prior = p;
        q->next = NULL;
        printf("向后插入完成\n");
        return SUCCESS;
    }
    p->next = q;
    q->next = r;
    r->prior = q;
    q->prior = p;
    printf("向后插入完成\n");
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    DuLinkedList q, r;
    if (p->next == NULL) {
        printf("传入有问题\n");
        return ERROR;
    }
    q = p->next;
    r = q->next;
    if (r == NULL)
    {
        *e=q->data;
        free(q);
        p->next =NULL;
        printf("删除完成\n");
        return SUCCESS;
    }
    *e = q->data;
    free(q);
    p->next = r;
    printf("删除完成\n");
    return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList p, q;
    p = L;
    if (p == NULL || p->next == NULL) {
        printf("传入的指针无效\n");
        return;
    }
    q = p->next;
    while (q != NULL) {
        p = q;
        q = q->next;
        (*visit)(p->data);
    }
    return;
}

/*!
 * @description  print value which is in DulLinkList
 * @param        e
 */
void print(int e) {
    printf("%d\n", e);
}


/**
 * @description    print menu
 */
void menu() {
    printf("你想干什么（输入q退出）退出自动删除表\n");
    printf("输入t 遍历链表\n");
    printf("输入a，向后插入一个节点\n");
    printf("输入b，向前插入一个节点\n");
    printf("输入d，删除指定的节点并获得其值\n");
    return;
}
