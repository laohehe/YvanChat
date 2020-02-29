#include "MainUI.h"
int uid = 0;
int AccountUI_SignIn()
{
	char ch;
	char name[30], password[30];
	int sex;  //1=男，2=女
	printf("请输入要注册的用户名:\n");
	scanf("%s", name);
	printf("请输入性别序号0-女/1-男\n");
	scanf("%d", &sex);
	printf("请输入密码:\n");
	scanf("%s", password);
	//printf("用户名：%s\n密码：%s\n性别：%d\n", name, password, sex);
	//scanf("%s", password);
	return AccountServer_SignIn(name, password, sex);
}

void MainUI_Menu()
{

}

void MainUI_Hello()
{
	if (uid > 0)  //已登录
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
		printf("功能选项:\n"
			"\t1、登录\n"
			"\t2、注册\n"
			"\t3、退出\n"
			"请输入功能序号:");
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




