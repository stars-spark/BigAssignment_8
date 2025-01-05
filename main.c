#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "data.h"

int option, son_option, grandson_option; // 全局变量

int main() {
	struct asset_node* asset_list = (struct asset_node*)malloc(sizeof(struct asset_node));
	if (asset_list == NULL) {
		printf("内存分配失败。\n");
		return 1; // 错误
	}
	//不会再出现乱码了老天爷
	asset_list->data.asset_id = 0;
	asset_list->data.asset_name[0] = '\0';
	asset_list->data.asset_type = 0;
	asset_list->data.school[0] = '\0';
	asset_list->data.purchase_year = 0;
	asset_list->data.price = 0.0;
	asset_list->data.recipient_name[0] = '\0';
	asset_list->data.phone_number = 0;
	asset_list->next = NULL;

menu: //标签
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
				asset_list = add_asset(asset_list); //添加资产信息
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
			asset_list = read_from_file(asset_list);
			if (asset_list == NULL) {
				printf("文件读取失败。\n");
			}
			else {
				printf("文件读取成功。\n");
			}
			goto menu;
		}
		break;
		//*		2.修改 资产信息          *
	case 2:
		printf("***********************************\n");
		printf("*          修 改 子 菜 单         *\n");
		printf("*           1.添加                *\n");
		printf("*           2.删除                *\n");
		printf("***********************************\n");
		printf("请输入功能选项：");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}
		switch (son_option) {
		case 1:
			for (;;) {
				asset_list = add_asset(asset_list); //添加资产信息
				getchar(); //吸收回车
				printf("是否继续添加？(y/n)");
				char c;
				scanf("%c", &c);
				if (c == 'n') {
					break;
				}
			}
			goto menu;
			break;
		case 2:
			printf("***********************************\n");
			printf("*          删 除 子 菜 单         *\n");
			printf("*           1.搜索ID              *\n");
			printf("*           2.搜索名称            *\n");
			printf("***********************************\n");
			printf("请输入功能选项：");
			if (scanf("%d", &grandson_option) != 1) {
				printf("输入错误，请输入一个有效的数字。\n");
				return 1; // 错误
			}
			switch (grandson_option) {
			case 1:
				printf("请输入资产编号：");
				unsigned int id;
				if (scanf("%u", &id) != 1) {
					printf("输入错误，请输入一个有效的数字。\n");
					goto menu;
					return 1; // 错误
				}
				delete_asset_by_id(asset_list, id);
				goto menu;
				break;
			case 2:
				printf("请输入资产名称：");
				char name[50];
				getchar();
				input_in_string(50, name);
				//scanf("%s", name);
				delete_asset_by_name(&asset_list, name);
				goto menu;
				break;
			}
			break;
		}
		//*		3.计算 资产信息          *
	case 3:
		printf("***********************************\n");
		printf("*         计 算 子 菜 单          *\n");
		printf("*         1.计算资产总价值        *\n");
		printf("*         2.计算资产平均价值      *\n");
		printf("***********************************\n");
		printf("请输入功能选项：");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}
		switch (son_option) {
		case 1:
			calculate_total_price(asset_list);
			goto menu;
			break;
		case 2:
			calculate_average_price(asset_list);
			goto menu;
			break;
		}
		break;
		//*		4.排序 资产信息          *
	case 4:
		printf("***********************************\n");
		printf("*         排 序 子 菜 单          *\n");
		printf("*         1.按购置年份排序        *\n");
		printf("*         2.按购置价格升序排列    *\n");
		printf("*         3.按购置价格降序排列    *\n");
		printf("***********************************\n");
		printf("请输入功能选项：");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}
		
		switch (son_option) {
		case 1:
			sort_by_purchase_year(asset_list);
			goto menu;
			break;
		case 2:
			sort_by_price_ascend(asset_list);
			goto menu;
			break;
		case 3:
			sort_by_price_descend(asset_list);
			goto menu;
			break;
		}
		break;
		//*		5.查询 资产信息          *
	case 5:
		printf("***********************************\n");
		printf("*         查 询 子 菜 单          *\n");
		printf("*         1.按资产编号查询        *\n");
		printf("*         2.按资产名称查询        *\n");
		printf("***********************************\n");
		printf("请输入子选项：");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}
		switch (son_option) {
		case 1:
			printf("请输入资产编号：");
			unsigned int id;
			if (scanf("%u", &id) != 1) {
				printf("输入错误，请输入一个有效的数字。\n");
				goto menu;
				return 1; // 错误
			}
			search_asset_by_id(asset_list, id);
			goto menu;
			break;
		case 2:
			printf("请输入资产名称：");
			char name[50];
			getchar();
			input_in_string(50, name);
			//scanf("%s", name);
			search_asset_by_name(asset_list, name);
			goto menu;
			break;
		}

		break;
	case 6:   //无子菜单，直接输出结果
		printf("***********************************\n");
		printf("*         统 计 子 菜 单          *\n");
		printf("*         1.按学院统计            *\n");
		printf("*         2.按购买年份统计        *\n");
		printf("***********************************\n");
		printf("请输入子选项：");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}
		switch (son_option) {
		case 1:
			statistic_by_school(asset_list);
			goto menu;
			break;
		case 2:
			statistic_by_purchase_year(asset_list);
			goto menu;
			break;
		}

		break;
	case 7:
		printf("***********************************\n");
		printf("*         输 出 子 菜 单          *\n");
		printf("*         1.输出到屏幕            *\n");
		printf("*         2.输出到文件            *\n");
		printf("***********************************\n");
		printf("请输入功能选项：");
		if (scanf("%d", &son_option) != 1) {
			printf("输入错误，请输入一个有效的数字。\n");
			return 1; // 错误
		}
		switch (son_option) {
		case 1:
			print_asset_screen(asset_list);
			goto menu;
			break;
		case 2:
			print_asset_file(asset_list);
			goto menu;
			break;
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
}