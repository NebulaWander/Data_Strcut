#ifndef _DOUBLECIRLINKEDLIST_H_
#define _DOUBLECIRLINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType_t;

typedef struct DoubleCircLList{
    DataType_t data;
    struct DoubleCircLList *prev;   // 直接前驱的指针域
    struct DoubleCircLList *next;   // 直接后继的指针域
}DoubleCircLList_t;

DoubleCircLList_t *DoubleCircLList_Create();
int DoubleCircLList_HeadInsert(DoubleCircLList_t *doublecircllist, DataType_t data);
int DoubleCircLList_TailInsert(DoubleCircLList_t *doublecircllist, DataType_t data);
int DoubleCircLList_OrderInsert(DoubleCircLList_t *doublecircllist, DataType_t data, int pos);
int DoubleCircLList_HeadDelete(DoubleCircLList_t *doublecircllist);
int DoubleCircLList_TailDelete(DoubleCircLList_t *doublecircllist);
int DoubleCircLList_OrderDelete(DoubleCircLList_t *doublecircllist, int pos);
int DoubleCircLList_Find(DoubleCircLList_t *doublecircllist, DataType_t data);
int DoubleCircLList_Change(DoubleCircLList_t *doublecircllist, DataType_t data, DataType_t changenum);
void DoubleCircLList_Show(DoubleCircLList_t *doublecircllist);
void DoubleCircLList_Free(DoubleCircLList_t *doublecircllist);

#endif