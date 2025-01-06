#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "func.h"
#include "data.h"

// 声明全局变量
int asset_count = 0;

/******************************
字符串录入函数*/
void input_in_string(int lengh, char s[]) {
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && i < lengh) {
		s[i++] = c;
	}
	s[i] = '\0';
}

/*********************************************
*只用来读取用户输入的资产信息，不负责加入节点
*返回值：一个资产的链表节点的指针
**********************************************/
struct asset_node *read_from_keyboard(void) {
	struct asset_node* assetnode = (struct asset_node*)malloc(sizeof(struct asset_node));
	//assetnode->next = NULL;       // 确保 next 指针为 NULL
	if (assetnode == NULL) {
		printf("内存分配失败\n");
		return NULL;
	}
	printf("请输入资产编号：");
	if (scanf("%u", &((*assetnode).data.asset_id)) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入资产名称：");
	getchar();
	input_in_string(50, (*assetnode).data.asset_name);
	/*if (scanf("%s", &((*assetnode).data.asset_name)) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}*/
	printf("请输入资产类别（家具=1，教学设备=2，科研设备=3，办公设备=4，软件资产=5，其他=6）：");
    if (scanf("%d", &((*assetnode).data.asset_type)) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入所属学院：");
	getchar();
	input_in_string(99, (*assetnode).data.school);
	/*if (scanf("%s", &((*assetnode).data.school)) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}*/
	printf("请输入购置年份：");
	if (scanf("%d", &((*assetnode).data.purchase_year)) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入购置价格：");
    if (scanf("%f", &((*assetnode).data.price)) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入领用人名称：");
	getchar();
	input_in_string(20, (*assetnode).data.recipient_name);
	/*if (scanf("%s", (*assetnode).data.recipient_name) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}*/
	printf("请输入领用人电话：");
	if (scanf("%d", &((*assetnode).data.phone_number)) != 1) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	return assetnode;

}


/**************************************
* 负责将用户输入的资产信息加入到链表中
*返回值：新链表的头指针
***************************************/
struct asset_node* add_asset(struct asset_node* head) {
	struct asset_node* new_asset = read_from_keyboard();
	if (new_asset == NULL) {
		return head;
	}
	new_asset->next = head; //新节点的next指向head所指的节点
	return new_asset; //返回新节点地址，外部可以用头指针接收
}

/**************************************
* 将文件中的数据读取到链表中
* 返回值：新链表的头指针
* **************************************/
struct asset_node* read_from_file(struct asset_node* head) {
	FILE* fp = fopen("asset_data.txt", "r+");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return NULL;
	}
	while (!feof(fp)) {
		struct asset_node* new_node = (struct asset_node*)malloc(sizeof(struct asset_node));
		if (new_node == NULL) {
			printf("内存分配失败\n");
			fclose(fp);
			return head;
		}
		if (fscanf(fp, "%u %99s %d %99s %d %f %99s %d", &new_node->data.asset_id, new_node->data.asset_name, &new_node->data.asset_type, new_node->data.school, &new_node->data.purchase_year, &new_node->data.price, new_node->data.recipient_name, &new_node->data.phone_number) != 8) {
			free(new_node);
			break;
		}
		new_node->next = head;
		head = new_node;
	}
	fclose(fp);
	printf("文件打开成功\n");
	return head;
}


/*输出到屏幕*/
void print_asset_screen(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	printf("%-15s%-20s%-15s%-25s%-15s%-15s%-15s%-15s\n",
		"资产编号", "资产名称", "资产类别", "所属学院",
		"购置年份", "购置价格", "领用人名称", "领用人电话");
	printf("=========================================================================================================================================\n");
	
	while (p != NULL) {
		const char* asset_type_name;
		switch (p->data.asset_type) {
			case 1: asset_type_name = "家具"; break;
			case 2: asset_type_name = "教学设备"; break;
			case 3: asset_type_name = "科研设备"; break;
			case 4: asset_type_name = "办公设备"; break;
			case 5: asset_type_name = "软件资产"; break;
			case 6: asset_type_name = "其他"; break;
			default: asset_type_name = "未知"; break;
		}
		printf("%-15u%-20s%-15s%-25s%-15d%-15.2f%-15s%-15d\n",
			(p->data).asset_id, (p->data).asset_name, asset_type_name, (p->data).school, (p->data).purchase_year, (p->data).price, (p->data).recipient_name, (p->data).phone_number);
		p = p->next;
	}
}
/*输出到文件*/
void print_asset_file(struct asset_node* asset_list) {
	FILE* fp = fopen("output_asset_data.txt", "a");
	if (fp == NULL) {
		printf("文件打开失败\n");
		return;
	}
	struct asset_node* p = asset_list;
	remove_invalid_nodes(&asset_list);
	while (p != NULL) {
		const char* asset_type_name;
		switch (p->data.asset_type) {
			case 1: asset_type_name = "家具"; break;
			case 2: asset_type_name = "教学设备"; break;
			case 3: asset_type_name = "科研设备"; break;
			case 4: asset_type_name = "办公设备"; break;
			case 5: asset_type_name = "软件资产"; break;
			case 6: asset_type_name = "其他"; break;
			default: asset_type_name = "未知"; break;
		}
		fprintf(fp, "%u %s %s %s %d %.2fRMB %s %d\n", p->data.asset_id, p->data.asset_name, asset_type_name, p->data.school, p->data.purchase_year, p->data.price, p->data.recipient_name, p->data.phone_number);
		p = p->next;
	}
	fclose(fp);
	printf("文件写入成功\n");
}

/*按照资产编号查找资产*/
void search_asset_by_id(struct asset_node* asset_list, unsigned int id) {
	struct asset_node* p = asset_list;
	while (p != NULL) {
		if (p->data.asset_id == id) {
			printf("%-15s%-20s%-15s%-25s%-15s%-15s%-15s%-15s\n",
				"资产编号", "资产名称", "资产类别", "所属学院",
				"购置年份", "购置价格", "领用人名称", "领用人电话");
			printf("=========================================================================================================================================\n");
			printf("%-15u%-20s%-15d%-25s%-15d%-15.2f%-15s%-15d\n",
				id, (p->data).asset_name, (p->data).asset_type, (p->data).school, (p->data).purchase_year, (p->data).price, (p->data).recipient_name, (p->data).phone_number);
			return;
		}
		p = p->next;
	}
	printf("未找到该资产\n");
}

/*按照资产名称查找资产*/
void search_asset_by_name(struct asset_node* asset_list, char name[]) {
	struct asset_node* p = asset_list;
	while (p != NULL) {
		if (strcmp(p->data.asset_name, name) == 0) {
			printf("%-15s%-20s%-15s%-25s%-15s%-15s%-15s%-15s\n",
				"资产编号", "资产名称", "资产类别", "所属学院",
				"购置年份", "购置价格", "领用人名称", "领用人电话");
			printf("=========================================================================================================================================\n");
			printf("%-15u%-20s%-15d%-25s%-15d%-15.2f%-15s%-15d\n",
				(p->data).asset_id, name, (p->data).asset_type, (p->data).school, (p->data).purchase_year, (p->data).price, (p->data).recipient_name, (p->data).phone_number);
			return;
		}
		p = p->next;
	}
	printf("未找到该资产\n");
}

/*按照资产ID删除资产*/
void delete_asset_by_id(struct asset_node* asset_list, unsigned int id) {
	struct asset_node* p = asset_list;
	struct asset_node* q = asset_list;
	while (p != NULL) {
		if (p->data.asset_id == id) {
			q->next = p->next;
			free(p);
			printf("删除成功\n");
			return;
		}
		q = p;
		p = p->next;
	}
	printf("未找到该资产\n");
}

/*查找名称并删除*/
void delete_asset_by_name(struct asset_node** asset_list, char* name) {
	struct asset_node* p = *asset_list; // 当前节点
	struct asset_node* q = NULL;       // 前一个节点

	while (p != NULL) {
		// 比较资产名称
		if (strcmp(p->data.asset_name, name) == 0) {
			// 处理头节点删除
			if (q == NULL) {
				*asset_list = p->next; // 更新头节点
			}
			else {
				q->next = p->next;     // 前一个节点跳过当前节点
			}
			free(p); // 释放当前节点
			printf("删除成功\n");
			return;
		}
		q = p;       // 更新前一个节点
		p = p->next; // 移动到下一个节点
	}
	printf("未找到该资产\n");
}

/*按照购置年份排序*/
void sort_by_purchase_year(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	struct asset_node* q = asset_list;
	struct asset temp;
	while (p != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->data.purchase_year > q->data.purchase_year) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
	printf("排序成功\n");
}

/*按照购置价格升序排列*/
void sort_by_price_ascend(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	struct asset_node* q = asset_list;
	struct asset temp;
	while (p != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->data.price > q->data.price) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
	printf("排序成功\n");
}

/*按照购置价格降序排列*/
void sort_by_price_descend(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	struct asset_node* q = asset_list;
	struct asset temp;
	while (p != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->data.price < q->data.price) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
	printf("排序成功\n");
}

/*计算总价值*/
void calculate_total_price(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	float total_price = 0;
	while (p != NULL) {
		total_price += p->data.price;
		p = p->next;
	}
	printf("总价值为：%.2f\n", total_price);
}

/*计算平均价值*/
void calculate_average_price(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	float total_price = 0;
	int count = 0; // 计算节点数量
	while (p != NULL) {
		total_price += p->data.price;
		count++;
		p = p->next;
	}
	if (count == 0) {
		printf("平均价值为：0.00\n");
	} else {
		printf("平均价值为：%.2f\n", total_price / count);
	}
}

/*按学院统计*/
void statistic_by_school(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	char school[99];
	printf("请输入学院名称：");
	getchar();
	input_in_string(99, school);
	/*if (scanf("%s", school) != 1) {
		printf("输入错误\n");
		return;
	}*/
	float total_price = 0;
	int count = 0;
	while (p != NULL) {
		if (strcmp(p->data.school, school) == 0) {
			total_price += p->data.price;
			count++;
		}
		p = p->next;
	}
	printf("学院：%s\n", school);
	printf("总价值为：%.2f\n", total_price);
	printf("资产数量为：%d\n", count);
}

/*按照购买年份统计*/
void statistic_by_purchase_year(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	int year;
	printf("请输入购买年份：");
	if (scanf("%d", &year) != 1) {
		printf("输入错误\n");
		return;
	}
	float total_price = 0;
	int count = 0;
	while (p != NULL) {
		if (p->data.purchase_year == year) {
			total_price += p->data.price;
			count++;
		}
		p = p->next;
	}
	printf("购买年份：%d\n", year);
	printf("总价值为：%.2f\n", total_price);
	printf("资产数量为：%d\n", count);
}

void statistic_year_percentage(struct asset_node* asset_list){
	struct asset_node* p = asset_list;
	float total_price = 0;
	int year_count[3000] = {0}; // 假设年份从0到2999
	float year_price[3000] = {0.0};

	// 计算总价值和每年的总价值
	while (p != NULL) {
		total_price += p->data.price;
		year_price[p->data.purchase_year] += p->data.price;
		year_count[p->data.purchase_year]++;
		p = p->next;
	}

	// 输出每年的价值占比
	for (int i = 0; i < 3000; i++) {
		if (year_count[i] > 0) {
			printf("购买年份：%d\n", i);
			printf("总价值为：%.2f\n", year_price[i]);
			printf("总价值占比为：%.2f%%\n", (year_price[i] / total_price) * 100);
		}
	}
}

void remove_invalid_nodes(Node** asset_list) {
	if (!asset_list || !(*asset_list)) {
		return; // 空链表直接返回
	}

	Node* current = *asset_list;
	Node* prev = NULL;

	// 遍历链表
	while (current != NULL) {
		if (current->data.purchase_year == 0) {
			// 删除当前节点
			if (prev == NULL) {
				// 删除的是头节点
				*asset_list = current->next;
				free(current);
				current = *asset_list;
			}
			else {
				// 删除的是中间或尾节点
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			// 移动指针
			prev = current;
			current = current->next;
		}
	}
}

void modify_asset_data(struct asset_node* asset_list, unsigned int id) {
	struct asset_node* p = asset_list;
	while (p != NULL) {
		if (p->data.asset_id == id) {
			printf("请输入资产编号：");
			if (scanf("%u", &p->data.asset_id) != 1) {
				printf("输入错误\n");
				return;
			}
			printf("请输入资产名称：");
			getchar();
			input_in_string(50, p->data.asset_name);
			/*if (scanf("%s", p->data.asset_name) != 1) {
				printf("输入错误\n");
				return;
			}*/
			printf("请输入资产类别（家具=1，教学设备=2，科研设备=3，办公设备=4，软件资产=5，其他=6）：");
			if (scanf("%d", &p->data.asset_type) != 1) {
				printf("输入错误\n");
				return;
			}
			printf("请输入所属学院：");
			getchar();
			input_in_string(99, p->data.school);
			/*if (scanf("%s", p->data.school) != 1) {
				printf("输入错误\n");
				return;
			}*/
			printf("请输入购置年份：");
			if (scanf("%d", &p->data.purchase_year) != 1) {
				printf("输入错误\n");
				return;
			}
			printf("请输入购置价格：");
			if (scanf("%f", &p->data.price) != 1) {
				printf("输入错误\n");
				return;
			}
			printf("请输入领用人名称：");
			getchar();
			input_in_string(20, p->data.recipient_name);
			/*if (scanf("%s", p->data.recipient_name) != 1) {
				printf("输入错误\n");
				return;
			}*/
			printf("请输入领用人电话：");
			if (scanf("%d", &p->data.phone_number) != 1) {
				printf("输入错误\n");
				return;
			}
			printf("修改成功\n\n");
			print_asset_screen(asset_list);
			return;
		}
		p = p->next;
	}
	printf("未找到该资产");
}


