#ifndef FUNC_H
#define FUNC_H


/*********************************************
*ֻ������ȡ�û�������ʲ���Ϣ�����������ڵ�*
**********************************************/
struct asset_node* read_from_keyboard(void);

struct asset_node* add_asset(struct asset_node* head);
struct asset_node* read_from_file(struct asset_node* head);
void print_asset_screen(struct asset_node* asset_list);
void print_asset_file(struct asset_node* asset_list);
void search_asset_by_id(struct asset_node* asset_list,int id);
void search_asset_by_name(struct asset_node* asset_list, char name[]);


#endif