#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "data.h"


int main(void) {
    int option,son_option;
	menu:
	printf("***********************************\n");
    printf("*     简易资产信息管理系统        *\n");
    printf("*作者：李家乐  学号：2422040318   *\n");
    printf("*e-mail：2422040318@hhu.edu.cn    *\n");
    printf("***********************************\n");
	printf("***********************************\n");
	printf("*            主 菜 单             *\n");
	printf("*        1.输入 资产信息          *\n");
	printf("*        2.修改 资产信息          *\n");
	printf("*        3.计算 资产信息          *\n");
	printf("*        4.排序 资产信息          *\n");
	printf("*        5.查询 资产信息          *\n");
	printf("*        6.统计 资产信息          *\n");
	printf("*        7.输出 资产信息          *\n");
	printf("*        0.退出 资产信息          *\n");
	printf("***********************************\n");
	printf("请输入功能选项：");
	
	
	if (scanf("%d", &option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return 1; // 表示错误
	}
	system("cls");  //清除屏幕,美观

    // 初始化物资链表，创建一个头结点
    struct asset_node* asset_list = (struct asset_node*)malloc(sizeof(struct asset_node));
    if (asset_list == NULL) {
        printf("内存分配失败。\n");
        return 1; // 错误
    }
    asset_list->next = NULL;

	switch (option) {
		//*		1.输入 资产信息          *
	case 1:
		printf("***********************************\n");
		printf("*          输 入 子 菜 单         *\n");
		printf("*           1.从键盘录入          *\n");
		printf("*           2.从文件导入          *\n");
		printf("***********************************\n");
		printf("请输入功能选项：");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}
		if (son_option == 1) {
			printf("\n");
			for (;;) {
				add_asset(asset_list); //添加资产信息
				getchar(); //吸收回车
				printf("是否继续添加？(y/n)");
				char c;
				scanf("%c", &c);
				if (c == 'n') {
					break;
				}
			}
			//input_from_keyboard();
			goto menu; //回到主菜单

		}
		else if (son_option == 2) {
			;
			break;
		}
		break;
		//*		2.修改 资产信息          *
	case 2:
		printf("***********************************\n");
		printf("*          修 改 子 菜 单         *\n");
		printf("*           1.添加                *\n");
		printf("*           2.删除                *\n");
		printf("*           3.修改                *\n");
		printf("***********************************\n");
		break;
		//*		3.计算 资产信息          *
	case 3:
		printf("***********************************\n");
		printf("*         计 算 子 菜 单          *\n");
		printf("*         1.计算资产总价值        *\n");
		printf("*         2.计算资产平均价值      *\n");
		printf("***********************************\n");
		break;
		//*		4.排序 资产信息          *
	case 4:
		printf("***********************************\n");
		printf("*         排 序 子 菜 单          *\n");
		printf("*         1.按购置年份排序        *\n");
		printf("*         2.按购置价格升序排列    *\n");
		printf("*         3.按购置价格降序排列    *\n");
		printf("***********************************\n");
		break;
		//*		5.查询 资产信息          *
	case 5:
		printf("***********************************\n");
		printf("*         查 询 子 菜 单          *\n");
		printf("*         1.按资产编号查询        *\n");
		printf("*         2.按资产名称查询        *\n");
		printf("***********************************\n");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}

		break;
	case 6:   //无子菜单，直接输出结果
		;
		break;
	case 7:
		printf("***********************************\n");
		printf("*         输 出 子 菜 单          *\n");
		printf("*         1.输出到屏幕            *\n");
		printf("*         2.输出到文件            *\n");
		printf("***********************************\n");

		break;
	case 0:
		printf("退出资产信息\n");
		break;
	default:
		printf("输入错误\n");
		break;
	}
	return 0;
}