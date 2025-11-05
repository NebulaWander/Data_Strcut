#include "sqstack.h"

// 创建顺序栈空间
SqStack_t *SqSatck_Create(void)
{
    SqStack_t *sq_stack = (SqStack_t *)calloc(1, sizeof(SqStack_t));
    if (sq_stack == NULL){
        return NULL;
    }
    sq_stack->Top = -1;
    return sq_stack;
}

// 入栈-栈空间放入元素（尾部）
int SqStack_Push(SqStack_t *sq_stack, DataType_t *data)
{
    // 判断占空间是否已满
    if ((SIZE - 1) == sq_stack->Top){
        return -1;
    }
    // 放入元素
    sq_stack->data[++(sq_stack->Top)] = *data;

    return 0;
}

// 出栈-栈空间取出元素（尾部）
int SqStack_Pop(SqStack_t *sq_stack)
{
    // 存储栈空间取出的元素的值
    DataType_t num = 0;
    // 判断栈空间是否为空
    if (-1 == sq_stack->Top){
        return -1;
    }
    num = sq_stack->data[sq_stack->Top];
    (sq_stack->Top)--;

    // 返回取出的元素
    return num;
}


// 遍历栈空间中的元素
void SqStack_Show(SqStack_t *sq_stack)
{
    // 判断栈空间是否为空
    if (-1 == sq_stack->Top){
        return ;
    }

    for (int i= 0; i <= sq_stack->Top; i++){
        printf("%d ", sq_stack->data[i]);
    }
    printf("\n");
}

// 销毁栈空间
void SqStack_Free(SqStack_t *sq_stack)
{
    free(sq_stack);
}
