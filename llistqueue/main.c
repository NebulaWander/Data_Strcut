#include <stdio.h>
#include "llistqueue.h"

int main()
{
    int num[] = {1, 2, 3, 4, 5};
    int size = ((sizeof(num)) / (sizeof(num[0])));

    // 创建链式队列
    LListQueue_t *llist_queue;
    llist_queue = LListQueue_Create();
    if (NULL == llist_queue){
        printf("error!!!!!\n");
    }

    // 入栈
    for (int i = 0; i < size; i++){
        if (0 != LListQueue_EnQueue(llist_queue, num[i])){
            printf("error!!!!!\n");
            break;
        }
    }
    // 遍历链式队列中的元素
    printf("链式队列元素：");
    LListQueue_Show(llist_queue);

    // 出栈
    int temp = 0;
    temp = LListQueue_DeQueue(llist_queue);
    printf("出队元素：%d\n", temp);

    printf("链式队列元素：");
    // 遍历链式队列中的元素
    LListQueue_Show(llist_queue);

    // 释放链式队列空间内存
    LListQueue_Free(llist_queue);

    return 0;
}
