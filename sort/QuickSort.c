// 快速排序：选择一个基准值，基准值的左边都比它小，基准值的右边都比它大
#include <stdio.h>

// 快速排序函数接口
void QuickSort(int num[], int low, int high)
{
    int temp = 0;   // 记录基准值的值
    int i = low;    // 记录数组首元素的下标
    int j = high;   // 记录数组尾元素的下标

    if (low < high){
        // 将数组首元素作为基准值
        temp = num[low];    
        // i 和 j 相等代表结束
        while (i < j){
            // 交替扫描
            // 先从数组的右边寻找比基准值小的，找到就把这个值放在基准值的位置
            // 交换方向，从数组的左边
            while ((j > i) && (num[j] > temp)){
                j--;
            }
            if (i < j){
                // 将找到的比基准值小的元素放到数组首位置
                num[i] = num[j];
                // 跳过数组首元素
                i++;
            }            
            // 再从数组的左边寻找比基准值大的，找到就把这个值放到上一次的空位置(上一次交换比基准值小的元素的位置)中
            // 交换方向，从数组的右边
            while ((i < j) && (num[i] < temp)){
                i++;
            }
            if (i < j){
                // 将找到的比基准值大的元素放到上一次的空位置(上一次交换比基准值小的元素的位置)中
                num[j] = num[i];
                // 跳过交换到上一次空位置中的元素
                j--;
            }
        }

        // 插入基准值
        num[i] = temp;
        // 使用递归对基准值的左边进行排序
        QuickSort(num, low, i-1);
        // 使用递归对基准值的右边进行排序
        QuickSort(num, i+1, high);
    }
}

int main()
{
    // 1.定义一个数组
    int num[] = {3, 5, 7, 9, 0, 2, 4, 1, 6, 8};
    // 2.计算数组中元素的个数
    int length = (sizeof(num) / sizeof(num[0]));

    // 3.遍历排序之前的数组元素
    for (int i = 0; i < length; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    QuickSort(num, 0, 9);

    // 4.遍历排序之后的数组元素
    for (int i = 0; i < length; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}