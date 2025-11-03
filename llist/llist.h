#ifndef _LLIST_H_
#define _LLIST_H_

// 重定义
typedef int Data_t;

// 包含头文件
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct LinkedList{
    Data_t data;                // 数据域
    struct LinkedList *next;    // 指针域
}LList_t;

// 函数声明
LList_t *Create_LinkedList();
int Insert_LinkedListHead(LList_t *llist, Data_t data);
int Insert_LinkedListTail(LList_t *llist, Data_t data);
int Insert_LinkedListOrder(LList_t *llist, Data_t pos, Data_t data);
int Delete_LinkedListHead(LList_t *llist);
int Delete_LinkedListTail(LList_t *llist);
int Delete_LinkedListOrder(LList_t *llist, Data_t pos);
int Find_LinkedList(LList_t *llist, Data_t data);
int Change_LinkedList(LList_t *llist, Data_t data, Data_t changenum);
void Show_LinkedList(LList_t *llist);
void Destory_LinkedList(LList_t *llist);

#endif