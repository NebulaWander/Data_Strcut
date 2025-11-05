#include <stdio.h>
#include "sqstack.h"

int main()
{
    int num[] = {1, 2, 3, 4, 5};
    int size = ((sizeof(num)) / (sizeof(num[0])));

    // 创建顺序栈空间
    SqStack_t *sq_stack;
    sq_stack = SqSatck_Create();
    if (NULL == sq_stack){
        printf("error!!!!!\n");
    }

    // 入栈
    for (int i = 0; i < size; i++){
        if (0 != SqStack_Push(sq_stack, &num[i])){
            printf("error!!!!!\n");
            break;
        }
    }
    // 遍历栈空间中的元素
    SqStack_Show(sq_stack);

    // 出栈
    SqStack_Pop(sq_stack);
    // 遍历栈空间中的元素
    SqStack_Show(sq_stack);

    // 释放栈空间内存
    SqStack_Free(sq_stack);

    return 0;
}
