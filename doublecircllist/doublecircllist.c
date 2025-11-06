#include "doublecircllist.h"

// 创建一个双向循环链表的头结点
DoubleCircLList_t *DoubleCircLList_Create()
{
    DoubleCircLList_t *doublecircllist;
    // 申请内存空间
    doublecircllist = (DoubleCircLList_t *)calloc(1, sizeof(DoubleCircLList_t));
    // 错误判断
    if (NULL == doublecircllist){
        return NULL;
    }
    // 头结点的直接前驱的指针域和直接后继的指针域指向自身，形成“循环”
    doublecircllist->prev = doublecircllist;
    doublecircllist->next = doublecircllist;

    // 返回头结点地址
    return doublecircllist;
}

// 双向循环链表插入元素（头部）
int DoubleCircLList_HeadInsert(DoubleCircLList_t *doublecircllist, DataType_t data)
{
    // 保存头结点地址
    DoubleCircLList_t *doublecircllist1 = doublecircllist;

    // 创建新节点
    DoubleCircLList_t *newdoublecircllist;
    // 申请内存空间
    newdoublecircllist = (DoubleCircLList_t *)calloc(1, sizeof(DoubleCircLList_t));
    // 错误判断
    if (NULL == newdoublecircllist){
        return -1;
    }
    newdoublecircllist->prev = newdoublecircllist;
    newdoublecircllist->next = newdoublecircllist;

    // 双向循环链表为空
    if (doublecircllist1 == doublecircllist1->next){
        // 将头结点的next指针域指向新结点
        doublecircllist1->next = newdoublecircllist;
        // 插入元素
        newdoublecircllist->data = data;
    }
    else{
        // 双向循环链表非空
        while (doublecircllist1->next){
            // 依次后向移动
            doublecircllist1 = doublecircllist1->next;
            // 找到最后一个结点
            if (doublecircllist->next == doublecircllist1->next){
                // 将新结点的next指针域指向首结点
                newdoublecircllist->next = doublecircllist->next;
                // 将新结点的prev指针域指向尾结点
                newdoublecircllist->prev = doublecircllist1;
                // 将尾结点的next指针域指向新结点
                doublecircllist1->next = newdoublecircllist;
                // 将头结点的next指针域指向新结点
                doublecircllist->next = newdoublecircllist;
                // 插入元素
                newdoublecircllist->data = data;
                break;
            }
        }
    }

    return 0;
}

// 双向循环链表插入元素（尾部）
int DoubleCircLList_TailInsert(DoubleCircLList_t *doublecircllist, DataType_t data)
{
    // 保存头结点地址
    DoubleCircLList_t *doublecircllist1 = doublecircllist;

    // 创建新节点
    DoubleCircLList_t *newdoublecircllist;
    // 申请内存空间
    newdoublecircllist = (DoubleCircLList_t *)calloc(1, sizeof(DoubleCircLList_t));
    // 错误判断
    if (NULL == newdoublecircllist){
        return -1;
    }
    newdoublecircllist->prev = newdoublecircllist;
    newdoublecircllist->next = newdoublecircllist;

    // 双向循环链表为空
    if (doublecircllist1 == doublecircllist1->next){
        // 将头结点的next指针域指向新结点
        doublecircllist1->next = newdoublecircllist;
        // 插入元素
        newdoublecircllist->data = data;
    }
    else{
        // 双向循环链表非空
        while (doublecircllist1->next){
            // 依次后向移动
            doublecircllist1 = doublecircllist1->next;
            // 找到最后一个结点
            if (doublecircllist->next == doublecircllist1->next){
                // 将新结点的next指针域指向首结点
                newdoublecircllist->next = doublecircllist->next;
                // 将新结点的prev指针域指向尾结点
                newdoublecircllist->prev = doublecircllist1;
                // 将尾结点的next指针域指向新结点
                doublecircllist1->next = newdoublecircllist;
                // 将首结点的prev指针域指向新结点
                doublecircllist->next->prev = newdoublecircllist;
                // 插入元素
                newdoublecircllist->data = data;
                break;
            }
        }
    }

    return 0;
}

