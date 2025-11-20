// 冒泡排序
#include <stdio.h>

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

    // 需要的轮数
    for (int i = 0; i < (length - 1); i++){
        // 两两元素之间交换的次数
        for (int j = 0; j < (length-1-i); j++){
            if (num[j] > num[j + 1]){
                // 交换元素
                int temp   = num[j];
                num[j]     = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    // 4.遍历排序之后的数组元素
    for (int i = 0; i < length; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}