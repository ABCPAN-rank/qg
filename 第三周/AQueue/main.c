//
// Created by ABCPAN on 2021/4/10.
//

#include <stdio.h>
#include "AQueue.h"
#include <string.h>
#include <stdlib.h>
int main(){
    int flag=0;
    int a[100];
    int lenth = 0;
    int count =0;
    int head=0;
    AQueue *Q=(AQueue *)malloc(sizeof(AQueue));
    menu();
    char ch;
    while (1){
        void *p = malloc(10);
        ch=getchar();
        switch (ch) {
            case 'q':
                flag=1;
                system("clear\n");
                printf("退出成功\n");
            case 'i':
                system("clear");
                InitAQueue(Q);
                menu();
                break;
            case 'l':
                system("clear");
                lenth=LengthAQueue(Q);
                printf("长度为%d\n",lenth);
                menu();
                break;
            case 'f':
                system("clear");
                if (IsFullAQueue(Q) == TRUE) {
                    printf("队列已满\n");
                } else
                    printf("队列未满\n");
                menu();
                break;
            case 'e':
                system("clear");
                if(IsEmptyAQueue(Q)==TRUE)
                    printf("队列为空\n");
                else
                    printf("队列非空\n");
                menu();
                break;
            case 'g':
                system("clear");
                GetHeadAQueue(Q,p);
                APrint(p,a[head]);
                menu();
                break;
            case 'a':
                system("clear");
                type_menu();
                int ty=0;
                while (scanf("%d", &ty) == 0) {
                    printf("输入格式错误,请重输入\n");
                    while (getchar() != '\n');      /* clear buffer area */
                }
                printf("输入你想输入的数据\n");
                a[count]=ty;
                if (ty == 1)
                {
                    int data;
                    while (scanf("%d", &data) == 0) {
                        printf("输入格式错误,请重输入\n");
                        while (getchar() != '\n');      /* clear buffer area */
                    }
                    if(EnAQueue(Q,&data)==TRUE)
                    {count++;}
//                    printf("插入成功\n");
                    menu();
                    break;
                }
                else if(ty == 2)
                {
                    double data;
                    while (scanf("%lf", &data) == 0) {
                        printf("输入格式错误,请重输入\n");
                        while (getchar() != '\n');      /* clear buffer area */
                    }
                    if(EnAQueue(Q,&data)==TRUE)
                    {count++;}
//                    printf("插入成功\n");
                    menu();
                    break;
                }
                else
                {
                    while (getchar() != '\n');
                    char data;
                    while (scanf("%c", &data) == 0) {
                        printf("输入格式错误,请重输入\n");
                        while (getchar() != '\n');      /* clear buffer area */
                    }
                    if(EnAQueue(Q,&data)==TRUE)
                    {count++;}
//                    printf("插入成功\n");
                    menu();
                    break;
                }
            case 'p':
                system("clear");
                DeAQueue(Q);
                head++;
                menu();
                break;
            case 't':
                system("clear");
                TraverseAQueue(Q,APrint,a,head);
                menu();
                break;
            case 'c':
                system("clear");
                ClearAQueue(Q);
                count=0;
                head=0;
                menu();
                break;
        }
        if (flag == 1)
            break;
    }
    DestoryAQueue(Q);

}