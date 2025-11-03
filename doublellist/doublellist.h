#ifndef _DOUBLELLIST_H_
#define _DOUBLELLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType_t;

// 定义一个双向链表结点结构体
typedef struct doublellist{
    DataType_t          data;    // 数据域
    struct doublellist *prev;    // 直接前驱的指针域
    struct doublellist *next;    // 直接后继的指针域
}DoubleLList_t;

DoubleLList_t *DoubleLList_Create(void);
int DoubleLList_HeadInsert(DoubleLList_t *doublellist, DataType_t data);
int DoubleLList_TailInsert(DoubleLList_t *doublellist, DataType_t data);
int DoubleLList_OrderInsert(DoubleLList_t *doublellist, DataType_t data, int pos);
int DoubleLList_HeadDelete(DoubleLList_t *doublellist);
int DoubleLList_TailDelete(DoubleLList_t *doublellist);
int DoubleLList_OrderDelete(DoubleLList_t *doublellist, int pos);
int DoubleLList_Find(DoubleLList_t *doublellist, DataType_t data);
int DoubleLList_Change(DoubleLList_t *doublellist, DataType_t data, DataType_t changenum);
void DoubleLList_Show(DoubleLList_t *doublellist);
void Destory_LinkedList(DoubleLList_t *doublellist);

#endif
