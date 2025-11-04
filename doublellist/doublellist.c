#include "doublellist.h"

DoubleLList_t *DoubleLList_Create(void)
{
    DoubleLList_t *doublellist;
    // 申请内存空间
    doublellist = (DoubleLList_t *)calloc(1, sizeof(DoubleLList_t));
    // 错误判断
    if (NULL == doublellist){
        return NULL;
    }
    // 内存空间申请成功，将头结点的直接前驱的指针域和直接后继的指针域指向NULL
    doublellist->prev = NULL;
    doublellist->next = NULL;
    // 返回头结点的地址
    return doublellist;
}

// 插入元素（头部）
int DoubleLList_HeadInsert(DoubleLList_t *doublellist, DataType_t data)
{
    DoubleLList_t *doublellist1 = doublellist;

    // 创建一个新结点
    DoubleLList_t *newdoublellist;
    // 申请内存空间
    newdoublellist = (DoubleLList_t *)calloc(1, sizeof(DoubleLList_t));
    // 错误判断
    if (NULL == newdoublellist){
        return -1;
    }
    // 内存空间申请成功，将头结点的直接前驱的指针域和直接后继的指针域指向NULL
    newdoublellist->prev = NULL;
    newdoublellist->next = NULL;

    // 判断双向链表为空
    if (NULL == doublellist->next){
        // 插入元素
        newdoublellist->data = data;
        // 头节点的直接后继的指针域指向新结点的地址
        doublellist->next = newdoublellist;
        // 新结点的直接前驱的指针域不指向头结点的地址，而是指向NULL
        //newdoublellist->prev = NULL;
        // 新结点的直接后继的指针域指向NULL
        //newdoublellist->next = NULL;
    }    
    else{
        // 插入元素
        newdoublellist->data = data;
        // 将新结点连接到双向链表
        newdoublellist->next = doublellist1->next;
        // 新结点的直接前驱的指针域不指向头结点的地址，而是指向NULL
        //newdoublellist->prev = NULL;
        // 断开头节点和首结点之间的连接
        doublellist1->next->prev = newdoublellist->next;
        doublellist1->next = newdoublellist;
    }
    return 0;
}

// 插入元素（尾部）
int DoubleLList_TailInsert(DoubleLList_t *doublellist, DataType_t data)
{
    DoubleLList_t *doublellist1 = doublellist;

    // 创建一个新结点
    DoubleLList_t *newdoublellist;
    // 申请内存空间
    newdoublellist = (DoubleLList_t *)calloc(1, sizeof(DoubleLList_t));
    // 错误判断
    if (NULL == newdoublellist){
        return -1;
    }
    // 内存空间申请成功，将头结点的直接前驱的指针域和直接后继的指针域指向NULL
    newdoublellist->prev = NULL;
    newdoublellist->next = NULL;

    // 依次向后移动找到最后一个节点
    while (NULL != doublellist1->next)
    {
        // 找到最后一个结点跳出循环
        doublellist1 = doublellist1->next;
    }

    // 判断双向链表为空
    if (NULL == doublellist->next){
        // 插入元素
        newdoublellist->data = data;
        // 头节点的直接后继的指针域指向新结点的地址
        doublellist->next = newdoublellist;
        // 新结点的直接前驱的指针域不指向头结点的地址，而是指向NULL
        //newdoublellist->prev = NULL;
        // 新结点的直接后继的指针域指向NULL
        //newdoublellist->next = NULL;
        return 0;
    }    
    else{
        // 插入元素
        newdoublellist->data = data;
        // 将新结点连接到尾结点的后面
        // 将最后一个节点的指针域指向新结点的地址
        doublellist1->next = newdoublellist;
        // 将新节点的直接前驱的指针域指向最后一个结点的地址
        newdoublellist->prev = doublellist1;
        // 新结点的直接后继的指针域指向NULL
        //newdoublellist->next = NULL;
    }
    return 0;
}