// 插入双向循环链表元素（指定位置）
int DoubleCircLList_OrderInsert(DoubleCircLList_t *doublecircllist, DataType_t data, int pos)
{
    int i = 0;
    DoubleCircLList_t *doublecircllist1 = doublecircllist;
    pos -= 1;

    // 创建新节点
    DoubleCircLList_t *newdoublecircllist;
    // 申请内存空间
    newdoublecircllist = (DoubleCircLList_t *)calloc(1, sizeof(DoubleCircLList_t));
    // 错误判断
    if (NULL == newdoublecircllist){
        return -1;
    }
    newdoublecircllist->prev = newdoublecircllist;
    newdoublecircllist->next = newdoublecircllist;

    // 双向循环链表为空
    if (doublecircllist1 == doublecircllist1->next){
        // 将头结点的next指针域指向新结点
        doublecircllist1->next = newdoublecircllist;
        // 插入元素
        newdoublecircllist->data = data;
    }
    else{
        // 双向循环链表非空
        while (doublecircllist1->next){
            // 结点依次向后移动，找到双向循环链表的指定位置
            doublecircllist1 = doublecircllist1->next;
            i++;
            // 找到双向循环链表中的最后一个结点
            if (doublecircllist->next == doublecircllist1->next){
                // 双向循环链表中的最后一个结点的指针域指向新节点的地址
                doublecircllist1->next = newdoublecircllist;
                // 新结点的prev指针域指向尾结点的地址
                newdoublecircllist->prev = doublecircllist1;  
                // 新结点的next指针域指向首结点的地址  
                newdoublecircllist->next = doublecircllist->next;
                // 插入元素
                newdoublecircllist->data = data;
                // 跳出循环
                break;
            }
            // 找到指定位置-（要删除结点的前一个结点）
            if (pos == i){            
                // 插入元素
                newdoublecircllist->data = data;
                // 将新结点的next指针域指向当前结点的下一个结点的地址
                newdoublecircllist->next = doublecircllist1->next;                
                // 将新结点的prev指针域指向当前结点的地址
                newdoublecircllist->prev = doublecircllist1;
                // 当前结点的下一个结点的prev指针域指向新结点的地址
                doublecircllist1->next->prev = newdoublecircllist;
                // 当前结点的指针域指向新结点的地址
                doublecircllist1->next = newdoublecircllist;
                break;
            }
        }   
    }

    return 0;
}

// 删除双向循环链表元素（头删）
int DoubleCircLList_HeadDelete(DoubleCircLList_t *doublecircllist)
{
    // 头节点地址
    DoubleCircLList_t *doublecircllist1 = doublecircllist;
    // 首结点地址
    DoubleCircLList_t *doublecircllist2 = doublecircllist->next;

    // 双向循环链表为空
    if (doublecircllist == doublecircllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return -1;
    }

    // 单向循环链表中只有首结点
    if (doublecircllist2 == doublecircllist2->next){
        // 将头节点指向自己
        doublecircllist->next = doublecircllist;        
        // 将首结点的prev指针域指向NULL
        doublecircllist2->prev = NULL;
        // 将首结点的next指针域指向NULL
        doublecircllist2->next = NULL;
        // 释放首结点地址
        free(doublecircllist2);
        doublecircllist2 = NULL;
    }
    else{
        while (doublecircllist1->next){
            // 依次向后移动结点
            doublecircllist1 = doublecircllist1->next;      // 更新为首结点地址
            // 找到最后一个结点
            if (doublecircllist->next == doublecircllist1->next){
                // 尾结点的next指针域指向首结点的下一个结点的地址
                doublecircllist1->next = doublecircllist2->next;
                // 头结点的next指针域指向首结点的下一个结点的地址
                doublecircllist->next = doublecircllist2->next;
                // 将首结点的next指针域指向NULL
                doublecircllist2->next = NULL;
                // 释放首结点的内存空间
                free(doublecircllist2);
                doublecircllist2 = NULL;
                // 跳出循环
                break;
            }
        }
    }

    return 0;
}

