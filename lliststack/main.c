#include <stdio.h>
#include "lliststack.h"

int main()
{
    int num[] = {1, 2, 3, 4, 5};
    int size = ((sizeof(num)) / (sizeof(num[0])));

    // 创建顺序栈空间
    LListStack_t *llist_stack;
    llist_stack = LListStack_Create();
    if (NULL == llist_stack){
        printf("error!!!!!\n");
    }

    // 入栈
    for (int i = 0; i < size; i++){
        if (0 != LListStack_Push(llist_stack, num[i])){
            printf("error!!!!!\n");
            break;
        }
    }
    // 遍历栈空间中的元素
    LListStack_Show(llist_stack);

    // 出栈
    LListStack_Pop(llist_stack);
    // 遍历栈空间中的元素
    LListStack_Show(llist_stack);

    // 释放栈空间内存
    LListStack_Free(llist_stack);

    return 0;
}