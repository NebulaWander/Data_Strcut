// 选择排序
#include <stdio.h>

int main()
{
    // 1.定义一个数组
    int num[] = {3, 5, 7, 9, 0, 2, 4, 1, 6, 8};
    // 2.计算数组中元素的个数
    int length = (sizeof(num) / sizeof(num[0]));
    // 3.记录最小值的下标
    int flag = 0;

    // 3.遍历排序之前的数组元素
    for (int i = 0; i < length; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    // 需要的轮数
    for (int i = 0; i < (length - 1); i++){
        // 记录第一个元素的下标
        flag = i;
        // 寻找数组中的最小元素
        for (int j = (i + 1); j < length; j++){
            // 一轮寻找完，第一个元素在下一次不再比较
            if (num[flag] > num[j]){
                // 更新下标
                flag = j;
            }
        }
        // 交换元素
        if (flag != i){
            // 说明找到最小元素，交换元素的值
            int temp  = num[flag];
            num[flag] = num[i];
            num[i]    = temp;     // 把找到的最小的元素放在数组首部
        }
    }

    // 4.遍历排序之后的数组元素
    for (int i = 0; i < length; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}