// 删除双向循环链表元素（尾删）
int DoubleCircLList_TailDelete(DoubleCircLList_t *doublecircllist)
{
    // 头节点地址
    DoubleCircLList_t *doublecircllist1 = doublecircllist;
    // 首结点地址
    DoubleCircLList_t *doublecircllist2 = doublecircllist->next;

    // 双向循环链表为空
    if (doublecircllist == doublecircllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return -1;
    }

    // 单向循环链表中只有首结点
    if (doublecircllist2 == doublecircllist2->next){
        // 将头节点指向自己
        doublecircllist->next = doublecircllist;        
        // 首结点的prev指针域指向NULL
        doublecircllist2->prev = NULL;
        // 首结点的next指针域指向NULL
        doublecircllist2->next = NULL;
        // 释放首结点地址
        free(doublecircllist2);
        doublecircllist2 = NULL;
    }
    else{
        while (doublecircllist1->next){
            // 依次向后移动结点
            doublecircllist1 = doublecircllist1->next;
            // 找到最后一个结点
            if (doublecircllist->next == doublecircllist1->next){
                // 尾结点的前一个结点的next指针域指向首结点地址
                doublecircllist1->prev->next = doublecircllist2;
                // 首结点的prev指针域指向尾结点的前一个结点的地址
                doublecircllist2->prev = doublecircllist1->prev;
                // 尾结点的prev指针域指向NULL
                doublecircllist1->prev = NULL;
                // 尾结点的next指针域指向NULL
                doublecircllist1->next = NULL;
                // 释放尾结点的内存空间
                free(doublecircllist1);
                doublecircllist1 = NULL;
                break;
            }
        }
    }

    return 0;
}

// 删除双向循环链表元素（指定位置删）
int DoubleCircLList_OrderDelete(DoubleCircLList_t *doublecircllist, int pos)
{
    int i = 0;
    // 头节点地址
    DoubleCircLList_t *doublecircllist1 = doublecircllist;
    // 首结点地址
    DoubleCircLList_t *doublecircllist2 = doublecircllist->next;
    DoubleCircLList_t *doublecircllist3 = NULL;
    pos -= 1;

    // 单向循环链表为空
    if (doublecircllist == doublecircllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return -1;
    }

    // 单向循环链表中只有首结点
    if (doublecircllist2 == doublecircllist2->next){
        // 将头节点指向自己
        doublecircllist->next = doublecircllist;        
        // 将首结点的prev指针域指向NULL
        doublecircllist2->prev = NULL;
        // 将首结点的next指针域指向NULL
        doublecircllist2->next = NULL;
        // 释放首结点地址
        free(doublecircllist2);
        doublecircllist2 = NULL;
    }
    else{
        while (doublecircllist1->next){
            // 依次向后移动结点
            doublecircllist1 = doublecircllist1->next;      // 更新为首结点地址
            // 找到最后一个结点
            if (doublecircllist->next == doublecircllist1->next){
                // 尾结点的前一个结点的next指针域指向首结点地址
                doublecircllist1->prev->next = doublecircllist2;
                // 首结点的prev指针域指向尾结点的前一个结点的地址
                doublecircllist2->prev = doublecircllist1->prev;
                // 尾结点的prev指针域指向NULL
                doublecircllist1->prev = NULL;
                // 尾结点的next指针域指向NULL
                doublecircllist1->next = NULL;
                // 释放尾结点的内存空间
                free(doublecircllist1);
                doublecircllist1 = NULL;
                break;
            }
            i++;
            // 找到指定位置-（要删除结点的前一个结点）
            if (pos == i){
                // 将指定删除的结点的地址保存在 circllist3
                doublecircllist3 = doublecircllist1->next;
                // 将当前结点的next指针域指向要删除的结点的下一个结点的地址
                doublecircllist1->next = doublecircllist3->next;
                // 将要删除结点的下一个结点的prev指针域指向的当前结点的地址
                doublecircllist3->next->prev = doublecircllist1;
                // 将要删除的结点的prev指针域指向NULL
                doublecircllist3->prev = NULL;
                // 将要删除的结点的next指针域指向NULL
                doublecircllist3->next = NULL;
                // 释放要删除的结点的内存空间
                free(doublecircllist3);
                doublecircllist3 = NULL;
                break;
            }
        }
    }

    return 0;
}

