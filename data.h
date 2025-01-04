// Last updated: 2024/12/29 18:29:00
#ifndef DATA_H
#define DATA_H

typedef struct asset {
	unsigned short asset_id; //�ʲ����
	char asset_name[50]; //�ʲ�����
	enum {  //�ʲ����ö��
		�Ҿ� = 1,
		��ѧ�豸 = 2,
		�����豸 = 3,
		�칫�豸 = 4,
		����ʲ� = 5,
		���� = 6
	} asset_type;
	float price; //���ü۸�
	char recipient_name[4]; //����������
	unsigned int phone_number; //�����˵绰
} Asset;

/*struct asset asset_list[150]; //�ʲ���Ϣ�б�*/
//����������洢�ʲ���Ϣ
typedef struct asset_node {
	struct asset data;
	struct asset_node* next;
} Node;

Node* head; //ͷָ��



#endif
