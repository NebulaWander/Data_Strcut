#include "circllist.h"

// 创建单向循环链表
CircLList_t *CircLList_Create(void)
{
    CircLList_t *circllist = NULL;
    // 申请内存空间
    circllist = (CircLList_t *)calloc(1, sizeof(CircLList_t));
    // 错误信息处理
    if (NULL == circllist){
        return NULL;
    }
    // 头结点的指针域指向自己
    circllist->next = circllist;
    // 返回头结点地址
    return circllist;
}

// 插入单向循环链表元素（头插）
int CircLList_HeadInsert(CircLList_t *circllist, Datatype_t data)
{
    CircLList_t *circllist1 = circllist;

    // 创建新结点
    CircLList_t *newcircllist = NULL;
    newcircllist = (CircLList_t *)calloc(1, sizeof(CircLList_t));
    if (NULL == newcircllist)
    {
        return -1;
    }
    newcircllist->next = NULL;    

    // 单向循环链表为空
    if (circllist->next == circllist){
        // 插入元素
        circllist->next    = newcircllist;
        newcircllist->next = newcircllist;
        newcircllist->data = data;
    }

    // 单向循环链表非空
    // 找到单向循环链表的最后一个结点
    while (circllist1->next){
        // 结点依次向后移动
        circllist1 = circllist1->next;
        // 找到单向循环链表中的最后一个结点
        if (circllist->next == circllist1->next){
            //插入元素
            newcircllist->data = data;  
            // 新结点的指针域指向首结点的地址  
            newcircllist->next = circllist->next;
            // 单向循环链表中的最后一个结点的指针域指向新节点的地址
            circllist1->next = newcircllist;
            // 头结点指向新节点的地址
            circllist->next = newcircllist;
            // 跳出循环
            break;
        }
    }    

    return 0;
}

// 插入单向循环链表元素（尾插）
int CircLList_TailInsert(CircLList_t *circllist, Datatype_t data)
{
    CircLList_t *circllist1 = circllist;

    // 创建新结点
    CircLList_t *newcircllist = NULL;
    newcircllist = (CircLList_t *)calloc(1, sizeof(CircLList_t));
    if (NULL == newcircllist)
    {
        return -1;
    }
    newcircllist->next = NULL;    

    // 单向循环链表为空
    if (circllist->next == circllist){
        // 插入元素
        circllist->next    = newcircllist;
        newcircllist->next = newcircllist;
        newcircllist->data = data;
    }

    // 单向循环链表非空
    // 找到单向循环链表的最后一个结点
    while (circllist1->next){
        // 结点依次向后移动
        circllist1 = circllist1->next;
        // 找到单向循环链表中的最后一个结点
        if (circllist->next == circllist1->next){
            // 单向循环链表中的最后一个结点的指针域指向新节点的地址
            circllist1->next = newcircllist;
            //插入元素
            newcircllist->data = data;  
            // 新结点的指针域指向首结点的地址  
            newcircllist->next = circllist->next;
            // 跳出循环
            break;
        }
    }

    return 0;
}

// 插入单向循环链表元素（指定位置）
int CircLList_OrderInsert(CircLList_t *circllist, Datatype_t data, int pos)
{
    int i = 0;
    CircLList_t *circllist1 = circllist;
    pos -= 1;

    // 创建新结点
    CircLList_t *newcircllist = NULL;
    newcircllist = (CircLList_t *)calloc(1, sizeof(CircLList_t));
    if (NULL == newcircllist)
    {
        return -1;
    }
    newcircllist->next = NULL;    

    // 单向循环链表为空
    if (circllist->next == circllist){
        // 插入元素
        circllist->next    = newcircllist;
        newcircllist->next = newcircllist;
        newcircllist->data = data;
    }

    // 单向循环链表非空
    // 找到单向循环链表的指定位置
    while (circllist1->next){
        // 结点依次向后移动
        circllist1 = circllist1->next;
        i++;
        // 找到单向循环链表中的最后一个结点
        if (circllist->next == circllist1->next){
            // 单向循环链表中的最后一个结点的指针域指向新节点的地址
            circllist1->next = newcircllist;
            //插入元素
            newcircllist->data = data;  
            // 新结点的指针域指向首结点的地址  
            newcircllist->next = circllist->next;
            // 跳出循环
            break;
        }
        // 找到指定位置（前一个结点）
        if (pos == i){            
            // 插入元素
            newcircllist->data = data;
            // 将新结点的指针域指向当前结点的下一个结点的地址
            newcircllist->next = circllist1->next;
            // 当前结点的指针域指向新结点的地址
            circllist1->next = newcircllist;
            break;
        }
    }   

    return 0;
}

