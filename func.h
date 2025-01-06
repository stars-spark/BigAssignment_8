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
void search_asset_by_id(struct asset_node* asset_list, unsigned int id);
void search_asset_by_name(struct asset_node* asset_list, char name[]);
void delete_asset_by_id(struct asset_node* asset_list, unsigned int id);
void delete_asset_by_name(struct asset_node** asset_list, char* name);
void sort_by_purchase_year(struct asset_node* asset_list);
void calculate_total_price(struct asset_node* asset_list);
void calculate_average_price(struct asset_node* asset_list);
void statistic_by_school(struct asset_node* asset_list);
void statistic_by_purchase_year(struct asset_node* asset_list);
void remove_invalid_nodes(struct asset_node** asset_list);
void statistic_year_percentage(struct asset_node* asset_list);
void sort_by_price_ascend(struct asset_node* asset_list);
void sort_by_price_descend(struct asset_node* asset_list);
void input_in_string(int lengh, char s[]);
void modify_asset_data(struct asset_node* asset_list, unsigned int id);
void statistic_year_percentage(struct asset_node* asset_list);
void modify_asset_data(struct asset_node* asset_list, unsigned int id);


#endif