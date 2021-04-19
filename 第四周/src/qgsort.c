//
// Created by ABCPAN on 2021/4/18.
//

# include "qgsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(int *a, int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

void MergeArray(int *a, int begin, int mid, int end) {
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j, k;
    for (i = begin; i <= mid; i++)
        left[i - begin] = a[i];
    for (i = mid + 1; i <= end; i++)
        right[i - mid - 1] = a[i];
    i = j = 0;
    k = begin;
    while (i < n1 && j < n2)
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];

    while (i < n1)  // 处理上面没处理完的
        a[k++] = left[i++];
    while (j < n2)
        a[k++] = right[j++];
}

void MergeSort(int *a, int begin, int end) {
    if (begin == end) {
        return;
    }
    int mid = (begin + end) / 2;
    MergeSort(a, begin, mid);
    MergeSort(a, mid + 1, end);
    MergeArray(a, begin, mid, end);
}

int Partition(int *a, int begin, int end) {
    return a[begin];
}

void swap(int *a, int i, int j) {
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void QuickSort_Recursion(int *a, int begin, int end) {
    int i, j, partiton;
    if (begin >= end)return;
    partiton = Partition(a, begin, end);
    i = begin;
    j = end;
    while (i != j) {
        while (a[j] >= partiton && i < j)j--;
        while (a[i] <= partiton && i < j)i++;
        if (i < j)swap(a, i, j);
    }
    a[begin] = a[i];
    a[i] = partiton;
    QuickSort_Recursion(a, begin, i - 1);
    QuickSort_Recursion(a, i + 1, end);
}

int one_sort(int *a, int begin, int end) {
    int i, j, partiton;
    if (begin >= end)return EOF;
    partiton = Partition(a, begin, end);
    i = begin;
    j = end;
    while (i != j) {
        while (a[j] >= partiton && i < j)j--;
        while (a[i] <= partiton && i < j)i++;
        if (i < j)swap(a, i, j);
    }
    a[begin] = a[i];
    a[i] = partiton;
    return i;
}

void QuickSort(int *a, int size) {
    int left = 0;
    int right = size - 1;
    int *stack = (int *) malloc(sizeof(int) * 100);
    int top = -1;
    if (left < right) {
        stack[++top] = right;
        stack[++top] = left;
        while (top > -1) {
            int l = stack[top--];
            int r = stack[top--];
            int mid = one_sort(a, l, r);
            if (mid == EOF)return;
            if (l < (mid - 1)) {
                stack[++top] = mid - 1;
                stack[++top] = l;
            }
            if ((mid + 1) < r) {
                stack[++top] = r;
                stack[++top] = mid + 1;
            }
        }
    }
    free(stack);
}

int getmax(int *a, int size) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void CountSort(int *a, int size) {
    int max = getmax(a, size);
    int *b, *c;
    int i;
    c = (int *) malloc(sizeof(int) * max);
    b = (int *) malloc(sizeof(int) * size);
    for (i = 0; i < max; i++)
        c[i] = 0;
    for (i = 0; i < size; i++)
        c[a[i]] += 1;
    for (i = 1; i <= max; i++)
        c[i] = c[i] + c[i - 1];
    for (i = size - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] -= 1;
    }
    for (int j = 0; j < size; j++) {
        a[j] = b[j];
    }
    free(c);
    free(b);
}


int GetNumInPos(int num, int pos) {
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}


void RadixCountSort(int *a, int size) {
    int *radix[10];
    int max = getmax(a, size);
    int count = 0;
    while (max != 0) {
        count++;
        max /= 10;
    }
    for (int i = 0; i < 10; i++) {
        radix[i] = (int *) malloc(sizeof(int) * size);
        radix[i][0] = 0;
    }
    for (int pos = 1; pos <= count; pos++) {
        for (int j = 0; j < size; j++) {
            int num = GetNumInPos(a[j], pos);
            int index = ++radix[num][0];
            radix[num][index] = a[j];
        }
        for (int i = 0, j = 0; i < 10; i++) {
            for (int k = 1; k <= radix[i][0]; k++)
                a[j++] = radix[i][k];
            radix[i][0] = 0;
        }
    }
}

void ColorSort(int *a, int size) {
    int zero = -1;
    int two = size;
    for (int i = 0; i < two;) {
        if (a[i] == 1) {
            i++;
        } else if (a[i] == 2) {
            swap(a, i, --two);
        } else if (a[i] == 0) {
            swap(a, ++zero, i++);
        }
    }
}

int quicksort(int *a, int start, int end, int k) {
    int pivot = a[start];
    int left = start, right = end;
    while (right > left) {
        while (right > left && a[right] <= pivot)right--;
        a[left] = a[right];
        while (right > left && a[left] >= pivot)left++;
        a[right] = a[left];
    }
    a[right] = pivot;
    if (right == k - 1)return a[right];
    else if (right > k - 1)return quicksort(a, start, right - 1, k);
    return quicksort(a, right + 1, end, k);
}

int FindNumber(int *a, int size, int k) {
    if (k > size / 10) {
        printf("ERROR\n");
        return 0;
    }
    int result = quicksort(a, 0, size - 1, k);
    return result;
}


int *CreatArray(int max) {
    if (max>200000)
    {
        printf("out of range\n");
        return NULL;
    }
    int *arr = (int *) malloc(sizeof(int) * max);
    srand((unsigned int) time(NULL));
    for (int i = 0; i < max; i++) {

        int randNum = rand() % max;
        arr[i] = randNum;
    }
    return arr;
}


void menu() {
    printf("你想干什么\n");
    printf("a，快速排序\n");
    printf("b,快速排序非递归\n");
    printf("c,归并排序\n");
    printf("d,计数排序\n");
    printf("e.基数排序\n");
    printf("f,颜色排序\n");
    printf("g,找出第k个大的数\n");
    printf("h,生成测试数据的文件\n");
    printf("q，退出\n");
}


void menu1(){
    printf("你想干什么\n");
    printf("a，快速排序\n");
    printf("b,快速排序非递归\n");
    printf("c,归并排序\n");
    printf("d,计数排序\n");
    printf("e.基数排序\n");
    printf("q，退出\n");
}


void menu2(){
    printf("你想干什么\n");
    printf("a，快速排序\n");
    printf("b,快速排序非递归\n");
    printf("c,归并排序\n");
    printf("d,计数排序\n");
    printf("e.基数排序\n");
    printf("g,找出第k个大的数\n");
    printf("q，退出\n");
}