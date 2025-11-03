#ifndef _CIRCLLIST_H_
#define _CIRCLLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int Datatype_t;

typedef struct circllist{
    Datatype_t        data;     // 数据域
    struct circllist *next;     // 直接后继的指针域
}CircLList_t;

CircLList_t *CircLList_Create(void);
int CircLList_HeadInsert(CircLList_t *circllist, Datatype_t data);
int CircLList_TailInsert(CircLList_t *circllist, Datatype_t data);
int CircLList_OrderInsert(CircLList_t *circllist, Datatype_t data, int pos);
int CircLList_HeadDelete(CircLList_t *circllist);
int CircLList_TailDelete(CircLList_t *circllist);
int CircLList_OrderDelete(CircLList_t *circllist, int pos);
int CircLList_Find(CircLList_t *circllist, Datatype_t data);
int CircLList_Change(CircLList_t *circllist, Datatype_t data, Datatype_t changenum);
void CircLList_Show(CircLList_t *circllist);
void CircLList_Destory(CircLList_t *circllist);

#endif