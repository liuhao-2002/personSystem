//普通人类
#pragma once
#include<iostream>
#include<fstream>
#include <iomanip>//格式输出
using namespace std;
#include"Ordinary.h"
#include"globalFile.h"

//默认构造
Ordinary::Ordinary()
{

}
//有参构造
Ordinary::Ordinary(string name, string pwd)
{

}

//菜单界面
void Ordinary::operMenu()
{
	cout << "欢迎普通用户" << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.查看公告             |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.注销登陆             |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//普通用户子界面
void Ordinary::ordinaryMenu(Identity*& ordinary)
{
	while (true)
	{
		//普通用户菜单
		ordinary->operMenu();
		Ordinary* man = (Ordinary*)ordinary;

		int select = 0;

		while (1)
		{
			if (!(cin >> select))
			{
				cout << "输入不合法，请重新输入\n";
				cin.clear(); // 清除输入流错误标记
				cin.ignore(1024, '\n');// 取走刚才输入流中的字符
				// cin.ignore()默认取走一个字符
			}
			else
				break;
		}
		if (select == 1)
		{
			cout << "查看公告" << endl;
			man->showNotice();
		}
		else
		{
			delete man;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//查看公告
void Ordinary::showNotice()
{
	//存储信息
	MyStruct my;
	ifstream ifs;
	ifs.open(NOTICE, ios::in);//用户名，身份证号，电话号，始发地，出行方式，车次，家庭住址
	while (ifs >> my.name && ifs >> my.phone && ifs >> my.startLoc && ifs >> my.way && ifs >> my.wayID && ifs >> my.homeLoc)
	{
		cout << setw(15) << std::left << my.name << setw(15) << std::left << my.phone << setw(15) << std::left << my.startLoc;
		if (my.way == 1)
		{
			cout << setw(15) << std::left << "火车";
		}
		else if (my.way == 2)
		{
			cout << setw(15) << std::left << "客车";
		}
		else if (my.way == 3)
		{
			cout << setw(15) << std::left << "飞机";
		}
		else if (my.way == 4)
		{
			cout << setw(15) << std::left << "其他";
		}
		cout << setw(15) << std::left << my.wayID << setw(15) << std::left << my.homeLoc << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
