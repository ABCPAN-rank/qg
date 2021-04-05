#include <linkedList.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int a_sign_of_loop = 0; /* a sign about loop LinkList*/
    int where = 0;          /* record where is inserted */
    int number = 0;         /* record insert or delete Lnode's value */
    int count = 0;          /* record the number of Lnode which is created in init Linklist */
    int flag = 0;           /* a sign about break cycle */
    int value = 0;          /* recive the Lnode's value which is delated */
    char ch;                /* recive command */
    LinkedList p, q, head, n, rever, find;
    LinkedList *L = (LinkedList *) malloc(sizeof(LinkedList));
    InitList(L);
    printf("你想创造几个节点\n");
    scanf("%d", &count);
    if (count < 1) {
        printf("节点数量错误\n");
        return 0;
    }
    q = (LinkedList) malloc(sizeof(LNode));
    (*L) = q;
    for (int i = 1; i <= count; i++) {
        p = (LinkedList) malloc(sizeof(LNode));
        printf("输入第%d个数据\n", i);
        while (scanf("%d", &p->data) == 0) {
            printf("输入格式错误,请重输入\n");
            while (getchar() != '\n');      /* clear buffer area */
        }
        p->next = NULL;
        q->next = p;
        q = p;
    }
    head = *L;           /* set a head to conveninent operation */
    printf("你想让它成环吗\n1为是，0为否");
    while (scanf("%d", &a_sign_of_loop) == 0) {
        printf("输入格式错误,请重输入");
        while (getchar() != '\n');
    }
    if (a_sign_of_loop != 0 && a_sign_of_loop != 1) {
        printf("错误，建议重开\n");
        return 0;
    }
    if (a_sign_of_loop == 1) {
        p->next = *L;
    }
    menu();
    while (1) {
        ch = getchar();
        switch (ch) {
            case 'q':         /* left cycle */
                flag = 1;
                printf("退出成功");
                break;
            case 't':         /* travel the linklist */
                if (a_sign_of_loop == 1) {
                    printf("成环的，遍历没意义\n");
                    break;
                }
                TraverseList(*L, print);
                menu();
                break;
            case 'a':         /* insert a new Lnode after Lnode which is decide by us */
                if (a_sign_of_loop == 1) {
                    printf("成环的，插入了你也遍历不了\n");
                    break;
                }
                printf("你想在第几个节点插入\n");
                scanf("%d", &where);
                if (where <= 0 || where > count) {
                    printf("错误，超出范围\n");
                    menu();
                    break;
                }
                printf("你想插入的节点值为\n");
                while (scanf("%d", &number) == 0) {
                    printf("输入格式错误,请重输入");
                    while (getchar() != '\n');
                }
                n = (LinkedList) malloc(sizeof(LNode));
                n->data = number;
                p = head;
                for (int i = 1; i <= where; i++) {
                    p = p->next;
                }
                InsertList(p, n);
                count++;
                menu();
                break;
            case 'r':           /* exchange odd and even Lnode */
                if (a_sign_of_loop == 1) {
                    printf("成环的\n");
                    break;
                }
                rever = ReverseEvenList(&head);
                TraverseList(rever, print);
                flag = 1;
                break;
            case 'R':            /* rever all List */
                if (a_sign_of_loop == 1) {
                    printf("成环的\n");
                    break;
                }
                ReverseList(L);
                menu();
                break;
            case 'f':          /* find the Lnode which is in the mid of List */
                if (a_sign_of_loop == 1) {
                    printf("成环的，下面那个函数返回NULL，没用\n");
                    break;
                }
                find = FindMidNode(L);
                printf("中间节点值为%d\n", find->data);
                menu();
                break;
            case 'i':          /* judge the list is loop */
                IsLoopList(*L);
                menu();
                break;
            case 'd':
                if (a_sign_of_loop == 1) {
                    printf("成环的，删了你也遍历不了\n");
                    break;
                }
                printf("你想在第几个节点删除\n");
                scanf("%d", &where);
                if (where <= 0 || where > count) {
                    printf("错误，超出范围\n");
                    menu();
                    break;
                }
                p = head;
                for (int i = 1; i <= where - 1; i++) {
                    p = p->next;
                }
                DeleteList(p, &value);
                count--;
                printf("删除的节点值为%d\n", value);
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
    DestroyList(L);       /* clear Linklist*/
    return 0;
}