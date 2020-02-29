#pragma once
#ifndef _MAINUI_H
#define _MAINUI_H
#include <stdio.h>
#include "../Service/AccountServer.h"

//初始界面
void MainUI_Hello();

//登录之后的菜单
void MainUI_Menu();

//注册的菜单
int AccountUI_SignIn();
#endif // !_MAINUI_H

