#include<fstream>
#include<stdlib.h>
#include"student.h"
#include"globalFile.h"
#include"orderFile.h"

Student::Student()
{
	m_id = 0;
	m_name = "";
	m_password = "";
}

Student::Student(int id, string name, string password)
{
	m_id = id;
	m_name = name;
	m_password = password;
}

void Student::menu()
{
	cout << "欢迎  学生：  " << m_name << endl;
	cout << "您可以：" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             1. 申请预约                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            2. 查看我的预约             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             3. 取消预约                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|        4. 删除已取消的预约记录         |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             0. 注销登录                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "请输入：";
}

void Student::apply()            //申请预约
{
	Orderfile of;
	int labid, day, time;
FLAG:
	cout << "请选择实验：" << endl;
	cout << "1. 牛顿环" << "  剩余量：" << of.lab[1] << endl;
	cout << "2. 单摆测重力加速度" << "  剩余量：" << of.lab[2] << endl;
	cout << "3. 惠斯通电桥测电阻" << "  剩余量：" << of.lab[3] << endl;
	cout << "4. 光电效应" << "  剩余量：" << of.lab[4] << endl;
	cout << "请输入：" << endl;
FLAG1:
	cin >> labid;
	if (labid != 1 && labid != 2 && labid != 3 && labid != 4)
	{
		cout << "请输入正确的数值：" << endl;
		goto FLAG1;
	}

	of.lab[labid]--;
	if (of.lab[labid] < 0)
	{
		cout << "该实验已满员，请重新选择：" << endl;
		of.lab[labid]++;
		goto FLAG1;
	}
	of.updatelab();

	cout << "请选择时间：" << endl;
	cout << "1. 星期一" << endl;
	cout << "2. 星期二" << endl;
	cout << "3. 星期三" << endl;
	cout << "4. 星期四" << endl;
	cout << "5. 星期五" << endl;
	cout << "请输入：" << endl;
FLAG2:
	cin >> day;
	if (day != 1 && day != 2 && day != 3 && day != 4 && day != 5)
	{
		cout << "请输入正确的数值：" << endl;
		goto FLAG2;
	}
	cout << "1. 1、2节" << endl;
	cout << "2. 3、4节" << endl;
	cout << "3. 5、6节" << endl;
	cout << "4. 7、8节" << endl;
	cout << "请输入：" << endl;
FLAG3:
	cin >> time;
	if (time != 1 && time != 2 && time != 3 && time != 4)
	{
		cout << "请输入正确的数值：" << endl;
		goto FLAG3;
	}

	for (int i = 0; i < of.size; i++)
	{
		if (atoi(of.order[i]["labid"].c_str()) == labid &&
			atoi(of.order[i]["day"].c_str()) == day &&
			atoi(of.order[i]["time"].c_str()) == time &&
			atoi(of.order[i]["stuid"].c_str()) == m_id &&
			of.order[i]["stuname"] == m_name &&
			of.order[i]["status"] != "-1")
		{
			of.lab[labid]++;
			cout << "该预约已存在，请重新选择" << endl;
			goto FLAG;
		}
	}

	//写入申请文件
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "labid：" << labid << endl;
	ofs << "day：" << day << endl;
	ofs << "time：" << time << endl;
	ofs << "stuid：" << m_id << endl;
	ofs << "stuname：" << m_name << endl;
	ofs << "status：" << 1 << endl;
	ofs.close();

	cout << "申请成功，等待老师审核" << endl;
}

void printinfo(map<string, string> m)    //打印预约信息
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
	if (m["time"] == "1")
	{
		cout << "1、2节" << endl;
	}
	if (m["time"] == "2")
	{
		cout << "3、4节" << endl;
	}
	if (m["time"] == "3")
	{
		cout << "5、6节" << endl;
	}
	if (m["time"] == "4")
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

void Student::showmyapply()      //显示自身预约
{
	Orderfile of;
	int i, flag;
	flag = 0;
	cout << "您的预约信息为：" << endl;
	for (i = 0; i < of.size; i++)
	{
		if (of.order[i]["stuname"] == m_name)
		{
			cout << endl;
			flag++;
			printinfo(of.order[i]);
		}
	}
	if (flag == 0)
	{
		cout << endl << "您尚未申请预约" << endl;
	}
	cout << endl;
}

void Student::cancelapply()            //取消预约
{
	Orderfile of;
	int flag = 0;
	cout << "可取消的预约如下：" << endl;
	for (int i = 0; i < of.size; i++)
	{
		if (of.order[i]["status"] == "1" || of.order[i]["status"] == "2")
		{
			flag++;
			cout << endl << "预约" << flag << "：" << endl;
			printinfo(of.order[i]);
		}
	}
	if (flag == 0)
	{
		cout << "暂无可取消的预约" << endl;
		return;
	}
	cout << endl << "请输入将要取消的预约编号：";
	int c;
	FLAG:
	cin >> c;
	if (c<1 || c>flag)
	{
		cout << "请输入正确的编号：";
		goto FLAG;
	}
	flag = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.order[i]["status"] == "1" || of.order[i]["status"] == "2")
		{
			flag++;
			if (flag == c)
			{
				of.order[i]["status"] = "-1";
				int n = atoi(of.order[i]["labid"].c_str());
				of.lab[n]++;
				of.updatelab();
				break;
			}
		}
	}
	cout << "预约取消成功" << endl;
	of.update();
}

void Student::deletecancel()              //删除已取消的预约记录
{
	cout << "以下是将要删除的预约记录：" << endl;
	Orderfile of;
	int flag = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.order[i]["status"] == "-1")
		{
			flag++;
			cout << endl;
			printinfo(of.order[i]);
		}
	}
	if (flag == 0)
	{
		cout << "暂无可取消的预约" << endl;
		return;
	}
	cout << endl << "1. 确认  0. 取消" << endl;
	int c;
	FLAG:
	cin >> c;
	if (c == 1)
	{
		for (int i = 0; i < of.size; i++)
		{
			if (of.order[i]["status"] == "-1")
			{
				of.order.erase(i);
				of.size--;
			}
		}
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		{
			for (auto it = of.order.begin(); it != of.order.end(); it++)
			{
				ofs << "labid：" << it->second["labid"] << endl;
				ofs << "day：" << it->second["day"] << endl;
				ofs << "time：" << it->second["time"] << endl;
				ofs << "stuid：" << it->second["stuid"] << endl;
				ofs << "stuname：" << it->second["stuname"] << endl;
				ofs << "status：" << it->second["status"] << endl;
			}
		}
	}
	else if (c == 0)
	{
		return;
	}
	else
	{
		cout << "请输入正确的数值：" << endl;
		goto FLAG;
	}
	cout << "删除成功" << endl;
}