// 删除单向循环链表元素（头删）
int CircLList_HeadDelete(CircLList_t *circllist)
{
    // 头节点地址
    CircLList_t *circllist1 = circllist;
    // 首结点地址
    CircLList_t *circllist2 = circllist->next;

    // 单向循环链表为空
    if (circllist == circllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return -1;
    }

    // 单向循环链表中只有首结点
    if (circllist2 == circllist2->next){
        circllist2->next = NULL;
        // 将头节点指向自己
        circllist->next = circllist;
        // 释放首结点地址
        free(circllist2);
        circllist2 = NULL;
    }

    while (circllist1->next){
        // 依次向后移动结点
        circllist1 = circllist1->next;      // 更新为首结点地址
        // 找到最后一个结点
        if (circllist->next == circllist1->next){
            // 最后一个结点的指针域指向首结点的下一个结点的地址
            circllist1->next = circllist2->next;
            // 头结点的指针域指向首结点的下一个结点的地址
            circllist->next = circllist2->next;
            // 将首结点的指针域执行NULL
            circllist2->next = NULL;
            // 释放首结点的内存空间
            free(circllist2);
            circllist2 = NULL;
            // 跳出循环
            break;
        }
    }

    return 0;
}

// 删除单向循环链表元素（尾删）
int CircLList_TailDelete(CircLList_t *circllist)
{
    // 头节点地址
    CircLList_t *circllist1 = circllist;
    // 首结点地址
    CircLList_t *circllist2 = circllist->next;
    CircLList_t *circllist3 = NULL;

    // 单向循环链表为空
    if (circllist == circllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return -1;
    }

    // 单向循环链表中只有首结点
    if (circllist2 == circllist2->next){
        circllist2->next = NULL;
        // 将头节点指向自己
        circllist->next = circllist;
        // 释放首结点地址
        free(circllist2);
        circllist2 = NULL;
    }


    while (circllist1->next){
        // 找到最后一个结点的前一个结点
        if (circllist->next == circllist1->next->next){
            // 将最后一个节点的地址保存在 circllist2
            circllist3 = circllist1->next;
            // 最后一个结点的前一个结点的指针域指向首结点的地址
            circllist1->next = circllist->next;
            // 将最后一个结点的指针域执行NULL
            circllist3->next = NULL;
            // 释放最后一个结点的内存空间
            free(circllist3);
            circllist3 = NULL;
            // 跳出循环
            break;
        }
        // 依次向后移动结点
        circllist1 = circllist1->next;      // 更新为首结点地址
    }

    return 0;
}

