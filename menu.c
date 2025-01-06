#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "data.h"

int sub_menu_1(int current_option) {
	int new_option;
	printf("***********************************\n");
	printf("*          输 入 子 菜 单         *\n");
	printf("*           1.从键盘录入          *\n");
	printf("*           2.从文件导入          *\n");
	printf("***********************************\n");
	printf("请输入功能选项：");
	if (scanf("%d", &new_option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return current_option; // 返回当前选项，避免错误
	}
	return new_option;
}   //输入

int sub_menu_2(int current_option) {
	printf("***********************************\n");
	printf("*          修 改 子 菜 单         *\n");
	printf("*           1.添加                *\n");
	printf("*           2.删除                *\n");
	printf("*           3.修改                *\n");
	printf("***********************************\n");
	printf("请输入功能选项：");
	if (scanf("%d", &current_option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return current_option; // 错误
	}
	return current_option;
}  //修改
int sub_menu_3(int current_option) {
	printf("***********************************\n");
	printf("*         计 算 子 菜 单          *\n");
	printf("*         1.计算资产总价值        *\n");
	printf("*         2.计算资产平均价值      *\n");
	printf("***********************************\n");
	printf("请输入功能选项：");
	if (scanf("%d", &current_option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return current_option; // 错误
	}
	return current_option;
}

int sub_menu_4(int current_option) {
	printf("***********************************\n");
	printf("*         排 序 子 菜 单          *\n");
	printf("*         1.按购置年份排序        *\n");
	printf("*         2.按购置价格升序排列    *\n");
	printf("*         3.按购置价格降序排列    *\n");
	printf("***********************************\n");
	printf("请输入功能选项：");
	if (scanf("%d", &current_option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return current_option; // 错误
	}
	return current_option;
}

int sub_menu_5(int current_option) {
	printf("***********************************\n");
	printf("*         查 询 子 菜 单          *\n");
	printf("*         1.按资产编号查询        *\n");
	printf("*         2.按资产名称查询        *\n");
	printf("***********************************\n");
	printf("请输入子选项：");
	if (scanf("%d", &current_option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return current_option; // 错误
	}
	return current_option;
}

int sub_menu_6(int current_option) {
	printf("***********************************\n");
	printf("*         统 计 子 菜 单          *\n");
	printf("*         1.按学院统计            *\n");
	printf("*         2.按购买年份统计        *\n");
	printf("*         3.统计各年份购买量占比  *\n");
	printf("***********************************\n");
	printf("请输入子选项：");
	if (scanf("%d", &current_option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return current_option; // 错误
	}
	return current_option;
}

int sub_menu_7(int current_option) {
	printf("***********************************\n");
	printf("*         输 出 子 菜 单          *\n");
	printf("*         1.输出到屏幕            *\n");
	printf("*         2.输出到文件            *\n");
	printf("***********************************\n");
	printf("请输入子选项：");
	if (scanf("%d", &current_option) != 1) {
		printf("输入错误，请输入一个有效的数字。\n");
		return current_option; // 错误
	}
	return current_option;
}