#include "MainUI.h"
int uid = 0;
int AccountUI_SignIn()
{
	char ch;
	char name[30], password[30];
	int sex;  //1=�У�2=Ů
	printf("������Ҫע����û���:\n");
	scanf("%s", name);
	printf("�������Ա����0-Ů/1-��\n");
	scanf("%d", &sex);
	printf("����������:\n");
	scanf("%s", password);
	//printf("�û�����%s\n���룺%s\n�Ա�%d\n", name, password, sex);
	//scanf("%s", password);
	return AccountServer_SignIn(name, password, sex);
}

void MainUI_Menu()
{

}

void MainUI_Hello()
{
	if (uid > 0)  //�ѵ�¼
	{
		MainUI_Menu();
	}
	int choice;
	while (1)
	{
		system("clear");
		printf("-------------------\n"
			"welcome to YvanChat\n"
			"-------------------\n");
		printf("����ѡ��:\n"
			"\t1����¼\n"
			"\t2��ע��\n"
			"\t3���˳�\n"
			"�����빦�����:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			break;
		case 2:
			AccountUI_SignIn();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}




