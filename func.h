#ifndef FUNC_H
#define FUNC_H


/*********************************************
*只用来读取用户输入的资产信息，不负责加入节点*
**********************************************/
struct asset_node* read_from_keyboard(void);

struct asset_node* add_asset(struct asset_node* head);
struct asset_node* read_from_file(struct asset_node* head);
void print_asset_screen(struct asset_node* asset_list);
void print_asset_file(struct asset_node* asset_list);
void search_asset_by_id(struct asset_node* asset_list,int id);
void search_asset_by_name(struct asset_node* asset_list, char name[]);


#endif