#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "data.h"

// ����ȫ�ֱ���
int asset_count = 0;
/*struct node* input_new_asset() {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	printf("�������ʲ���ţ�");
	if (scanf("%hu", &new_node->data.asset_id) != 1) {
		printf("�������\n");
		free(new_node);
		return NULL;
	}
	printf("�������ʲ����ƣ�");
	if (scanf("%s", new_node->data.asset_name) != 1) {
		printf("�������\n");
		free(new_node);
		return NULL;
	}
	printf("�������ʲ����");
	if (scanf("%d", &new_node->data.asset_type) != 1) {
		printf("�������\n");
		free(new_node);
		return NULL;
	}
	printf("�����빺�ü۸�");
	if (scanf("%f", &new_node->data.price) != 1) {
		printf("�������\n");
		free(new_node);
		return NULL;
	}
	printf("���������������ƣ�");
	if (scanf("%s", new_node->data.recipient_name) != 1) {
		printf("�������\n");
		free(new_node);
		return NULL;
	}
	printf("�����������˵绰��");
	if (scanf("%d", &new_node->data.phone_number) != 1) {
		printf("�������\n");
		free(new_node);
		return NULL;
	}
	new_node->next = NULL;
	return new_node;

}
*/

/*********************************************
*ֻ������ȡ�û�������ʲ���Ϣ�����������ڵ�
*����ֵ��һ���ʲ�������ڵ����
**********************************************/
struct asset_node *read_from_keyboard(void) {
	struct asset_node* assetnode = (struct asset_node*)malloc(sizeof(struct asset_node));
	if (assetnode == NULL) {
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	printf("�������ʲ���ţ�");
	if (scanf("%hu", &((*assetnode).data.asset_id) != 1)) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("�������ʲ����ƣ�");
	if (scanf("%s", &((*assetnode).data.asset_name) != 1)) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("�������ʲ����");
	if (scanf("%d", &((*assetnode).data.asset_type) != 1)) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("�����빺�ü۸�");
	if (scanf("%f", &((*assetnode).data.price) != 1)) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("���������������ƣ�");
	if (scanf("%s", &((*assetnode).data.recipient_name) != 1)) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("�����������˵绰��");
	if (scanf("%d", &((*assetnode).data.phone_number) != 1)) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	return assetnode;

}


/**************************************
* �����û�������ʲ���Ϣ���뵽������
*����ֵ���������ͷָ��
***************************************/
struct asset_node* add_asset(struct asset_node* head) {
	struct asset_node* new_asset = read_from_keyboard();
	if (new_asset == NULL) {
		return head;
	}
	new_asset->next = head; //�½ڵ��nextָ��head��ָ�Ľڵ�
	return new_asset; //�����½ڵ��ַ���ⲿ������ͷָ�����
}

/*void output_to_screen(void) {
    for (int i = 0; i < asset_count; i++) {
		
    }
}*/
