#ifndef _SQCIRCQUEUE_h_
#define _SQCIRCQUEUE_h_

// 包含头文件
#include <stdio.h>
#include <stdlib.h>

// 宏定义队列的容量
#define MAXSIZE 10
// 重命名
typedef int DataType_t;

// 定义顺序循环队列结构体
typedef struct SqCircQueue{
    DataType_t data[MAXSIZE];   // 队列元素
    int        Front;           // 队首
    int        Real;            // 队尾
}SqCircQueue_t;

// 函数声明
SqCircQueue_t *SqCircQueue_Create();
int SqCircQueue_EnQueue(SqCircQueue_t *sqcircqueue, DataType_t *data);
int SqCircQueue_DeQueue(SqCircQueue_t *sqcircqueue, DataType_t *data);
void SqCircQueue_Show(SqCircQueue_t *sqcircqueue);
int SqCircQueue_IsEmpty(SqCircQueue_t *sqcircqueue);
int SqCircQueue_IsFull(SqCircQueue_t *sqcircqueue);
void SqCircQueue_Destroy(SqCircQueue_t *sqcircqueue);

#endif
