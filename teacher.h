#pragma once
#include<iostream>
#include"identity.h"

using namespace std;

class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int id, string name, string password);
	virtual void menu();
	//查看所有预约
	void showallapply();
	//查找预约
	void searchapply();
	//审核预约
	void validorder();

	int m_id;
};