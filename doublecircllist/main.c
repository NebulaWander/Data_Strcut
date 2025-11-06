#include <stdio.h>
#include "doublecircllist.h"

int main()
{
    DoubleCircLList_t *doublecircllist;
    DataType_t num[] = {1, 2, 3, 4, 5, 6};
    DataType_t size  = ((sizeof(num)) / (sizeof(num[0])));

    // 创建双向循环链表
    doublecircllist = DoubleCircLList_Create();
    // 错误判断
    if (NULL == doublecircllist){
        printf("error!!!!!\n");
    }

     // 插入元素
    for (int i = 0; i < size; i++){
        if (0 != DoubleCircLList_TailInsert(doublecircllist, num[i])){
            printf("error!!!!!\n");
            printf("\n");
        }            
    }
    // 遍历元素
    printf("双向循环链表的元素（尾插）：");
    DoubleCircLList_Show(doublecircllist);
    printf("\n");

    // 头部插入元素
    int n = 0;
    DoubleCircLList_HeadInsert(doublecircllist, n);
    // 遍历元素
    printf("头部双向循环链表元素：");
    DoubleCircLList_Show(doublecircllist);
    printf("\n");

    // 尾部插入元素
    int m = 7;
    DoubleCircLList_TailInsert(doublecircllist, m);
    // 遍历元素
    printf("尾部双向循环链表元素：");
    DoubleCircLList_Show(doublecircllist);
    printf("\n");

    
    // 指定位置插入元素
    int a = 8;
    int pos1 = 9;
    DoubleCircLList_OrderInsert(doublecircllist, a, pos1);
    // 遍历元素
    printf("指定位置[%d]插入双向循环链表元素：", pos1);
    DoubleCircLList_Show(doublecircllist);
    printf("\n");    
    
    // 头部删除元素
    if (0 != DoubleCircLList_HeadDelete(doublecircllist)){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        // 遍历元素
        printf("头部删除双向循环链表元素：");
        DoubleCircLList_Show(doublecircllist);
        printf("\n");
    }

    // 尾部删除元素
    if (0 != DoubleCircLList_TailDelete(doublecircllist)){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        // 遍历元素
        printf("尾部删除双向循环链表元素：");
        DoubleCircLList_Show(doublecircllist);
        printf("\n");
    }

    // 指定位置删除元素
    int pos2 = 7;
    if (0 != DoubleCircLList_OrderDelete(doublecircllist, pos2)){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        // 遍历元素
        printf("指定位置[%d]删除双向循环链表元素：", pos2);
        DoubleCircLList_Show(doublecircllist);
        printf("\n");
    }

    // 查找元素
    int ele1 = 2;
    int ret = DoubleCircLList_Find(doublecircllist, ele1);
    if (0 == ret){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        printf("查找元素[%d]在单向循环链表中的下标是：%d\n", ele1, ret);
        printf("\n");
    }

    // 修改元素
    int f_ele2 = 2;
    int c_ele3 = 3;
    DoubleCircLList_Change(doublecircllist, f_ele2, c_ele3);
    // 遍历元素
    printf("将链表元素[%d]修改为[%d]：", f_ele2, c_ele3);
    DoubleCircLList_Show(doublecircllist);
    printf("\n");

    // 释放双向循环链表的内存空间
    DoubleCircLList_Free(doublecircllist);

    return 0;
}
