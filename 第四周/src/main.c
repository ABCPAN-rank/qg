//
// Created by ABCPAN on 2021/4/18.
//
#include "qgsort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SMALL 10

int main() {
    clock_t start, end;
    int max;
    int flag = 0;
    int p;
    char type;
    int *color;
    printf("你想生成小数组或者大数据\na为大数据\nb为小数据\nc,阅读数据排序\n");
    type = getchar();
    switch (type) {
        case 'a':
            printf("你想生成多大的数据集\n");
            while (scanf("%d", &max) == 0) {
                printf("输入格式错误,请重输入\n");
                while (getchar() != '\n');      /* clear buffer area */
            }
            int *a = CreatArray(max);
            if (a == NULL)return 0;
            char ch;
            menu();
            while (1) {
                ch = getchar();
                FILE *fpWrite = fopen("data.txt", "w");
                switch (ch) {
                    case 'q':
                        flag = 1;
                        system("clear");
                        printf("退出成功\n");
                        break;
                    case 'a':
                        system("clear");
                        start = clock();
                        QuickSort_Recursion(a, 0, max - 1);
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu();
                        break;
                    case 'b':
                        system("clear");
                        start = clock();
                        QuickSort(a, max);
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu();
                        break;
                    case 'c':
                        system("clear");
                        start = clock();
                        MergeSort(a, 0, max - 1);
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu();
                        break;
                    case 'd':
                        system("clear");
                        start = clock();
                        CountSort(a, max);
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu();
                        break;
                    case 'e':
                        system("clear");
                        start = clock();
                        RadixCountSort(a, max);
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu();
                        break;
                    case 'f':
                        system("clear");
                        color = (int *) malloc(sizeof(int) * max);
                        srand((unsigned int) time(NULL));
                        for (int i = 0; i < max; i++) {   // 生成不大于2的数组
                            int randNum = rand() % 2;
                            color[i] = randNum;
                        }
                        start = clock();
                        ColorSort(color, max);
                        end = clock();
                        printf("时间是%f", (double) (end - start) / CLOCKS_PER_SEC);
                        menu();
                        break;
                    case 'g':
                        system("clear");
                        printf("你想找第几大的数\n");
                        int k;
                        scanf("%d", &k);
                        int result = FindNumber(a, max, k);
                        printf("第%d个大的数是%d\n", k, result);
                        menu();
                        break;
                    case 'h':
                        system("clear");
                        if (fpWrite == NULL) {
                            return 0;
                        }
                        for (int i = 0; i < max; i++)
                            fprintf(fpWrite, "%d ", a[i]);
                        fclose(fpWrite);
                        printf("生成成功\n");
                        menu();
                        flag = 1;
                        break;
                }
                if (flag == 1)
                    return 0;
            }
        case 'b':
            printf("你想生成多少数据集\n");

            while (scanf("%d", &p) == 0) {
                printf("输入格式错误,请重输入\n");
                while (getchar() != '\n');      /* clear buffer area */
            }
            char cha;
            menu1();
            while (1) {
                cha = getchar();
                switch (cha) {
                    case 'q':
                        flag = 1;
                        system("clear");
                        printf("退出成功\n");
                        break;
                    case 'a':
                        system("clear");
                        start = clock();
                        for (int i = 0; i < p; i++) {
                            a = CreatArray(SMALL);
                            QuickSort_Recursion(a, 0, SMALL - 1);
                        }

                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu1();
                        break;
                    case 'b':
                        system("clear");
                        start = clock();
                        for (int i = 0; i < p; i++) {
                            a = CreatArray(SMALL);
                            QuickSort(a, SMALL);
                        }
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu1();
                        break;
                    case 'c':
                        system("clear");
                        start = clock();
                        for (int i = 0; i < p; i++) {
                            a = CreatArray(SMALL);
                            MergeSort(a, 0, SMALL - 1);
                        }
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu1();
                        break;
                    case 'd':
                        system("clear");
                        start = clock();
                        for (int i = 0; i < p; i++) {
                            a = CreatArray(SMALL);
                            CountSort(a, SMALL);
                        }
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu1();
                        break;
                    case 'e':
                        system("clear");
                        start = clock();
                        for (int i = 0; i < p; i++) {
                            a = CreatArray(SMALL);
                            RadixCountSort(a, SMALL);
                        }
                        end = clock();
                        printf("时间是%f\n", (double) (end - start) / CLOCKS_PER_SEC);
                        menu1();
                        break;

                }
                if (flag == 1)
                    return 0;
            }

        case 'c':
            printf("输入数据数量\n");
            FILE *fpRead = fopen("data.txt", "r");
            if (fpRead == NULL) {
                printf("未找到\n");
                return 0;
            }
            int number;
            scanf("%d", &number);
            int *rea = (int *) malloc(sizeof(int) * number);
            for (int i = 0; i < number; i++) {
                fscanf(fpRead, "%d ", &rea[i]);
            }
            system("clear");
            char re;
            menu2();
            while (1) {
                re = getchar();
                switch (re) {
                    case 'q':
                        flag = 1;
                        system("clear");
                        printf("退出成功\n");
                        break;
                    case 'a':
                        system("clear");
                        start = clock();
                        QuickSort_Recursion(rea, 0, number - 1);
                        end = clock();
                        printf("时间是%f", (double) (end - start) / CLOCKS_PER_SEC);
                        menu2();
                        break;
                    case 'b':
                        system("clear");
                        start = clock();
                        QuickSort(rea, number);
                        end = clock();
                        printf("时间是%f", (double) (end - start) / CLOCKS_PER_SEC);
                        menu2();
                        break;
                    case 'c':
                        system("clear");
                        start = clock();
                        MergeSort(rea, 0, number - 1);
                        end = clock();
                        printf("时间是%f", (double) (end - start) / CLOCKS_PER_SEC);
                        menu2();
                        break;
                    case 'd':
                        system("clear");
                        start = clock();
                        CountSort(rea, number);
                        end = clock();
                        printf("时间是%f", (double) (end - start) / CLOCKS_PER_SEC);
                        menu2();
                        break;
                    case 'e':
                        system("clear");
                        start = clock();
                        RadixCountSort(rea, number);
                        end = clock();
                        printf("时间是%f", (double) (end - start) / CLOCKS_PER_SEC);
                        menu();
                        break;
                    case 'g':
                        system("clear");
                        printf("你想找第几大的数\n");
                        int k;
                        scanf("%d", &k);
                        int result = FindNumber(rea, number, k);
                        printf("第%d个大的数是%d", k, result);
                        menu2();
                        break;
                }
                if (flag == 1)
                    return 0;
            }


    }
}