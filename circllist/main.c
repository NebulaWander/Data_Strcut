#include <stdio.h>
#include "circllist.h"

int main()
{
    CircLList_t *circllist;
    Datatype_t num[] = {1, 2, 3, 4, 5, 6};
    Datatype_t size  = ((sizeof(num)) / (sizeof(num[0])));

    // 创建单项循环链表的头结点
    circllist = CircLList_Create();
    if (NULL == circllist){
        printf("error!!!!!\n");
        printf("\n");
    }

    // 插入元素
    for (int i = 0; i < size; i++){
        if (0 != CircLList_TailInsert(circllist, num[i])){
            printf("error!!!!!\n");
            printf("\n");
        }            
    }
    
    // 遍历元素
    printf("单向循环链表的元素（尾插）：");
    CircLList_Show(circllist);
    printf("\n");

    // 头部插入元素
    int n = 0;
    CircLList_HeadInsert(circllist, n);
    // 遍历元素
    printf("头部单向循环链表元素：");
    CircLList_Show(circllist);
    printf("\n");

    // 尾部插入元素
    int m = 7;
    CircLList_TailInsert(circllist, m);
    // 遍历元素
    printf("尾部单向循环链表元素：");
    CircLList_Show(circllist);
    printf("\n");

    // 指定位置插入元素
    int a = 8;
    int pos1 = 9;
    CircLList_OrderInsert(circllist, a, pos1);
    // 遍历元素
    printf("指定位置[%d]插入单向循环链表元素：", pos1);
    CircLList_Show(circllist);
    printf("\n");    

    // 头部删除元素
    if (0 != CircLList_HeadDelete(circllist)){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        // 遍历元素
        printf("头部删除单向循环链表元素：");
        CircLList_Show(circllist);
        printf("\n");
    }
    
    // 尾部删除元素
    if (0 != CircLList_TailDelete(circllist)){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        // 遍历元素
        printf("尾部删除单向循环链表元素：");
        CircLList_Show(circllist);
        printf("\n");
    }

    // 指定位置删除元素
    int pos2 = 7;
    if (0 != CircLList_OrderDelete(circllist, pos2)){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        // 遍历元素
        printf("指定位置[%d]删除单向循环链表元素：", pos2);
        CircLList_Show(circllist);
        printf("\n");
    }

    // 查找元素
    int ele1 = 2;
    int ret = CircLList_Find(circllist, ele1);
    if (0 == ret){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        printf("查找元素[%d]在单向循环链表中的下标是：%d\n", ele1, ret);
        printf("\n");
    }

    // 修改元素
    int ele2 = 2;
    int ele3 = 3;
    if (0 != CircLList_Change(circllist, ele2, ele3)){
        printf("error!!!!!\n");
        printf("\n");
    }
    else{
        // 遍历元素
        printf("将链表元素[%d]修改为[%d]：", ele2, ele3);
        CircLList_Show(circllist);
        printf("\n");
    }

    // 销毁单向循环链表内存空间
    CircLList_Destory(circllist);

    return 0;
}
