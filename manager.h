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
	//添加账号
	void addperson();
	//查看账号状态
	void showperson();
	//查看实验室信息
	void showlab();
	//清空预约记录
	void clearfile();
	//初始化学生，老师容器
	void initvector();
	//显示学生，老师数量
	void shownum();
	//检测是否重复
	bool repeat(int id, int type);
	//查找信息
	void search();

	vector<Student> stus;
	vector<Teacher> teas;
};
