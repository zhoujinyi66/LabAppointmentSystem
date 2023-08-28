#pragma once
#include<iostream>
#include<vector>
#include"identity.h"

using namespace std;

class Student :public Identity
{
public:
	Student();
	Student(int id, string name, string password);
	virtual void menu();
	//申请预约
	void apply();
	//查找预约
	void showmyapply();
	//取消预约
	void cancelapply();
	//删除已取消的预约记录
	void deletecancel();

	int m_id;
};