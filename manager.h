#pragma once
#include<iostream>
#include<vector>
#include"identity.h"
#include"teacher.h"
#include"student.h"

using namespace std;

class Manager :public Identity
{
public:
	Manager();
	Manager(string name, string password);
	virtual void menu();
	//����˺�
	void addperson();
	//�鿴�˺�״̬
	void showperson();
	//�鿴ʵ������Ϣ
	void showlab();
	//���ԤԼ��¼
	void clearfile();
	//��ʼ��ѧ������ʦ����
	void initvector();
	//��ʾѧ������ʦ����
	void shownum();
	//����Ƿ��ظ�
	bool repeat(int id, int type);
	//������Ϣ
	void search();

	vector<Student> stus;
	vector<Teacher> teas;
};
