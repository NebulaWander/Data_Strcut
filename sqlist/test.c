#include <stdio.h>
#include "sqlist.h"

void MenuInfo()
{
    printf("****************************\n");
    printf("*        1.创建链表        *\n");
    printf("****************************\n");
    printf("*        2.插入元素        *\n");
    printf("****************************\n");
    printf("*        3.打印元素        *\n");
    printf("****************************\n");
    printf("*        4.删除元素        *\n");
    printf("****************************\n");
    printf("*        5.修改元素        *\n");
    printf("****************************\n");
    printf("*        6.查找元素        *\n");
    printf("****************************\n");    
    printf("*        7.注销链表        *\n");
    printf("****************************\n");
    printf("input the number：");
}


int main()
{
    int num = 0;
    Sqlist *sq_list = NULL;

    while (1){
        // 提示用户菜单信息
        MenuInfo();
        // 接受用户输入指令
        scanf("%d", &num);
        // 进入与用户指令相应的程序
        switch(num)
        {
            case 1:
            {
                sq_list = create_sq();
                if (sq_list == NULL){
                    printf("error\n");
                }
                else{                    
                    printf("链表创建成功!!!!!\n");
                }
            }
            break;

            case 2:
            {
                int num = 0;

                StuInfo stu[] = { \
                                    {"赵磊", 19, "男", "20140506"}, \
                                    {"张伟", 23, "男", "20140507"}, \
                                    {"刘梅", 22, "女", "20140508"}, \
                                    {"柳琴", 22, "女", "20140509"}  \
                                };
                num = sizeof(stu)/sizeof(stu[0]);

                // 插入元素
                for(int i = 0; i < num; i++){
                    if(insert_sq(sq_list, i, &stu[i]) != 0){
                        printf("error\n");
                        break;
                    }
                    else{
                        printf("链表元素插入成功!!!!!\n");
                    }
                }
            }
            break;

            case 3:
            {
                // 遍历顺序表中的元素
                show_sq(sq_list);
            }
            break;

            case 4:
            {
                int ret = delete_sq(sq_list, "刘梅");

                if (ret == -1){
                    printf("error\n");
                }
                else if (ret == -2){
                    printf("not find !!!!!\n");
                }
                else{
                    printf("deleted the info !!!!!\n");
                }
            }
            break;

            case 5:
            {
                StuInfo stu2 = {"张雷", 30, "女", "20140510"};
                int ret1 = change_sq(sq_list, "柳琴", stu2);

                if (ret1 == -1){
                    printf("\nerror\n");
                }
                else if (ret1 == -2){
                    printf("\nnot find !!!!!\n");
                }
            }
            break;

            case 6:
            { 
                // 查找顺序表中的元素
                find_sq(sq_list, "张伟");
            }
            break;
            
            case 7:
            {
                // 释放顺序表的内存空间
                destory_sq(sq_list);
            }
            break;

            default:
                printf("请重新输入指令!!!!!\n");
        }

        printf("continue or stop(y/n)：");
        scanf("%d", &num);
        if (num == 0){
            break;
        }
        
        // 清屏
        system("clear");
    }
    return 0;
}
