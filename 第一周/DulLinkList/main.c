
#include "duLinkedList.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    int where = 0;       /* record where is inserted */
    int number = 0;      /* record insert Lnode's value */
    int count = 0;       /* record the number of Lnode which is created in init Linklist */
    int flag = 0;        /* a sign about break cycle */
    int value = 0;       /* recive the Lnode's value which is delated */
    char ch;             /* recive command */
    DuLinkedList *L = (DuLinkedList *) malloc(sizeof(DuLinkedList));
    InitList_DuL(L);
    printf("你想创造几个节点\n");
    scanf("%d", &count);
    if (count < 1) {
        printf("节点数量错误\n");
        return 0;
    }
    DuLinkedList p, q, head, n;

    q = (DuLinkedList) malloc(sizeof(struct DuLNode));
    *L = q;
    for (int i = 1; i <= count; i++) {
        p = (DuLinkedList) malloc(sizeof(struct DuLNode));
        printf("输入第%d个数据\n", i);
        while (scanf("%d", &p->data) == 0) {
            printf("输入格式错误,请重输入");
            while (getchar() != '\n');    /* clear buffer area */
        }
        p->next = NULL;
        q->next = p;
        p->prior = q;
        q = p;
    }
    head = *L;      /* set a head to conveninent operation */
    menu();
    while (1) {
        ch = getchar();
        switch (ch) {
            case 'q':                /* left cycle */
                flag = 1;
                printf("退出成功\n");
                break;
            case 't':                /* travel the linklist */
                TraverseList_DuL(*L, print);
                menu();
                break;
            case 'a':                /* insert a new Lnode after a Lnode which is decide by us */
                printf("你想在第几个节点向后插入\n");
                scanf("%d", &where);
                if (where <= 0 || where > count) {
                    printf("错误，超过了范围\n");
                    menu();
                    break;
                }
                printf("你想插入的节点值为\n");
                while (scanf("%d", &number) == 0) {
                    printf("输入格式错误,请重输入");
                    while (getchar() != '\n');
                }
                n = (DuLinkedList) malloc(sizeof(DuLNode));
                n->data = number;
                p = head;
                for (int i = 1; i <= where; i++) {
                    p = p->next;
                }
                InsertAfterList_DuL(p, n);
                count++;
                menu();
                break;
            case 'b':                 /* insert a new Lnode before a Lnode which is decide by ue */
                printf("你想在第几个节点向前插入\n");
                scanf("%d", &where);
                if (where <= 0 || where > count) {
                    printf("错误，超过了范围\n");
                    menu();
                    break;
                }
                printf("你想插入的节点值为\n");
                while (scanf("%d", &number) == 0) {
                    printf("输入格式错误,请重输入");
                    while (getchar() != '\n');
                }
                n = (DuLinkedList) malloc(sizeof(DuLNode));
                n->data = number;
                p = head;
                for (int i = 1; i <= where; i++) {
                    p = p->next;
                }
                InsertBeforeList_DuL(p, n);
                count++;
                menu();
                break;
            case 'd':
                printf("你想删除第几个节点\n");
                scanf("%d", &where);
                if (where <= 0 || where > count) {
                    printf("错误，超过了范围\n");
                    menu();
                    break;
                }
                p = head;
                for (int i = 1; i <= where-1; i++) {
                    p = p->next;
                }
                DeleteList_DuL(p, &value);
                printf("删除的节点值为%d\n",value);
                count--;
                if (count == 0) {
                    printf("链表无元素了\n");
                    flag = 1;
                    break;
                }
                menu();
                break;

        }
        if (flag == 1)
            break;
    }

    DestroyList_DuL(L);     /* destroy all list */
    return 0;
}
