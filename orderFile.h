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
	void update();            //更新预约信息
	void updatelab();         //更新实验室容量信息

	map<int, int> lab;        //存放实验室信息
	map<int, map<string, string>> order;      //存放预约信息
	int size;                 //预约数
};