#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "data.h"

// ����ȫ�ֱ���
int asset_count = 0;

/******************************
�ַ���¼�뺯��*/
input_in_string(int lengh, char s[]) {
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && i < lengh) {
		s[i++] = c;
	}
	s[i] = '\0';
}

/*********************************************
*ֻ������ȡ�û�������ʲ���Ϣ�����������ڵ�
*����ֵ��һ���ʲ�������ڵ����
**********************************************/
struct asset_node *read_from_keyboard(void) {
	struct asset_node* assetnode = (struct asset_node*)malloc(sizeof(struct asset_node));
	//assetnode->next = NULL;       // ȷ�� next ָ��Ϊ NULL
	if (assetnode == NULL) {
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	printf("�������ʲ���ţ�");
	if (scanf("%u", &((*assetnode).data.asset_id)) != 1) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("�������ʲ����ƣ�");
	getchar();
	input_in_string(50, (*assetnode).data.asset_name);
	/*if (scanf("%s", &((*assetnode).data.asset_name)) != 1) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}*/
	printf("�������ʲ���𣨼Ҿ�=1����ѧ�豸=2�������豸=3���칫�豸=4������ʲ�=5������=6����");
    if (scanf("%d", &((*assetnode).data.asset_type)) != 1) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("����������ѧԺ��");
	getchar();
	input_in_string(99, (*assetnode).data.school);
	/*if (scanf("%s", &((*assetnode).data.school)) != 1) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}*/
	printf("�����빺����ݣ�");
	if (scanf("%d", &((*assetnode).data.purchase_year)) != 1) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("�����빺�ü۸�");
    if (scanf("%f", &((*assetnode).data.price)) != 1) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}
	printf("���������������ƣ�");
	getchar();
	input_in_string(20, (*assetnode).data.recipient_name);
	/*if (scanf("%s", (*assetnode).data.recipient_name) != 1) {
		printf("�������\n");
		free(assetnode);
		return NULL;
	}*/
	printf("�����������˵绰��");
	if (scanf("%d", &((*assetnode).data.phone_number)) != 1) {
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

/**************************************
* ���ļ��е����ݶ�ȡ��������
* ����ֵ���������ͷָ��
* **************************************/
struct asset_node* read_from_file(struct asset_node* head) {
	FILE* fp = fopen("asset_data.txt", "r+");
	if (fp == NULL) {
		printf("�ļ���ʧ��\n");
		return NULL;
	}
	while (!feof(fp)) {
		struct asset_node* new_node = (struct asset_node*)malloc(sizeof(struct asset_node));
		if (new_node == NULL) {
			printf("�ڴ����ʧ��\n");
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
	printf("�ļ��򿪳ɹ�\n");
	return head;
}


/*�������Ļ*/
void print_asset_screen(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	printf("%-15s%-20s%-15s%-25s%-15s%-15s%-15s%-15s\n",
		"�ʲ����", "�ʲ�����", "�ʲ����", "����ѧԺ",
		"�������", "���ü۸�", "����������", "�����˵绰");
	printf("=========================================================================================================================================\n");
	while (p != NULL) {
		printf("%-15u%-20s%-15d%-25s%-15d%-15.2f%-15s%-15d\n",
			(p->data).asset_id, (p->data).asset_name, (p->data).asset_type, (p->data).school, (p->data).purchase_year, (p->data).price, (p->data).recipient_name, (p->data).phone_number);
		p = p->next;
	}
}
/*������ļ�*/
void print_asset_file(struct asset_node* asset_list) {
	FILE* fp = fopen("optput_asset_data.txt", "a");
	if (fp == NULL) {
		printf("�ļ���ʧ��\n");
		return;
	}
	struct asset_node* p = asset_list;
	while (p != NULL) {
		fprintf(fp, "%u %s %d %s %d %fRMB %s %d\n", p->data.asset_id, p->data.asset_name, p->data.asset_type, p->data.school, p->data.purchase_year, p->data.price, p->data.recipient_name,p->data.phone_number);
		p = p->next;
	}
	fclose(fp);
	printf("�ļ�д��ɹ�\n");
}

/*�����ʲ���Ų����ʲ�*/
void search_asset_by_id(struct asset_node* asset_list, unsigned int id) {
	struct asset_node* p = asset_list;
	while (p != NULL) {
		if (p->data.asset_id == id) {
			printf("%-15s%-20s%-15s%-25s%-15s%-15s%-15s%-15s\n",
				"�ʲ����", "�ʲ�����", "�ʲ����", "����ѧԺ",
				"�������", "���ü۸�", "����������", "�����˵绰");
			printf("=========================================================================================================================================\n");
			printf("%-15u%-20s%-15d%-25s%-15d%-15.2f%-15s%-15d\n",
				id, (p->data).asset_name, (p->data).asset_type, (p->data).school, (p->data).purchase_year, (p->data).price, (p->data).recipient_name, (p->data).phone_number);
			return;
		}
		p = p->next;
	}
	printf("δ�ҵ����ʲ�\n");
}

/*�����ʲ����Ʋ����ʲ�*/
void search_asset_by_name(struct asset_node* asset_list, char name[]) {
	struct asset_node* p = asset_list;
	while (p != NULL) {
		if (strcmp(p->data.asset_name, name) == 0) {
			printf("%-15s%-20s%-15s%-25s%-15s%-15s%-15s%-15s\n",
				"�ʲ����", "�ʲ�����", "�ʲ����", "����ѧԺ",
				"�������", "���ü۸�", "����������", "�����˵绰");
			printf("=========================================================================================================================================\n");
			printf("%-15u%-20s%-15d%-25s%-15d%-15.2f%-15s%-15d\n",
				(p->data).asset_id, name, (p->data).asset_type, (p->data).school, (p->data).purchase_year, (p->data).price, (p->data).recipient_name, (p->data).phone_number);
			return;
		}
		p = p->next;
	}
	printf("δ�ҵ����ʲ�\n");
}

void delete_asset_by_id(struct asset_node* asset_list, unsigned int id) {
	struct asset_node* p = asset_list;
	struct asset_node* q = asset_list;
	while (p != NULL) {
		if (p->data.asset_id == id) {
			q->next = p->next;
			free(p);
			printf("ɾ���ɹ�\n");
			return;
		}
		q = p;
		p = p->next;
	}
	printf("δ�ҵ����ʲ�\n");
}
/*�������Ʋ�ɾ��*/
void delete_asset_by_name(struct asset_node** asset_list, char* name) {
	struct asset_node* p = *asset_list; // ��ǰ�ڵ�
	struct asset_node* q = NULL;       // ǰһ���ڵ�

	while (p != NULL) {
		// �Ƚ��ʲ�����
		if (strcmp(p->data.asset_name, name) == 0) {
			// ����ͷ�ڵ�ɾ��
			if (q == NULL) {
				*asset_list = p->next; // ����ͷ�ڵ�
			}
			else {
				q->next = p->next;     // ǰһ���ڵ�������ǰ�ڵ�
			}
			free(p); // �ͷŵ�ǰ�ڵ�
			printf("ɾ���ɹ�\n");
			return;
		}
		q = p;       // ����ǰһ���ڵ�
		p = p->next; // �ƶ�����һ���ڵ�
	}
	printf("δ�ҵ����ʲ�\n");
}

/*���չ����������*/
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
	printf("����ɹ�\n");
}

/*���չ��ü۸���������*/
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
	printf("����ɹ�\n");
}

/*���չ��ü۸�������*/
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
	printf("����ɹ�\n");
}

/*�����ܼ�ֵ*/
void calculate_total_price(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	float total_price = 0;
	while (p != NULL) {
		total_price += p->data.price;
		p = p->next;
	}
	printf("�ܼ�ֵΪ��%.2f\n", total_price);
}

/*����ƽ����ֵ*/
void calculate_average_price(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	float total_price = 0;
	while (p != NULL) {
		total_price += p->data.price;
		p = p->next;
	}
	printf("ƽ����ֵΪ��%.2f\n", total_price / asset_count);
}

/*��ѧԺͳ��*/
void statistic_by_school(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	char school[99];
	printf("������ѧԺ���ƣ�");
	getchar();
	input_in_string(99, school);
	/*if (scanf("%s", school) != 1) {
		printf("�������\n");
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
	printf("ѧԺ��%s\n", school);
	printf("�ܼ�ֵΪ��%.2f\n", total_price);
	printf("�ʲ�����Ϊ��%d\n", count);
}

/*���չ������ͳ��*/
void statistic_by_purchase_year(struct asset_node* asset_list) {
	struct asset_node* p = asset_list;
	int year;
	printf("�����빺����ݣ�");
	if (scanf("%d", &year) != 1) {
		printf("�������\n");
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
	printf("������ݣ�%d\n", year);
	printf("�ܼ�ֵΪ��%.2f\n", total_price);
	printf("�ʲ�����Ϊ��%d\n", count);
}