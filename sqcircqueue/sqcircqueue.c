#include "sqcircqueue.h"

// 创建顺序循环队列
SqCircQueue_t *SqCircQueue_Create()
{
    SqCircQueue_t *sqcircqueue;
    // 申请内存空间
    sqcircqueue = (SqCircQueue_t *)calloc(1, sizeof(SqCircQueue_t));
    // 错误判断
    if (NULL == sqcircqueue){
        return NULL;
    }

    // 将队首和队尾都初始化为0
    sqcircqueue->Front = 0;
    sqcircqueue->Real  = 0;

    // 返回队列的地址
    return sqcircqueue;
}

// 入队 - 队尾移动（先放入元素再移动队尾）
int SqCircQueue_EnQueue(SqCircQueue_t *sqcircqueue, DataType_t *data)
{
    // 判断顺序循环队列是否已满
    if (SqCircQueue_IsFull(sqcircqueue)){
        return -1;
    }

    // 放入元素
    sqcircqueue->data[sqcircqueue->Real] = *data;
    // 移动队尾（需要防止队尾超出顺序循环队列的最大容量）
    sqcircqueue->Real = ((sqcircqueue->Real + 1) % MAXSIZE);

    return 0;
}

// 出队 - 队首移动
int SqCircQueue_DeQueue(SqCircQueue_t *sqcircqueue, DataType_t *data)
{
    // 判断顺序循环队列是否为空
    if (SqCircQueue_IsEmpty(sqcircqueue)){
        return -1;
    }

    // 移动首（需要防止队尾超出顺序循环队列的最大容量）
    sqcircqueue->Front = ((sqcircqueue->Front + 1) % MAXSIZE);
    *data = sqcircqueue->data[sqcircqueue->Front];

    // 返回出队的元素
    return 0;
}

// 遍历顺序循环队列的元素
void SqCircQueue_Show(SqCircQueue_t *sqcircqueue)
{
    // 存储顺序循环队列的队首下标
    int temp = 0;
    // 判断顺序循环队列是否为空
    if (SqCircQueue_IsEmpty(sqcircqueue)){
        return ;
    }

    // 将队首的下标赋值给temp
    temp = sqcircqueue->Front;

    // 判断是否遍历到队尾
    // 由于是先放入元素再移动队尾，此时 sqcircqueue->Real 的值是（真实的队尾下标+1）
    while (temp < sqcircqueue->Real){
        printf("%d ", sqcircqueue->data[temp]);
        // 更新temp变量的值，向队尾移动
        temp = ((temp + 1) % MAXSIZE);
    }

    printf("\n");
}

// 判断顺序循环队列为空
int SqCircQueue_IsEmpty(SqCircQueue_t *sqcircqueue)
{
    // 判断顺序循环队列为空的条件：队首 == 队尾
    // 为空，返回1
    // 不空，返回0
    return (sqcircqueue->Front == sqcircqueue->Real ? 1 : 0);
}

// 判断顺序循环队列已满
int SqCircQueue_IsFull(SqCircQueue_t *sqcircqueue)
{
    // 判断顺序循环队列已满的条件：(队尾 + 1) % 队列容量 == 队首
    // 已满，返回1
    // 不满，返回0
    // 顺序循环队列的最后一个容量不放数据
    return (sqcircqueue->Front == ((sqcircqueue->Real + 1) % MAXSIZE) ? 1 : 0);
}

// 释放顺序循环队列的内存空间
void SqCircQueue_Destroy(SqCircQueue_t *sqcircqueue)
{
    free(sqcircqueue);
}
