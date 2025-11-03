#include <stdio.h>
#include "doublellist.h"

int main()
{
    DoubleLList_t *doublellist;
    DataType_t num[] = {1, 2, 3, 4, 5, 6};
    DataType_t size  = ((sizeof(num)) / (sizeof(num[0])));

    // 创建双向链表
    doublellist = DoubleLList_Create();
    // 错误判断
    if (NULL == doublellist){
        printf("error!!!!!\n");
    }

    // 插入元素
    for (int i = 0; i < size; i++){
        if (0 != DoubleLList_TailInsert(doublellist, num[i])){
            printf("error!!!!!\n");
            printf("\n");
        }            
    }
    // 遍历元素
    printf("双向链表的元素（尾插）：");
    DoubleLList_Show(doublellist);
    printf("\n");

    // 头部插入元素
    int data1 = 0;
    DoubleLList_HeadInsert(doublellist, data1);
    // 遍历元素
    printf("头部插入元素双向链表：");
    DoubleLList_Show(doublellist);
    printf("\n");

    // 尾部插入元素
    int data2 = 7;
    DoubleLList_TailInsert(doublellist, data2);
    // 遍历元素
    printf("尾部插入元素双向链表：");
    DoubleLList_Show(doublellist);
    printf("\n");

    // 指定位置插入元素
    int pos1  = 9;
    int data3 = 8;
    DoubleLList_OrderInsert(doublellist, data3, pos1);
    // 遍历元素
    printf("指定位置[%d]插入元素[%d]：", pos1, data3);
    DoubleLList_Show(doublellist);
    printf("\n");

    // 头部删除元素
    DoubleLList_HeadDelete(doublellist);
    // 遍历元素
    printf("头部删除元素双向链表：");
    DoubleLList_Show(doublellist);
    printf("\n");

    // 尾部删除元素
    DoubleLList_TailDelete(doublellist);
    // 遍历元素
    printf("尾部删除元素双向链表：");
    DoubleLList_Show(doublellist);
    printf("\n");

    // 指定位置删除元素
    int pos2 = 7;
    DoubleLList_OrderDelete(doublellist, pos2);
    // 遍历元素
    printf("指定位置[%d]删除元素：", pos2);
    DoubleLList_Show(doublellist);
    printf("\n");

    // 查找元素
    int data4 = 2;
    int pos3  = 0;
    pos3 = DoubleLList_Find(doublellist, data4);
    if (0 == pos3){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        printf("查找元素[%d]的下标是：%d\n", data4, pos3);
        printf("\n");
    }

    // 修改元素
    int data5 = 2;
    int data6 = 9;
    int ret  = 0;
    ret = DoubleLList_Change(doublellist, data5, data6);
    if (0 != ret){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        printf("元素[%d]修改为[%d]双向链表：", data5, data6);
        DoubleLList_Show(doublellist);
        printf("\n");
    }

    // 释放双向链表的内存空间
    Destory_LinkedList(doublellist);

    return 0;
}
