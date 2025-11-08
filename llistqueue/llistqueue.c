#include "llistqueue.h"

// 创建链式队列
LListQueue_t *LListQueue_Create()
{
    // 定义一个链表头节点结构体变量
    LListQueue_t *llist_queue = NULL;
    // 申请内存空间
    llist_queue = (LListQueue_t *)calloc(1, sizeof(LListQueue_t));
    // 错误判断
    if (NULL == llist_queue){
        return NULL;
    }
    // 将头节点的指针域指向NULL
    llist_queue->next = NULL;
    // 返回头节点地址
    return llist_queue;
}

// 入队（尾插）
int LListQueue_EnQueue(LListQueue_t *llist_queue, Data_t data)
{
    LListQueue_t *llist_queue1 = llist_queue;
    LListQueue_t *llist_queue2 = NULL;

    // 创建一个链表节点（存储数据和下一个节点的地址）
    llist_queue2 = calloc(1, sizeof(LListQueue_t));
    if (NULL == llist_queue2){
        return -1;
    }   
    // 放入元素
    llist_queue2->data = data; 

    // 依次向后移动直到找到尾部   
    while (NULL != llist_queue1->next){
        llist_queue1 = llist_queue1->next;
    }

    // 将尾结点的next指针域指向新结点的地址
    llist_queue1->next = llist_queue2;
    // 将新结点的next指针域指向NULL   
    llist_queue2->next = NULL;

    return 0;
}

// 出队（头删）
int LListQueue_DeQueue(LListQueue_t *llist_queue)
{
    // 存储出队的元素
    int temp = 0;
    // 头节点地址
    LListQueue_t *llist_queue1 = llist_queue->next;

    // 判断链表是否为空
    if (NULL == llist_queue1){
        return -1;
    }   

    //保存出队元素
    temp = llist_queue1->data;
    // 头节点指向首结点的下一个节点
    llist_queue->next = llist_queue1->next;
    free(llist_queue1);
    llist_queue1 = NULL;

    // 将出队的元素返回
    return temp;
}

// 遍历元素
void LListQueue_Show(LListQueue_t *llist_queue)
{
    // 将头结点的地址保存在llist1中
    LListQueue_t *llist_queue1 = llist_queue;
    // 判断链表是否为空
    if (NULL == llist_queue1->next){
        return ;
    }
    // 依次向后移动一位遍历链表元素
    while (NULL != llist_queue1->next){
        llist_queue1 = llist_queue1->next;
        printf("%d ", llist_queue1->data);
    }
    printf("\n");
}

// 释放内存空间
void LListQueue_Free(LListQueue_t *llist_queue)
{
    LListQueue_t *llist_queue1 = NULL;
    LListQueue_t *llist_queue2 = NULL;
    for (llist_queue1 = llist_queue->next; NULL != llist_queue1; llist_queue1 = llist_queue2){
        // 保存当前节点指向的下一个结点的地址
        llist_queue2 = llist_queue1->next;
        // 释放当前节点内存空间（llist1中保存的地址的内存空间）
        free(llist_queue1);
    }
    // 释放链表中的头节点
    free(llist_queue);
}