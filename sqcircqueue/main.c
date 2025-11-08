#include <stdio.h>
#include "sqcircqueue.h"

int main()
{
    DataType_t arr[] = {10, 25, 15, 20};
    DataType_t size  = (sizeof(arr) / sizeof(arr[0]));
    SqCircQueue_t *sqcircqueue;

    // 创建循环队列
    sqcircqueue = SqCircQueue_Create();
    // 判断循环队列是否创建成功
    if (NULL == sqcircqueue){
        printf("error!!!!!\n");
    }

    // 入队
    for(int i = 0; i < size; i++){        
        if (0 != SqCircQueue_EnQueue(sqcircqueue, &arr[i])){
            printf("error!!!!!\n");
        }
    }
    // 遍历顺序循环队列的元素
    printf("顺序循环队列元素：");
    SqCircQueue_Show(sqcircqueue);

    // 出队
    int tmp = 0;
    if (-1 == SqCircQueue_DeQueue(sqcircqueue, &tmp)){
        printf("error!!!!!\n");
    }
    else{
        printf("出队元素：%d\n",tmp);
    }
    // 遍历顺序循环队列的元素
    printf("顺序循环队列元素：");
    SqCircQueue_Show(sqcircqueue);

    // 释放顺序循环队列的内存空间
    SqCircQueue_Destroy(sqcircqueue);

    return 0;
}