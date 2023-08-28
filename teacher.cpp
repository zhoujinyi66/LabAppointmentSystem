#include"teacher.h"
#include"orderFile.h"
#include<stdlib.h>

Teacher::Teacher()
{
	m_id = 0;
	m_name = "";
	m_password = "";
}

Teacher::Teacher(int id, string name, string password)
{
	m_id = id;
	m_name = name;
	m_password = password;
}

void Teacher::menu()
{
	cout << "欢迎  教师：  " << m_name << endl;
	cout << "您可以：" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            1. 显示所有预约             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            2. 查找学生预约             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            3. 审核学生预约             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             0. 注销登录                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "请输入：";
}

void printinfo1(map<string, string> m)      //打印预约信息
{
	cout << "实验名称：";
	if (m["labid"] == "1")
	{
		cout << "牛顿环" << endl;
	}
	if (m["labid"] == "2")
	{
		cout << "单摆测重力加速度" << endl;
	}
	if (m["labid"] == "3")
	{
		cout << "惠斯通电桥测电阻" << endl;
	}
	if (m["labid"] == "4")
	{
		cout << "光电效应" << endl;
	}
	cout << "日期：";
	if (m["day"] == "1")
	{
		cout << "星期一";
	}
	if (m["day"] == "2")
	{
		cout << "星期二";
	}
	if (m["day"] == "3")
	{
		cout << "星期三";
	}
	if (m["day"] == "4")
	{
		cout << "星期四";
	}
	if (m["day"] == "5")
	{
		cout << "星期五";
	}
	cout << ' ';
	if (m["labid"] == "1")
	{
		cout << "1、2节" << endl;
	}
	if (m["labid"] == "2")
	{
		cout << "3、4节" << endl;
	}
	if (m["labid"] == "3")
	{
		cout << "5、6节" << endl;
	}
	if (m["labid"] == "4")
	{
		cout << "7、8节" << endl;
	}
	cout << "预约状态：";
	if (m["status"] == "1")
	{
		cout << "审核中" << endl;
	}
	if (m["status"] == "2")
	{
		cout << "审核通过" << endl;
	}
	if (m["status"] == "3")
	{
		cout << "审核未通过" << endl;
	}
	if (m["status"] == "-1")
	{
		cout << "预约已取消" << endl;
	}
}

void Teacher::showallapply()            //显示所有预约信息
{
	int i;
	Orderfile of;
	cout << "全部学生的预约信息如下：" << endl;
	for (i = 0; i < of.size; i++)
	{
		cout << endl;
		cout << "学号：" << of.order[i]["stuid"] << ' ' << "姓名：" << of.order[i]["stuname"] << endl;
		printinfo1(of.order[i]);
	}
	if (i == 0)
	{
		cout << endl << "暂无学生预约实验" << endl;
	}
}

void Teacher::searchapply()                 //查找预约信息
{
	cout << "请选择查找方式：" << endl;
	cout << "1. 姓名  2. 学号" << endl;
	Orderfile of;
	int c;
	int flag = 0;
	FLAG:
	cin >> c;
	if (c == 1)
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < of.size; i++)
		{
			if (of.order[i]["stuname"] == name)
			{
				flag++;
				cout << "学号：" << of.order[i]["stuid"] << ' ' << "姓名：" << of.order[i]["stuname"] << endl;
				cout << "该学生预约信息为：" << endl;
				cout << endl;
				printinfo1(of.order[i]);
			}
		}
		if (flag == 0)
		{
			cout << endl << "未找到该学生的预约信息" << endl;
		}
	}
	else if (c == 2)
	{
		cout << "请输入学号：" << endl;
		string id;
		cin >> id;
		for (int i = 0; i < of.size; i++)
		{
			if (of.order[i]["stuid"] == id)
			{
				flag++;
				cout << "学号：" << of.order[i]["stuid"] << ' ' << "姓名：" << of.order[i]["stuname"] << endl;
				cout << "该学生预约信息为：" << endl;
				cout << endl;
				printinfo1(of.order[i]);
			}
		}
		if (flag == 0)
		{
			cout << endl << "未找到该学生的预约信息" << endl;
		}
	}
	else
	{
		cout << "请输入正确的数值：";
		goto FLAG;
	}
}

void Teacher::validorder()                   //审核预约
{
	Orderfile of;
	cout << "可审核的预约如下：" << endl;
	int flag = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.order[i]["status"] == "1")
		{
			flag++;
			cout << endl << "预约" << flag << "：" << endl;
			cout << "学号：" << of.order[i]["stuid"] << ' ' << "姓名：" << of.order[i]["stuname"] << endl;
			printinfo1(of.order[i]);
			cout << endl;
		}
	}
	if (flag == 0)
	{
		cout << endl << "暂无可审核的预约" << endl;
		return;
	}
	int c1, c2;
	cout << "请输入将要操作的预约编号：";
	FLAG1:
	cin >> c1;
	if (c1<1 || c1>flag)
	{
		cout << "请输入正确的编号：";
		goto FLAG1;
	}
	cout << "请选择：" << endl;
	cout << "1. 通过  2. 不通过" << endl;
	FLAG2:
	cin >> c2;
	if (c2 != 1 && c2 != 2)
	{
		cout << "请输入正确的编号：";
		goto FLAG2;
	}
	flag = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.order[i]["status"] == "1")
		{
			flag++;
			if (flag == c1)
			{
				if (c2 == 1)
				{
					of.order[i]["status"] = "2";
				}
				else if (c2 == 2)
				{
					of.order[i]["status"] = "3";
					int n = atoi(of.order[i]["labid"].c_str());
					of.lab[n]++;
					of.updatelab();
				}
				break;
			}
		}
	}
	cout << "操作成功" << endl;
	of.update();
}
