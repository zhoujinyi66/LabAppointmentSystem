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
	//����ԤԼ
	void apply();
	//����ԤԼ
	void showmyapply();
	//ȡ��ԤԼ
	void cancelapply();
	//ɾ����ȡ����ԤԼ��¼
	void deletecancel();

	int m_id;
};