// 查找元素
int DoubleCircLList_Find(DoubleCircLList_t *doublecircllist, DataType_t data)
{
    int pos = 0;
    DoubleCircLList_t *doublecircllist1 = doublecircllist;

    // 单向循环链表为空
    if (doublecircllist == doublecircllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return 0;
    }

    while (doublecircllist1->next){
        // 依次向后移动一个结点
        doublecircllist1 = doublecircllist1->next;       
        // 找到该元素
        if (data == doublecircllist1->data){
            break;
        }
        // 找到最后一个结点没有找到该元素
        if (doublecircllist->next == doublecircllist1->next){
            perror("the element is not find!!!!!\n");
            break;
        }        
        // 计数器的值加1
        pos++; 
    }
    pos += 1;

    return pos;
} 

// 修改元素
int DoubleCircLList_Change(DoubleCircLList_t *doublecircllist, DataType_t data, DataType_t changenum)
{
     DoubleCircLList_t *doublecircllist1 = doublecircllist;

    // 单向循环链表为空
    if (doublecircllist == doublecircllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return 0;
    }

    while (doublecircllist1->next){
        // 依次向后移动一个结点
        doublecircllist1 = doublecircllist1->next;       
        // 找到该元素
        if (data == doublecircllist1->data){
            doublecircllist1->data = changenum;
            break;
        }
        // 找到最后一个结点没有找到该元素
        if (doublecircllist->next == doublecircllist1->next){
            perror("the element is not find!!!!!\n");
            break;
        }
    }

    return 0;
} 

// 遍历双向循环链表中的元素
void DoubleCircLList_Show(DoubleCircLList_t *doublecircllist)
{
    // 保存头结点地址
    DoubleCircLList_t *doublecircllist1 = doublecircllist;
    // 判断双向循环链表是否为空
    if (doublecircllist1 == doublecircllist1->next){
        return ;
    }    
    // 依次后向移动
    while (doublecircllist1->next){
        doublecircllist1 = doublecircllist1->next;
        printf("%d ", doublecircllist1->data);
        if (doublecircllist->next == doublecircllist1->next){
            break;
        }
    }

    printf("\n");
}

// 释放双向循环链表的内存空间
void DoubleCircLList_Free(DoubleCircLList_t *doublecircllist)
{
    DoubleCircLList_t *doublecircllist1 = NULL;
    DoubleCircLList_t *doublecircllist2 = NULL;

    for (doublecircllist1 = doublecircllist->next; doublecircllist->next != doublecircllist1; doublecircllist1 = doublecircllist2){
        // 依次向后移动
        doublecircllist1 = doublecircllist1->next;              // 第一次赋值的是首结点的下一个结点的地址
        // 将当前节点的下一个结点的地址保存在doublecircllist2
        doublecircllist2 = doublecircllist1->next;              // 首结点的下一个结点的下一个结点的地址
        //释放内存空间
        free(doublecircllist1);                                 // 是从首结点的下一个结点的地址开始释放内存空间
    }
    // 释放首结点的内存空间
    free(doublecircllist->next);
    // 释放头结点的内存空间
    free(doublecircllist);
    doublecircllist1 = NULL;
    doublecircllist2 = NULL;
}
