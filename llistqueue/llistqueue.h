#ifndef _LLISTQUEUE_H_
#define _LLISTQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

// 重定义
typedef int Data_t;

// 定义链表节点
typedef struct LinkedListQueue{
    Data_t data;                        // 数据域
    struct LinkedListQueue *next;       // 指针域
}LListQueue_t;

LListQueue_t *LListQueue_Create();
int LListQueue_EnQueue(LListQueue_t *llist_queue, Data_t data);
int LListQueue_DeQueue(LListQueue_t *llist_queue);
void LListQueue_Show(LListQueue_t *llist_queue);
void LListQueue_Free(LListQueue_t *llist_queue);

#endif