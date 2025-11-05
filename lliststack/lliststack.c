#include "lliststack.h"

// 创建一个头节点
LListStack_t *LListStack_Create()
{
    // 定义一个链表头节点结构体变量
    LListStack_t *llist_stack = NULL;
    // 申请内存空间
    llist_stack = (LListStack_t *)calloc(1, sizeof(LListStack_t));
    // 错误判断
    if (NULL == llist_stack){
        return NULL;
    }
    // 将头节点的指针域指向NULL
    llist_stack->next = NULL;
    // 返回头节点地址
    return llist_stack;
}

// 入栈-栈空间放入元素（头部）
int LListStack_Push(LListStack_t *llist_stack, Data_t data)
{
    LListStack_t *llist_stack1 = llist_stack;
    LListStack_t *llist_stack2 = NULL;
    // 创建一个链表节点（存储数据和下一个节点的地址）
    llist_stack2 = calloc(1, sizeof(LListStack_t));
    if (NULL == llist_stack2){
        return -1;
    }      
    // 放入元素
    llist_stack2->data = data;  
    // 连接链表的节点    
    llist_stack2->next = llist_stack1->next;
    llist_stack1->next = llist_stack2;

    return 0;
}

// 出栈-栈空间取出元素（头部）
int LListStack_Pop(LListStack_t *llist_stack)
{
    LListStack_t *llist_stack1 = llist_stack->next;
    // 判断链表是否为空
    if (NULL == llist_stack1){
        return -1;
    }   

    // 头节点指向首结点的下一个节点
    llist_stack->next = llist_stack1->next;
    free(llist_stack1);
    llist_stack1 = NULL;

    return 0;
}

// 遍历栈空间中的元素
void LListStack_Show(LListStack_t *llist_stack)
{
    // 将头结点的地址保存在llist1中
    LListStack_t *llist_stack1 = llist_stack;
    // 判断链表是否为空
    if (NULL == llist_stack1->next){
        return ;
    }
    // 依次向后移动一位遍历链表元素
    while (NULL != llist_stack1->next){
        llist_stack1 = llist_stack1->next;
        printf("%d ", llist_stack1->data);
    }
    printf("\n");
}

// 销毁栈空间
void LListStack_Free(LListStack_t *llist_stack)
{
    LListStack_t *llist_stack1 = NULL;
    LListStack_t *llist_stack2 = NULL;
    for (llist_stack1 = llist_stack->next; NULL != llist_stack1; llist_stack1 = llist_stack2){
        // 保存当前节点指向的下一个结点的地址
        llist_stack2 = llist_stack1->next;
        // 释放当前节点内存空间（llist1中保存的地址的内存空间）
        free(llist_stack1);
    }
    // 释放链表中的头节点
    free(llist_stack);
}
