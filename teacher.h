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
	//�鿴����ԤԼ
	void showallapply();
	//����ԤԼ
	void searchapply();
	//���ԤԼ
	void validorder();

	int m_id;
};