#include <stdio.h>
#include "llist.h"

int main()
{
    LList_t *llist = NULL;
    Data_t num[] = {1, 2, 3, 4, 5};
    Data_t size = ((sizeof(num)) / (sizeof(num[0]))); 

    // 创建链表
    llist = Create_LinkedList();
    if (NULL == llist){
        printf("链表创建失败!!!!!\n");
    }

    // 插入元素(尾插)
    for (int i = 0; i < size; i++){    
        if (0 != Insert_LinkedListTail(llist, num[i])){
            printf("链表元素插入失败!!!!!\n");
        }
    }
    printf("链表的元素为（尾插）：");
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");

    Insert_LinkedListHead(llist, 0);
    printf("头部插入链表元素：");
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");

    Insert_LinkedListTail(llist, 6);
    printf("尾部插入链表元素：");
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");

    int n = 8;
    Insert_LinkedListOrder(llist, n, 7);
    printf("指定位置[%d]插入链表元素：", n);
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");

    // 删除链表的头元素
    if (Delete_LinkedListHead(llist) != 0)
    {
        printf("Error!!!!!\n");
    }
    printf("头部删除链表元素：");
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");

    // 删除链表的尾元素
    if (Delete_LinkedListTail(llist) != 0)
    {
        printf("Error!!!!!\n");
    }
    printf("尾部删除链表元素：");
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");
    
    int m = 4;
    // 删除链表的指定元素
    if (Delete_LinkedListOrder(llist, m) != 0)
    {
        printf("Error!!!!!\n");
    }
    printf("指定位置[%d]删除链表元素：", m);
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");

    // 查找链表元素
    printf("查找的元素[%d]的下标为：%d\n", 2, Find_LinkedList(llist, 2));
    printf("\n");

    int a = 2;
    int b = 3;
    // 修改链表元素
    if (Change_LinkedList(llist, a, b) != 0)
    {
        printf("Error!!!!!\n");
    }
    printf("将链表元素[%d]修改为[%d]：", a, b);
    // 遍历链表元素
    Show_LinkedList(llist);
    printf("\n");

    // 销毁链表
    Destory_LinkedList(llist);

    return 0;
}