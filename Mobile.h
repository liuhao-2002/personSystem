//流动人员类
/*主要功能：
* 查看公告
* 填报信息——上报个人的姓名，身份证号，电话号，起始地，交通方式，车次/航班号
* 查看信息——查看个人所上报的信息
* 注销登录——返回登录界面
*/
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

class Mobile :public Identity
{
public:
	//默认构造
	Mobile();
	//有参构造（姓名即用户名，密码，身份证号，电话号，始发地，出行方式，车次，家庭住址）
	Mobile(string name, string pwd, string id, string phone_id, string start, int way, string way_id,string home);
	
	//菜单界面
	virtual void operMenu();
	//注册
	void addPerson();
	
	//查看公告
	void showNotice();
	//填报信息
	void addInfo();

	//独有属性
	string m_Id;
	string m_phone_id;
	string m_Start;
	int m_Way;
	string m_May_id;
	string m_Home;
};