// 插入元素（指定位置）
int DoubleLList_OrderInsert(DoubleLList_t *doublellist, DataType_t data, int pos)
{
    int i = 0;
    DoubleLList_t *doublellist1 = doublellist;
    pos -= 1;

    // 创建一个新结点
    DoubleLList_t *newdoublellist;
    // 申请内存空间
    newdoublellist = (DoubleLList_t *)calloc(1, sizeof(DoubleLList_t));
    // 错误判断
    if (NULL == newdoublellist){
        return -1;
    }
    // 内存空间申请成功，将头结点的直接前驱的指针域和直接后继的指针域指向NULL
    newdoublellist->prev = NULL;
    newdoublellist->next = NULL;    

    // 依次向后移动找到指定位置节点的前一个结点
    while (NULL != doublellist1->next && i < pos)
    {
        // 找到最后一个结点跳出循环
        doublellist1 = doublellist1->next;
        // 计数器的值加1
        i++;
    }

    // 判断双向链表为空
    if (NULL == doublellist->next){
        // 插入元素
        newdoublellist->data = data;
        // 头节点的直接后继的指针域指向新结点的地址
        doublellist->next = newdoublellist;
    }    
    // 找到的是最后一节点
    else if (NULL == doublellist1->next){
        // 插入元素
        newdoublellist->data = data;
        // 将新结点连接到尾结点的后面
        // 将最后一个节点的指针域指向新结点的地址
        doublellist1->next = newdoublellist;
        // 将新节点的直接前驱的指针域指向最后一个结点的地址
        newdoublellist->prev = doublellist1;
    }
    else{
        // 插入元素
        newdoublellist->data = data;
        // 先连接
        // 将新结点的直接前驱的指针域指向指定位置结点前一个结点的地址
        newdoublellist->prev = doublellist1;
        // 将新结点的直接后继的指针域指向指定位置结点的地址
        newdoublellist->next = doublellist1->next;
        // 在断开
        // 将指定位置节点的直接前驱的指针域指向新结点的地址
        doublellist1->next->prev = newdoublellist;
        // 将指定位置节点前一个结点的指针域指向新结点的地址
        doublellist1->next = newdoublellist;
    }    

    return 0;
}

// 删除元素（头部）
int DoubleLList_HeadDelete(DoubleLList_t *doublellist)
{
    // 头节点地址
    DoubleLList_t *doublellist1 = doublellist;
    // 首结点地址
    DoubleLList_t *doublellist2 = doublellist->next;
    
    // 判断双向链表为空
    if (NULL == doublellist1->next){
        perror("the double linked list is empty!!!!!\n");
        return -1;
    }    

    // 双向链表中只有一个首结点
    if (NULL == doublellist2->next){
        // 将头结点的直接后继的指针域指向NULL
        doublellist1->next = NULL;
        // 释放首结点的内存空间
        free(doublellist2);
        doublellist2 = NULL;
    } 
    else{
        // 删除元素
        // 将头结点的直接后继的指针域指向首结点的下一个结点的地址
        doublellist1->next = doublellist2->next;
        // 将首结点的下一个节点的直接后继的指针域指向NULL
        doublellist2->next->prev = NULL;
        // 将首结点的直接后继的指针域指向NULL
        doublellist2->next = NULL;
        // 释放首结点的内存空间
        free(doublellist2);
        doublellist2 = NULL;
    }

    return 0;
}

// 删除元素（尾部）
int DoubleLList_TailDelete(DoubleLList_t *doublellist)
{
    // 头节点地址
    DoubleLList_t *doublellist1 = doublellist;
    // 首结点地址
    DoubleLList_t *doublellist2 = doublellist->next;
    DoubleLList_t *doublellist3 = NULL;
    
    // 判断双向链表为空
    if (NULL == doublellist1->next){
        perror("the double linked list is empty!!!!!\n");
        return -1;
    }   

    // 依次向后移动找到最后一个节点
    while (NULL != doublellist1->next)
    {
        // 找到最后一个结点的前一个结点跳出循环
        doublellist1 = doublellist1->next;
    }

    // 双向链表中只有一个首结点
    if (NULL == doublellist2->next){
        // 将头结点的直接后继的指针域指向NULL
        doublellist1->next = NULL;
        // 释放首结点的内存空间
        free(doublellist2);
        doublellist2 = NULL;
    } 
    else{
        // 删除元素
        // 将尾结点的地址保存在 doublellist3
        doublellist3 = doublellist1;
        // 将尾结点的前一个节点的直接后继的指针域指向NULL
        doublellist3->prev->next = NULL;
        // 尾结点的直接前驱的指针域指向NULL
        doublellist3->prev = NULL;
        // 释放尾结点的内存空间
        free(doublellist3);
        doublellist3 = NULL;
    }

    return 0;
}

