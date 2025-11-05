#ifndef _LLISTSTACK_H_
#define _LLISTSTACK_H_

#include <stdio.h>
#include <stdlib.h>

// 重定义
typedef int Data_t;

// 定义链表节点
typedef struct LinkedListStack{
    Data_t data;                        // 数据域
    struct LinkedListStack *next;       // 指针域
}LListStack_t;

LListStack_t *LListStack_Create();
int LListStack_Push(LListStack_t *llist_stack, Data_t data);
int LListStack_Pop(LListStack_t *llist_stack);
void LListStack_Show(LListStack_t *llist_stack);
void LListStack_Free(LListStack_t *llist_stack);

#endif