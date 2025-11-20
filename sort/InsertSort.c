// 插入排序：是把无序序列中元素依次插入到有序序列中，一般是从有序序列的尾部开始比较
#include <stdio.h>

int main()
{
    // 1.定义一个数组
    int num[] = {3, 5, 7, 9, 0, 2, 4, 1, 6, 8};
    // 2.计算数组中元素的个数
    int length = (sizeof(num) / sizeof(num[0]));
    // 3.记录待插入元素
    int temp = 0;
    // 4.记录下标
    int current_prev = 0;

    // 3.遍历排序之前的数组元素
    for (int i = 0; i < length; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    // 将数组中的一个元素当作有序序列，其余元素的是无序序列
    for (int i = 1; i < length; i++){
        // 备份待插入元素的值
        temp = num[i];
        for (int j = (i - 1); j >= 0; j--){
            if (temp < num[j]){
                current_prev = j;
                // 后移一位，将元素插入当前元素的前面
                num[j + 1]   = num[j];
            }
            else{
                // 实际上就是当前元素的下标
                current_prev = (j + 1);
                break;
            }
        }
        // 插入元素
        num[current_prev] = temp;
    }    

    // 4.遍历排序之后的数组元素
    for (int i = 0; i < length; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}