#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "func.h"
#include "data.h"

int sub_menu_1(int current_option) {
	int new_option;
	printf("***********************************\n");
	printf("*          �� �� �� �� ��         *\n");
	printf("*           1.�Ӽ���¼��          *\n");
	printf("*           2.���ļ�����          *\n");
	printf("***********************************\n");
	printf("�����빦��ѡ�");
	if (scanf("%d", &new_option) != 1) {
		printf("�������������һ����Ч�����֡�\n");
		return current_option; // ���ص�ǰѡ��������
	}
	return new_option;
}   //����

int sub_menu_2(int current_option) {
	printf("***********************************\n");
	printf("*          �� �� �� �� ��         *\n");
	printf("*           1.���                *\n");
	printf("*           2.ɾ��                *\n");
	printf("*           3.�޸�                *\n");
	printf("***********************************\n");
	printf("�����빦��ѡ�");
	if (scanf("%d", &current_option) != 1) {
		printf("�������������һ����Ч�����֡�\n");
		return current_option; // ����
	}
	return current_option;
}  //�޸�
int sub_menu_3(int current_option) {
	printf("***********************************\n");
	printf("*         �� �� �� �� ��          *\n");
	printf("*         1.�����ʲ��ܼ�ֵ        *\n");
	printf("*         2.�����ʲ�ƽ����ֵ      *\n");
	printf("***********************************\n");
	printf("�����빦��ѡ�");
	if (scanf("%d", &current_option) != 1) {
		printf("�������������һ����Ч�����֡�\n");
		return current_option; // ����
	}
	return current_option;
}

int sub_menu_4(int current_option) {
	printf("***********************************\n");
	printf("*         �� �� �� �� ��          *\n");
	printf("*         1.�������������        *\n");
	printf("*         2.�����ü۸���������    *\n");
	printf("*         3.�����ü۸�������    *\n");
	printf("***********************************\n");
	printf("�����빦��ѡ�");
	if (scanf("%d", &current_option) != 1) {
		printf("�������������һ����Ч�����֡�\n");
		return current_option; // ����
	}
	return current_option;
}

int sub_menu_5(int current_option) {
	printf("***********************************\n");
	printf("*         �� ѯ �� �� ��          *\n");
	printf("*         1.���ʲ���Ų�ѯ        *\n");
	printf("*         2.���ʲ����Ʋ�ѯ        *\n");
	printf("***********************************\n");
	printf("��������ѡ�");
	if (scanf("%d", &current_option) != 1) {
		printf("�������������һ����Ч�����֡�\n");
		return current_option; // ����
	}
	return current_option;
}

int sub_menu_6(int current_option) {
	printf("***********************************\n");
	printf("*         ͳ �� �� �� ��          *\n");
	printf("*         1.��ѧԺͳ��            *\n");
	printf("*         2.���������ͳ��        *\n");
	printf("*         3.ͳ�Ƹ���ݹ�����ռ��  *\n");
	printf("***********************************\n");
	printf("��������ѡ�");
	if (scanf("%d", &current_option) != 1) {
		printf("�������������һ����Ч�����֡�\n");
		return current_option; // ����
	}
	return current_option;
}

int sub_menu_7(int current_option) {
	printf("***********************************\n");
	printf("*         �� �� �� �� ��          *\n");
	printf("*         1.�������Ļ            *\n");
	printf("*         2.������ļ�            *\n");
	printf("***********************************\n");
	printf("��������ѡ�");
	if (scanf("%d", &current_option) != 1) {
		printf("�������������һ����Ч�����֡�\n");
		return current_option; // ����
	}
	return current_option;
}