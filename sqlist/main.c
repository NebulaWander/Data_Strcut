#include <stdio.h>
#include "sqlist.h"

int main()
{
    Sqlist *sqlist = NULL;
    StuInfo stu[] = { \
                        {"赵磊", 19, "男", "20140506"}, \
                        {"张伟", 23, "男", "20140507"}, \
                        {"刘梅", 22, "女", "20140508"}, \
                        {"柳琴", 22, "女", "20140509"}  \
                    };
    StuInfo stu2 = {"张雷", 30, "女", "20140510"};
    // 计算需要插入学生信息的个数                
    int num = sizeof(stu)/sizeof(stu[0]);

    // 创建顺序表
    sqlist = create_sq();
    // 判断顺序表是否创建成功
    if (sqlist == NULL){
        printf("error\n");
    }

    // 插入元素
    for(int i = 0; i < num; i++){
        insert_sq(sqlist, i, &stu[i]);
    }

    // 遍历顺序表中的元素
    show_sq(sqlist);

    printf("\n");
    // 查找顺序表中的元素
    find_sq(sqlist, "张伟");

    // 删除顺序表中的元素
    int ret = delete_sq(sqlist, "刘梅");
    if (ret == -1){
        printf("\nerror\n");
    }
    else if (ret == -2){
        printf("\nnot find !!!!!\n");
    }
    else{
        printf("\ndeleted the info !!!!!\n");
        // 遍历顺序表中的元素
        show_sq(sqlist);
    }
	
	printf("\n");
    // 查找顺序表中的元素
    find_sq(sqlist, "柳琴");

    int ret1 = change_sq(sqlist, "柳琴", stu2);
    if (ret1 == -1){
        printf("\nerror\n");
    }
    else if (ret1 == -2){
        printf("\nnot find !!!!!\n");
    }
    else{
        // 遍历顺序表中的元素
        show_sq(sqlist);
    }

    // 释放顺序表的内存空间
    destory_sq(sqlist);
    
    return 0;
}
