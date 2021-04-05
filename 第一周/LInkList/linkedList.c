#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name          Status InitList(LinkList *L);
 *	@description   initialize an empty linked list with only the head node without value
 *	@param		   L(the head node)
 *	@return		   Status
 *  @notice        None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList) malloc(sizeof(LNode));
    if (*L == NULL)return ERROR;
    (*L)->next = NULL;
    printf("创造头节点完成\n");
    return SUCCESS;
}

/**
 *  @name          void DestroyList(LinkedList *L)
 *	@description   destroy a linked list, free all the nodes
 *	@param		   L(the head node)
 *	@return		   None
 *  @notice        None
 */
void DestroyList(LinkedList *L) {
    LinkedList p, q;
//    p=(*L);
    if (p == NULL) {
        printf("此表为空\n");
        return;
    }
    p = (*L)->next;
    if (IsLoopList(*L) == ERROR) {
        while (q != p) {
            q = p->next;
            free(p);
            p = q;
        }
        printf("删除完毕\n");
        return;
    }

    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    free(p);
    L = NULL;
    printf("删除全表完毕\n");
    return;

}

/**
 *  @name          Status InsertList(LNode *p, LNode *q)
 *	@description   insert node q after node p
 *	@param		   p, q
 *	@return		   Status
 *  @notice        None
 */
Status InsertList(LNode *p, LNode *q) {
    if (p == NULL || q == NULL) {
        printf("插入错误\n");
        return ERROR;
    }
    if ((p->next) == NULL) {
        p->next = q;
        q->next = NULL;
        printf("插入完成\n");
        return SUCCESS;
    } else {
        q->next = p->next;
        p->next = q;
        printf("插入完成\n");
        return SUCCESS;
    }

}

/**
 *  @name          Status DeleteList(LNode *p, ElemType *e)
 *	@description   delete the first node after the node p and assign its value to e
 *	@param		   p, e
 *	@return		   Status
 *  @notice        None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList q, r;
    if (!(p->next)) {
        printf("p是链表结尾了,删除失败\n");
        return ERROR;
    }
    q = p->next;
    r = q->next;
    if (r == NULL) {
        *e = q->data;
        free(q);
        p->next = NULL;
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
 *  @name          void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description   traverse the linked list and call the funtion visit
 *	@param		   L(the head node), visit
 *	@return		   None
 *  @notice        None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p, q;
    p = L;
    if (p == NULL || p->next == NULL) {
        printf("错误，传入的指针无效");
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

/**
 *  @name          Status SearchList(LinkedList L, ElemType e)
 *	@description   find the first node in the linked list according to e
 *	@param		   L(the head node), e
 *	@return		   Status
 *  @notice        None
 */
Status SearchList(LinkedList L, ElemType e) {
    int count = 1;
    LinkedList p, q;
    p = L;
    q = p->next;
    while (q != NULL) {
        if ((q->data) == e) {
            printf("e在第%d个节点\n", count);
            return SUCCESS;
        }
        count++;
        p = q;
        q = q->next;
    }
    printf("此表中无此数\n");
    return SUCCESS;
}

/**
 *  @name          Status ReverseList(LinkedList *L)
 *	@description   reverse the linked list
 *	@param		   L(the head node)
 *	@return		   Status
 *  @notice        None
 */
Status ReverseList(LinkedList *L) {
    LinkedList p, q, pr;
    p = (*L)->next;
    q = NULL;
    (*L)->next = NULL;
    while (p != NULL) {
        pr = p->next;
        p->next = q;
        q = p;
        p = pr;
    }
    (*L)->next = q;
    printf("反转完成\n");
    return SUCCESS;
}

/**
 *  @name          Status IsLoopList(LinkedList L)
 *	@description   judge whether the linked list is looped
 *	@param		   L(the head node)
 *	@return		   Status
 *  @notice        None
 */
Status IsLoopList(LinkedList L) {
    int flag = 0;
    if (L == NULL) {
        printf("链表为空，错误\n");
        return SUCCESS;
    }
    LinkedList fast = L;
    LinkedList slow = L;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            flag = 1;
            if (flag == 1)printf("成环\n");
            return ERROR;
        }
    }
    if (flag == 0)printf("不成环\n");


    return SUCCESS;
}

/**
 *  @name          LNode* ReverseEvenList(LinkedList *L)
 *	@description   reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		   L(the head node)
 *	@return		   LNode(the new head node)
 *  @notice        choose to finish
 */
LNode *ReverseEvenList(LinkedList *L) {
    LinkedList D_L, S_L, p, q, first;
    D_L = split(L);
    S_L = *L;
    if (S_L == D_L) {
        printf("此链表不存在或只有一个节点\n");
        return *L;
    }
    q = D_L->next;
    p = S_L->next;
    LinkedList new_head = (LinkedList) malloc(sizeof(struct LNode));
    first = new_head;
    while (p != NULL && q != NULL) {
        new_head->next = q;
        q = q->next;
        new_head = new_head->next;
        new_head->next = p;
        p = p->next;
        new_head = new_head->next;
    }
    printf("交换完成\n");
    return first;
}

/*!
 *
 */
Status addlist(LinkedList p, LinkedList q) {
    p->next = q;
    return SUCCESS;
}

/**
 *  @name          LNode* FindMidNode(LinkedList *L)
 *	@description   find the middle node in the linked list
 *	@param		   L(the head node)
 *	@return		   LNode
 *  @notice        choose to finish
 */
LNode *FindMidNode(LinkedList *L) {
    LinkedList slow, fast;
    slow = *L;
    fast = *L;
    if (IsLoopList(*L) == ERROR) {
        printf("这是个成环的链表\n");
        return NULL;
    }
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("找到了\n");
    return slow;

}

/*!
 * @name           LinkedList split(LinkedList L)
 * @description    the function can split a LinkList depend it's Lnode's Odevity (it isn't Lnode's value!!)
 * @param          L  :a LinkList
 * @return         M  :a part of LinkList (all Lnode is even Lnode)
 * @return         L  :a part of LinkList (all Londe is odd Lnode)
 */
LinkedList split(LinkedList *L) {
    LinkedList p = (*L)->next;
    LinkedList q = p->next;
    LinkedList M = (LinkedList) malloc(sizeof(LNode));
    M->next = NULL;
    if (p == NULL || q == NULL) return M;
    M->next = q;
    while (q != NULL) {
        p->next = q->next;
        p = q;
        q = q->next;
    }
    p->next = NULL;
    return M;
}


/*!
 * @name           void print(int e)
 * @param          e:print value
 * @description    print data
 */
void print(int e) {
    printf("%d\n", e);
}


/*!
 *  @description  print menu
 */
void menu() {
    printf("你想干什么（输入q退出）退出自动删除表\n");
    printf("输入t 遍历链表\n");
    printf("输入a，插入一个节点\n");
    printf("输入r，改变奇偶节点的位置，并退出程序\n");
    printf("输入i，判断节点是否闭环\n");
    printf("输入f, 寻找链表中间节点点\n");
    printf("输入R，使整个链表反转\n");
    printf("输入d，删除指定的节点\n");
    return;
}