// 删除元素（指定位置）
int DoubleLList_OrderDelete(DoubleLList_t *doublellist, int pos)
{
    int i = 0;
    // 头节点地址
    DoubleLList_t *doublellist1 = doublellist;
    // 首结点地址
    DoubleLList_t *doublellist2 = doublellist->next;
    DoubleLList_t *doublellist3 = NULL;
    pos -= 1;
    
    // 判断双向链表为空
    if (NULL == doublellist1->next){
        perror("the double linked list is empty!!!!!\n");
        return -1;
    }    

     

    // 依次向后移动找到指定位置节点
    while (NULL != doublellist1->next && i <= pos)
    {
        // 找到最后一个结点或者找到指定位置结点跳出循环
        doublellist1 = doublellist1->next;
        // 计数器的值加1
        i++;
    }

    // 双向链表中只有一个首结点
    if (NULL == doublellist2->next){
        // 将头结点的直接后继的指针域指向NULL
        doublellist1->next = NULL;
        // 释放首结点的内存空间
        free(doublellist2);
        doublellist2 = NULL;
    }
    // 找到的是最后一个结点
    else if (NULL == doublellist1->next){
        // 删除元素
        // 将尾结点的地址保存在 doublellist3
        doublellist3 = doublellist1;
        // 将尾结点的前一个节点的直接后继的指针域指向NULL
        doublellist3->prev->next = NULL;
        // 尾结点的直接前驱的指针域指向NULL
        doublellist3->prev = NULL;
        // 释放尾结点的内存空间
        free(doublellist3);
        doublellist3 = NULL;
    }
    else{
        // 删除元素
        // 将指定位置结点的地址保存在 doublellist3
        doublellist3 = doublellist1->next;
        // 将指定位置结点的下一个节点的直接前驱的指针域指向指定位置结点的前一个节点的地址
        doublellist3->next->prev = doublellist1;
        // 将指定位置结点的前一个节点的直接后继的指针域指向指定位置结点的下一个节点的地址
        doublellist1->next = doublellist3->next; 
        // 将指定位置结点的直接前驱的指针域指向NULL
        doublellist3->prev = NULL;
        // 将指定位置结点的直接后继的指针域指向NULL
        doublellist3->next = NULL;
        // 释放当前节点的内存空间
        free(doublellist3);
        doublellist3 = NULL;
    }

    return 0;    
}

// 查找元素
int DoubleLList_Find(DoubleLList_t *doublellist, DataType_t data)
{
    int pos = 0;
    // 头节点地址
    DoubleLList_t *doublellist1 = doublellist;
    
    // 判断双向链表为空
    if (NULL == doublellist1->next){
        perror("the double linked list is empty!!!!!\n");
        return 0;
    }    

    // 依次向后移动找到指定位置节点
    while (NULL != doublellist1->next)
    {
        // 找到最后一个结点或者找到指定位置结点跳出循环
        doublellist1 = doublellist1->next;
        // 判断数据是否相等
        if (data == doublellist1->data)
        {
            break;
        }
        // 下标加1
        pos++;
    }
    pos += 1;
   
    return pos;    
}

// 修改元素
int DoubleLList_Change(DoubleLList_t *doublellist, DataType_t data, DataType_t changenum)
{
    // 头节点地址
    DoubleLList_t *doublellist1 = doublellist;
    
    // 判断双向链表为空
    if (NULL == doublellist1->next){
        perror("the double linked list is empty!!!!!\n");
        return -1;
    }    

    // 依次向后移动找到指定位置节点
    while (NULL != doublellist1->next)
    {
        // 找到最后一个结点或者找到指定位置结点跳出循环
        doublellist1 = doublellist1->next;
        // 判断数据是否相等
        if (data == doublellist1->data)
        {
            // 修改元素
            doublellist1->data = changenum;
            break;
        }
    }
   
    return 0;    
}


// 遍历链表的元素
void DoubleLList_Show(DoubleLList_t *doublellist)
{
    // 将头结点的地址保存在doublellist1中
    DoubleLList_t *doublellist1 = doublellist;
    // 判断链表是否为空
    if (NULL == doublellist1->next){
        return ;
    }
    // 依次向后移动一位遍历链表元素
    while (NULL != doublellist1->next){
        // 依次向后移动节点
        doublellist1 = doublellist1->next;
        printf("%d ", doublellist1->data);
    }
    printf("\n");
}

// 销毁双向链表
void Destory_LinkedList(DoubleLList_t *doublellist)
{
    // 首节点地址
    DoubleLList_t *doublellist1 = doublellist;
    DoubleLList_t *doublellist2 = NULL;

    for (doublellist1 = doublellist1->next; NULL != doublellist1; doublellist1 = doublellist2){
        // 保存当前节点指向的下一个结点的地址
        doublellist2 = doublellist1->next;
        // 将当前节点的直接前驱的指针域指向NULL
        doublellist1->prev = NULL;
        // 将当前节点的直接后继的指针域指向NULL
        doublellist1->next = NULL;
        // 释放当前节点内存空间（doublellist1中保存的地址的内存空间）
        free(doublellist1);
    }
    // 释放链表中的头节点
    free(doublellist);
}
