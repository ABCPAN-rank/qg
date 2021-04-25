//
// Created by ABCPAN on 2021/4/24.
//
#include "binary_sort_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"



int main (){
    BinarySortTreePtr T=(BinarySortTreePtr) malloc(sizeof(BinarySortTree));
    BST_init(T);
    char ch;
    int sign=0;
    int a[1000];
    int count=0;
    int flag=0;
    menu();
    while (1){
        ch=getchar();
        switch (ch) {
            case 'q':
                flag=1;
                free(T);
                printf("退出成功\n");
                system("clear");
                break;
            case 'a':
                sign=0;
                printf("请输入你想插入的数字:");
                int num;
                while (scanf("%d", &num) == 0) {
                    printf("输入格式错误,请重输入");
                    while (getchar() != '\n');    /* clear buffer area */
                }
                count++;
                a[count]=num;
                for (int i = 0; i < count; i++) {
                    if (a[i]==num)
                    {
                        system("clear");
                        printf("此数存在于树中，无法插入\n");
                        sign=1;
                    }
                }
                if (sign==1)
                {
                    menu();
                    break;
                }
                system("clear");
                BST_insert(T,num);
                menu();
                break;
            case 'b':
                printf("请输入你想查找的数字:");
                int number;
                while (scanf("%d", &number) == 0) {
                    printf("输入格式错误,请重输入");
                    while (getchar() != '\n');    /* clear buffer area */
                }
                system("clear");
                if(BST_search(T->root,number)==NULL)
                    printf("未找到\n");
                else
                    printf("找到了\n");
                menu();
                break;
            case 'c':
                printf("请输入你想删除的数字:");
                int numb;
                while (scanf("%d", &numb) == 0) {
                    printf("输入格式错误,请重输入");
                    while (getchar() != '\n');    /* clear buffer area */
                }
                system("clear");
                BST_delete(T,numb);
                menu();
                if (T->root==NULL)
                {
                    printf("你删除了根节点\n");
                    return 0;
                }
                break;
            case 'd':
                system("clear");
                BST_preorderR(T->root,print);
                menu();
                break;
            case 'e':
                system("clear");
                BST_inorderR(T->root,print);
                menu();
                break;
            case 'f':
                system("clear");
                BST_postorderR(T->root,print);
                menu();
                break;
            case 'g':
                system("clear");
                BST_preorderI(T,print);
                menu();
                break;
            case 'h':
                system("clear");
                BST_inorderI(T,print);
                menu();
                break;
            case 'i':
                system("clear");
                BST_postorderI(T,print);
                menu();
                break;
            case 'j':
                system("clear");
                BST_levelOrder(T,print);
                menu();
                break;
        }
        if (flag==1)
            return 0;
    }
}