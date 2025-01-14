// Last updated: 2024/12/29 18:29:00
#ifndef DATA_H
#define DATA_H

typedef struct asset {
	unsigned int asset_id; //资产编号
	char asset_name[50]; //资产名称
	enum asset_type { FURNITURE = 1, TEACHING_EQUIPMENT, RESEARCH_EQUIPMENT, OFFICE_EQUIPMENT, SOFTWARE_ASSET, OTHER } asset_type; //资产类别
	char school[99]; //所属学院
	int purchase_year; //购置年份
	float price; //购置价格
	char recipient_name[20]; //领用人名称
	unsigned int phone_number; //领用人电话
} Asset;

/*struct asset asset_list[150]; //资产信息列表*/
//尝试用链表存储资产信息
typedef struct asset_node {
	struct asset data;
	struct asset_node* next;
} Node;

//Node* head; //头指针

#endif
