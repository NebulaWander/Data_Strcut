#ifndef _SQLIST_H_
#define _SQLIST_H_

// 包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 100

// 定义一个学生信息类型的数据类型
typedef struct Student{
    char name[32];      // 姓名
    int  age;           // 年龄
    char sex[10];       // 性别
    char id[18];        // 学号
}StuInfo;

// 定义一个顺序表
typedef struct Sqlist{
	StuInfo stuinfo[MAXSIZE];
    int count;          // 数据个数
}Sqlist;


Sqlist *create_sq(void);
int insert_sq(Sqlist *sq_list,int i, StuInfo *data);
int delete_sq(Sqlist *sq_list, char *name);
void show_sq(Sqlist * list);
void find_sq(Sqlist *sq_list, char *name);
int change_sq(Sqlist *sq_list, char *name, StuInfo data);
void destory_sq(Sqlist *sq_list);

#endif
