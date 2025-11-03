#include "llist.h"

// 创建一个头节点
LList_t *Create_LinkedList()
{
    // 定义一个链表头节点结构体变量
    LList_t *llist = NULL;
    // 申请内存空间
    llist = (LList_t *)calloc(1, sizeof(LList_t));
    // 错误判断
    if (NULL == llist){
        return NULL;
    }
    // 将头节点的指针域指向NULL
    llist->next = NULL;
    // 返回头节点地址
    return llist;
}

// 插入链表元素（头部）
int Insert_LinkedListHead(LList_t *llist, Data_t data)
{
    LList_t *llist1 = llist;
    LList_t *llist2 = NULL;
    // 创建一个链表节点（存储数据和下一个节点的地址）
    llist2 = calloc(1, sizeof(LList_t));
    if (NULL == llist2){
        return -1;
    }      
    // 放入元素
    llist2->data = data;  
    // 连接链表的节点    
    llist2->next = llist1->next;
    llist1->next = llist2;
    return 0;
}

// 插入链表元素（尾部）
int Insert_LinkedListTail(LList_t *llist, Data_t data)
{
    LList_t *llist1 = llist;
    LList_t *llist2 = NULL;
    // 如果链表中已经有元素，就后移一位，移动最后一个节点
    while (NULL != llist1->next){
        // 指向下一个节点
        llist1 = llist1->next;
    }
    // 创建一个链表节点，最为最后一个节点并存储数据
    llist2 = calloc(1, sizeof(LList_t));  
    if (NULL == llist2){
        return -1;
    }  
    // 放入元素
    llist2->data = data;  
    // 连接链表的节点
    llist1->next = llist2;    
    llist2->next = NULL;

    return 0;
}

// 插入链表元素（指定位置）
int Insert_LinkedListOrder(LList_t *llist, Data_t pos, Data_t data)
{
    int i = 0;
    LList_t *llist1 = llist;
    LList_t *llist2 = NULL;
    if (pos < 0){
        perror("插入链表的位置 < 0!!!!!!\n");
        return -1;
    }
    pos -= 1;
    // 如果链表中已经有元素，并且还没有到插入的位置，就后移一位，直到移动到插入元素的节点位置
    while (NULL != llist1->next && i < pos){
        // 指向下一个节点
        llist1 = llist1->next;
        // 当跳出循环时，llist1 就指向了链表中需要插入元素pos的位置
        i++;
    }
    // 创建一个链表节点，最为最后一个节点并存储数据
    llist2 = calloc(1, sizeof(LList_t));  
    if (NULL == llist2){
        return -2;
    }  
    // 放入元素
    llist2->data = data;  
    // 连接链表的节点    
    llist2->next = llist1->next;
    llist1->next = llist2;

    return 0;
}

// 删除链表元素（头部）
int Delete_LinkedListHead(LList_t *llist)
{
    LList_t *llist1 = llist->next;
    // 判断链表是否为空
    if (NULL == llist1)
    {
        return -1;
    }   

    // 头节点指向首结点的下一个节点
    llist->next = llist1->next;
    free(llist1);
    llist1 = NULL;

    return 0;
}

// 删除链表元素（尾部）
int Delete_LinkedListTail(LList_t *llist)
{
    LList_t *llist1 = llist;
    // 判断链表是否为空
    if (NULL == llist->next)
    {
        return -1;
    }   
    // 遍历链表元素，找到最后一个节点
    while (NULL != llist1->next->next){
        // 循环结束时，llist1 指向的是最后一个节点的前一个节点指向的地址
        llist1 = llist1->next;
    }
    free(llist1->next->next);
    // 将最后一个节点的前一个节点指向的地址置为NULL
    llist1->next = NULL;

    return 0;
}

// 删除链表元素（指定位置）
int Delete_LinkedListOrder(LList_t *llist, Data_t pos)
{
    int i = 0;
    LList_t *llist1 = llist;
    LList_t *llist2 = NULL;
    // 判断链表是否为空
    if (NULL == llist->next)
    {
        return -1;
    }
    pos -= 1;   
    // 如果链表中已经有元素，并且还没有到插入的位置，就后移一位，直到移动到需要删除的节点的前一个位置
    while (NULL != llist1->next && i < pos){
        // 指向下一个节点
        llist1 = llist1->next;
        // 当跳出循环时，llist1 就指向了需要删除的节点的前一个节点的地址
        i++;
    }
    // 保存要删除的元素的地址
    llist2 = llist1->next;
    // 将当前结点指向要删除的节点的下一个结点的地址
    llist1->next = llist2->next;
    // 释放要删除的元素的内存空间
    free(llist2);

    return 0;
}

// 查找链表中的元素
int Find_LinkedList(LList_t *llist, Data_t data)
{
    int pos = 0;
    LList_t *llist1 = llist;
    // 判断链表是否为空
    if (NULL == llist->next){
        return -1;
    }
    while ((NULL != llist1->next) && (llist1->next->data != data)){
        // 依次向后移动一个节点
        llist1 = llist1->next;
        // 元素所在的节点的下标加1
        pos++;
    }
    // 按照用户习惯，输出的下标的值应该是加1的
    pos += 1;
    // 查找的元素存在，返回下标
    return pos;
}

// 修改链表中的元素
int Change_LinkedList(LList_t *llist, Data_t data, Data_t changenum)
{
    LList_t *llist1 = llist;
    // 判断链表是否为空
    if (NULL == llist->next){
        return -1;
    }
    while ((NULL != llist1->next) && (llist1->next->data != data)){
        // 依次向后移动一个节点
        // 跳出循环表示已经找到该元素
        // llist1 指向的是需要修改的元素所在节点的前一个节点的地址
        llist1 = llist1->next;
    }
    // 将需要修改的数值赋值给节点的数据域
    llist1->next->data = changenum;

    return 0;
}

// 遍历链表的元素
void Show_LinkedList(LList_t *llist)
{
    // 将头结点的地址保存在llist1中
    LList_t *llist1 = llist;
    // 判断链表是否为空
    if (NULL == llist1->next){
        return ;
    }
    // 依次向后移动一位遍历链表元素
    while (NULL != llist1->next){
        // 让当前结点指向下一个节点的地址
        // 进入下一次循环时该结点就变为下一个节点
        // 也就是下一次循环时该结点充当的是头节点
        // 依次向后移动直到链表中的最后一个节点
        llist1 = llist1->next;
        printf("%d ", llist1->data);
    }
    printf("\n");
}

// 销毁链表元素
void Destory_LinkedList(LList_t *llist)
{
    LList_t *llist1 = NULL;
    LList_t *llist2 = NULL;
    for (llist1 = llist->next; NULL != llist1; llist1 = llist2){
        // 保存当前节点指向的下一个结点的地址
        llist2 = llist1->next;
        // 释放当前节点内存空间（llist1中保存的地址的内存空间）
        free(llist1);
    }
    // 释放链表中的头节点
    free(llist);
}

