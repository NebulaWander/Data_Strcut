#ifndef _SQSTACK_H_
#define _SQSTACK_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef int DataType_t;

typedef struct SqStack{
    DataType_t data[SIZE];
    int Top;                // 栈顶元素的下标
}SqStack_t;

SqStack_t *SqSatck_Create(void);
int SqStack_Push(SqStack_t *sq_stack, DataType_t *data);
int SqStack_Pop(SqStack_t *sq_stack);
void SqStack_Show(SqStack_t *sq_stack);
void SqStack_Free(SqStack_t *sq_stack);

#endif