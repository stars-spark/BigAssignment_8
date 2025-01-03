#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "data.h"

// 声明全局变量
int asset_count = 0;
/*struct node* input_new_asset() {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("内存分配失败\n");
		return NULL;
	}
	printf("请输入资产编号：");
	if (scanf("%hu", &new_node->data.asset_id) != 1) {
		printf("输入错误\n");
		free(new_node);
		return NULL;
	}
	printf("请输入资产名称：");
	if (scanf("%s", new_node->data.asset_name) != 1) {
		printf("输入错误\n");
		free(new_node);
		return NULL;
	}
	printf("请输入资产类别：");
	if (scanf("%d", &new_node->data.asset_type) != 1) {
		printf("输入错误\n");
		free(new_node);
		return NULL;
	}
	printf("请输入购置价格：");
	if (scanf("%f", &new_node->data.price) != 1) {
		printf("输入错误\n");
		free(new_node);
		return NULL;
	}
	printf("请输入领用人名称：");
	if (scanf("%s", new_node->data.recipient_name) != 1) {
		printf("输入错误\n");
		free(new_node);
		return NULL;
	}
	printf("请输入领用人电话：");
	if (scanf("%d", &new_node->data.phone_number) != 1) {
		printf("输入错误\n");
		free(new_node);
		return NULL;
	}
	new_node->next = NULL;
	return new_node;

}
*/

/*********************************************
*只用来读取用户输入的资产信息，不负责加入节点
*返回值：一个资产的链表节点的针
**********************************************/
struct asset_node *read_from_keyboard(void) {
	struct asset_node* assetnode = (struct asset_node*)malloc(sizeof(struct asset_node));
	if (assetnode == NULL) {
		printf("内存分配失败\n");
		return NULL;
	}
	printf("请输入资产编号：");
	if (scanf("%hu", &((*assetnode).data.asset_id) != 1)) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入资产名称：");
	if (scanf("%s", &((*assetnode).data.asset_name) != 1)) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入资产类别：");
	if (scanf("%d", &((*assetnode).data.asset_type) != 1)) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入购置价格：");
	if (scanf("%f", &((*assetnode).data.price) != 1)) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入领用人名称：");
	if (scanf("%s", &((*assetnode).data.recipient_name) != 1)) {
		printf("输入错误\n");
		free(assetnode);
		return NULL;
	}
	printf("请输入领用人电话：");
	if (scanf("%d", &((*assetnode).data.phone_number) != 1)) {
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

/*void output_to_screen(void) {
    for (int i = 0; i < asset_count; i++) {
		
    }
}*/
