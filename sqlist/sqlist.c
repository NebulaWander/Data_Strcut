#include "sqlist.h"

// 创建顺序表
Sqlist *create_sq(void)
{
    Sqlist *sq_list = (Sqlist *)malloc(sizeof(Sqlist));
    if (sq_list == NULL){
        return NULL;
    }
    sq_list->count = 0;
    return sq_list;
}

// 顺序表插入元素
int insert_sq(Sqlist *sq_list,int i, StuInfo *data)
{
    // 顺序表已满
    if (sq_list->count == (MAXSIZE + 1)){
        return -1;
    }
    // 判断插入位置是否合法
    if (i < 0 || i > (sq_list->count+1)){
        return -2;
    }
	
    for (int j = (sq_list->count); i <= j; j-- ){
        sq_list->stuinfo[j+1] = sq_list->stuinfo[j];
    }
	
    sq_list->stuinfo[i] = *data;
    (sq_list->count)++;

    return 0;
}

// 删除顺序表中的元素
int delete_sq(Sqlist *sq_list, char *name)
{
    if (name == NULL || sq_list == NULL || sq_list->count == 0){                    //判断是否是空链表
        return -1;
    }

    for (int i = 0; i < sq_list->count; i++){
        // strcmp 函数：比较两个字符串是否相同（相同为0）
        if (strcmp(sq_list->stuinfo[i].name, name) == 0){
            // 找到该元素
            // 如果是最后一个元素，则不需还要进行处理
            for (int j = i; j < (sq_list->count)-1; j++){
                // 将 *name 之后的元素有一次向前移动一位
                sq_list->stuinfo[j] = sq_list->stuinfo[j + 1];
            }             
    
            // 顺序表中存储的元素个数-1
            (sq_list->count)--;
            return 0;            
        }
    }
    // 没有找到元素
    return -2;  
}

// 遍历顺序元素
void show_sq(Sqlist * sq_list)                 //打印链表
{
	if (sq_list->count == 0){                    //判断是否是空链表
        return ;
    }	

	for (int i = 0; i < (sq_list->count); i++){
        printf("%s\t%d\t%s\t%s\n", sq_list->stuinfo[i].name, \
                                sq_list->stuinfo[i].age,  \
                                sq_list->stuinfo[i].sex,  \
                                sq_list->stuinfo[i].id    \
              );
    }		

	return ;
}

// 查找顺序表中的元素
void find_sq(Sqlist *sq_list, char *name)
{
    if (name == NULL || sq_list == NULL || sq_list->count == 0){                    //判断是否是空链表
        return ;
    }

    for (int i = 0; i < sq_list->count; i++){
        // strcmp 函数：比较两个字符串是否相同（相同为0）
        if (strcmp(sq_list->stuinfo[i].name, name) == 0){
            // 找到该元素
            printf("%s 是第 %d 个 !!!!!\n", sq_list->stuinfo[i].name, i+1);
            return ;
        }
    }

    printf("not find %s !!!!!\n", name);
}

// 替换顺序表中的元素
int change_sq(Sqlist *sq_list, char *name, StuInfo data)
{
    if (name == NULL || sq_list == NULL || sq_list->count == 0){                    //判断是否是空链表
        return -1;
    }

    for (int i = 0; i < sq_list->count; i++){
        // strcmp 函数：比较两个字符串是否相同（相同为0）
        if (strcmp(sq_list->stuinfo[i].name, name) == 0){
            // 找到该元素            
            sq_list->stuinfo[i] = data;
	        printf("\nchanged the %s to %s\n", name, data.name);
            return 0;
        }
    }

    return -2;
}

// 销毁顺序表
void destory_sq(Sqlist *sq_list)
{
    // 顺序表中的元素个数清零
    sq_list->count = 0;
    // 释放内存空间
    free(sq_list);
}
