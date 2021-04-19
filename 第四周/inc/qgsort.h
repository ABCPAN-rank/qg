
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end
 */
void MergeArray(int *a,int begin,int mid,int end);


/**
 *  @name        : void MergeSort(int *a,int begin,int end);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void MergeSort(int *a,int begin,int end);

/*!
 * @description :一次快速排序
 * @param a 数组
 * @param left 开头
 * @param right 结尾
 * @return 回传中轴
 */
int one_sort(int* a, int left, int right);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);

/**
 * @ name :void swap(int *a,int i,int j)
 * @ description :交换数组中的两个值顺序
 */
void swap(int *a,int i,int j);

/**
 * @ name :int getmax(int *a,int size)
 * @ description ：获得数组中的最大值
 */
int getmax(int *a,int size);

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size
 */
void CountSort(int *a, int size );


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : int FindNumber(int *a,int size,int k)
 *  @description : 在一个无序序列中找到第K大的数
 *  @param       : 数组指针a，数组长度size,第几大的数
 */
int FindNumber(int *a,int size,int k);

/*！
 * @name :int quicksort(int *a,int start,int end,int k)
 * @description :快速排序的比较下标来传回第k大的数
 */
int quicksort(int *a,int start,int end,int k);

/*!
 * @description :创造数组
 * @param :max 创造的数量
 * @return
 */
int *CreatArray(int max) ;

/**
 * @description :打印页面
 */
void menu();

/**
 * @ description :打印页面1
 */
void menu1();

/**
 * @description :打印页面2
 */
void menu2();

#endif // QUEUE_H_INCLUDED
