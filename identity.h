#pragma once
#include<iostream>
#include<string>

using namespace std;

class Identity                      //��Ա����
{
public:
	virtual void menu() = 0;        //��½��˵�

	string m_name;                  //�û���
	string m_password;              //����
};