// 删除单向循环链表元素（指定位置删）
int CircLList_OrderDelete(CircLList_t *circllist, int pos)
{
    int i = 0;
    // 头节点地址
    CircLList_t *circllist1 = circllist;
    // 首结点地址
    CircLList_t *circllist2 = circllist->next;
    CircLList_t *circllist3 = NULL;
    pos -= 1;

    // 单向循环链表为空
    if (circllist == circllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return -1;
    }

    // 单向循环链表中只有首结点
    if (circllist2 == circllist2->next){
        circllist2->next = NULL;
        // 将头节点指向自己
        circllist->next = circllist;
        // 释放首结点地址
        free(circllist2);
        circllist2 = NULL;
    }

    while (circllist1->next){
        // 找到最后一个结点的前一个结点
        if (circllist->next == circllist1->next->next){
            // 将最后一个节点的地址保存在 circllist2
            circllist3 = circllist1->next;
            // 最后一个结点的前一个结点的指针域指向首结点的地址
            circllist1->next = circllist->next;
            // 将最后一个结点的指针域执行NULL
            circllist3->next = NULL;
            // 释放最后一个结点的内存空间
            free(circllist3);
            circllist3 = NULL;
            // 跳出循环
            break;
        }
        // 依次向后移动结点
        circllist1 = circllist1->next;      // 更新为首结点地址
        i++;
        // 找到当前结点的前一个结点
        if (pos == i){
            // 将指定删除的结点的地址保存在 circllist3
            circllist3 = circllist1->next;
            // 将当前结点的指针域指向要删除的结点的下一个结点的地址
            circllist1->next = circllist3->next;
            circllist3->next = NULL;
            // 释放要删除的结点的内存空间
            free(circllist3);
            circllist3 = NULL;
            break;
        }
    }

    return 0;
}

// 查找元素
int CircLList_Find(CircLList_t *circllist, Datatype_t data)
{
    int pos = 0;
    CircLList_t *circllist1 = circllist;

    // 单向循环链表为空
    if (circllist == circllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return 0;
    }

    while (circllist1->next){
        // 依次向后移动一个结点
        circllist1 = circllist1->next;       
        // 找到该元素
        if (data == circllist1->data){
            break;
        }
        // 找到最后一个结点没有找到该元素
        if (circllist->next == circllist1->next){
            perror("the element is not find!!!!!\n");
            break;
        }        
        // 计数器的值加1
        pos++; 
    }
    pos += 1;

    return pos;
} 

// 查找元素
int CircLList_Change(CircLList_t *circllist, Datatype_t data, Datatype_t changenum)
{
    CircLList_t *circllist1 = circllist;

    // 单向循环链表为空
    if (circllist == circllist->next){
        perror("the circular linkedlist is empty!!!!!\n");
        return -1;
    }

    while (circllist1->next){
        // 依次向后移动一个结点
        circllist1 = circllist1->next;       
        // 找到该元素
        if (data == circllist1->data){
            circllist1->data = changenum;
            break;
        }
        // 找到最后一个结点没有找到该元素
        if (circllist->next == circllist1->next){
            perror("the element is not find!!!!!\n");
            break;
        }
    }

    return 0;
} 

void CircLList_Show(CircLList_t *circllist)
{
    CircLList_t *circllist1 = circllist;

    // 单向循环链表为空
    if (circllist->next == circllist){
        return ;
    }

    while (circllist1->next){
        // 结点依次向后移动
        circllist1 = circllist1->next;
        // 遍历单项循环链表元素
        printf("%d ", circllist1->data);
        // 遍历到单向循环链表中的最后一个结点
        if (circllist1->next == circllist->next){
            break;
        }
    }

    printf("\n");
}

// 释放单向循环链表的内存空间
void CircLList_Destory(CircLList_t *circllist)
{
    CircLList_t *circllist1 = NULL;
    CircLList_t *circllist2 = NULL;

    // 依次向后移动一个结点
    // 初始化 circllist1 指向首结点的地址
    for (circllist1 = circllist->next; circllist->next != circllist1; circllist1 = circllist2){
        // 从第二个结点开始释放内存空间（防止找不到最后一个结点，造成死循环）
        circllist1 = circllist1->next;      // 指向第二个结点
        // 将第二个结点的指针域指向的地址保存在 circllist2
        circllist2 = circllist1->next;      // 指向第三个结点
        // 释放当前结点的内存空间
        free(circllist1);
    }
    // 释放首节点的内存空间
    free(circllist->next);
    // 释放头节点的内存空间
    free(circllist);
}

