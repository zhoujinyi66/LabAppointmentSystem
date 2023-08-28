#pragma once
#include<iostream>
#include<string>

using namespace std;

class Identity                      //人员基类
{
public:
	virtual void menu() = 0;        //登陆后菜单

	string m_name;                  //用户名
	string m_password;              //密码
};