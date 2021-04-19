
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end
 */
void MergeArray(int *a,int begin,int mid,int end);


/**
 *  @name        : void MergeSort(int *a,int begin,int end);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void MergeSort(int *a,int begin,int end);

/*!
 * @description :һ�ο�������
 * @param a ����
 * @param left ��ͷ
 * @param right ��β
 * @return �ش�����
 */
int one_sort(int* a, int left, int right);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);

/**
 * @ name :void swap(int *a,int i,int j)
 * @ description :���������е�����ֵ˳��
 */
void swap(int *a,int i,int j);

/**
 * @ name :int getmax(int *a,int size)
 * @ description ����������е����ֵ
 */
int getmax(int *a,int size);

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size
 */
void CountSort(int *a, int size );


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : int FindNumber(int *a,int size,int k)
 *  @description : ��һ�������������ҵ���K�����
 *  @param       : ����ָ��a�����鳤��size,�ڼ������
 */
int FindNumber(int *a,int size,int k);

/*��
 * @name :int quicksort(int *a,int start,int end,int k)
 * @description :��������ıȽ��±������ص�k�����
 */
int quicksort(int *a,int start,int end,int k);

/*!
 * @description :��������
 * @param :max ���������
 * @return
 */
int *CreatArray(int max) ;

/**
 * @description :��ӡҳ��
 */
void menu();

/**
 * @ description :��ӡҳ��1
 */
void menu1();

/**
 * @description :��ӡҳ��2
 */
void menu2();

#endif // QUEUE_H_INCLUDED
