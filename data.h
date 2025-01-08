// Last updated: 2024/12/29 18:29:00
#ifndef DATA_H
#define DATA_H

typedef struct asset {
	unsigned int asset_id; //�ʲ����
	char asset_name[50]; //�ʲ�����
	enum asset_type { FURNITURE = 1, TEACHING_EQUIPMENT, RESEARCH_EQUIPMENT, OFFICE_EQUIPMENT, SOFTWARE_ASSET, OTHER } asset_type; //�ʲ����
	char school[99]; //����ѧԺ
	int purchase_year; //�������
	float price; //���ü۸�
	char recipient_name[20]; //����������
	unsigned int phone_number; //�����˵绰
} Asset;

/*struct asset asset_list[150]; //�ʲ���Ϣ�б�*/
//����������洢�ʲ���Ϣ
typedef struct asset_node {
	struct asset data;
	struct asset_node* next;
} Node;

//Node* head; //ͷָ��

#endif
