#pragma once
#include<iostream>
#include<map>
#include<string>
#include"globalFile.h"

using namespace std;

class Orderfile
{
public:
	Orderfile();
	void update();            //����ԤԼ��Ϣ
	void updatelab();         //����ʵ����������Ϣ

	map<int, int> lab;        //���ʵ������Ϣ
	map<int, map<string, string>> order;      //���ԤԼ��Ϣ
	int size;                 //ԤԼ��
};