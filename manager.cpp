#include<fstream>
#include<algorithm>
#include"manager.h"
#include"student.h"
#include"teacher.h"
#include"globalFile.h"
#include"orderFile.h"

Manager::Manager()
{
	m_name = "";
	m_password = "";
	initvector();
}

Manager::Manager(string name, string password)
{
	m_name = name;
	m_password = password;
	initvector();
}

void Manager::menu()
{
	cout << "欢迎  管理员：  " << m_name << endl;
	cout << "您可以：" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|           1. 添加新的账号              |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|           2. 查看已有账号              |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|          3. 查看实验室信息             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|           4. 清空所有预约              |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|         5. 显示已添加的人员数          |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            6. 查找人员信息             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             0. 注销登录                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "请输入：";
}

void Manager::addperson()      //添加新的账号 
{
	cout << "请选择要添加账号的类型：" << endl;
	cout << "   1.学生     2.教师   " << endl;
	cout << "请输入：" << endl;
	string filename;     //定义两个将要生成的提示
	string tipseed;
	int choice;
	FLAG:
	cin >> choice;
	switch (choice)
	{
	case 1:
		filename = STUDENT_FILE;
		tipseed = "请输入学号：";
		break;
	case 2:
		filename = TEACHER_FILE;	
		tipseed = "请输入工号：";
		break;
	default:
		cout << "请输入正确的数值：";
		goto FLAG;
	}
	fstream f;
	f.open(filename, ios::out | ios::app);
	if (!f)
	{
		cout << "文件读取失败" << endl;
		return;
	}
	int fid;
	string fname;
	string fpassword;
	cout << tipseed;
	FLAG1:
	cin >> fid;
	if (repeat(fid, choice))
	{
		if (choice == 1)
		{
			cout << "学号重复，请重新输入：" << endl;
		}
		else
		{
			cout << "工号重复，请重新输入：" << endl;
		}
		goto FLAG1;
	}
	cout << "请输入姓名：";
	cin >> fname;
	cout << "请输入密码：";
	cin >> fpassword;
	f << fid << ' ' << fname << ' ' << fpassword << endl;   //写入文件
	cout << "添加成功" << endl;
	f.close();
	initvector();
}

void printstudent(Student& s)
{
	cout << "学号：" << s.m_id << "  姓名：" << s.m_name << "  密码：" << s.m_password << endl;

}

void printteacher(Teacher& t)
{
	cout << "工号：" << t.m_id << "  姓名：" << t.m_name << "  密码：" << t.m_password << endl;
}

void Manager::showperson()     //查看已有账号
{
	cout << "学生信息如下：" << endl;
	for_each(stus.begin(), stus.end(), printstudent);
	cout << endl;
	cout << "老师信息如下：" << endl;
	for_each(teas.begin(), teas.end(), printteacher);
}

void Manager::showlab()       //查看实验室信息
{
	cout << "实验室信息如下：" << endl;
	Orderfile of;
	cout << "1. 牛顿环   " << "剩余容量：" << of.lab[1] << endl;
	cout << "2. 单摆测重力加速度   " << "剩余容量：" << of.lab[2] << endl;
	cout << "3. 惠斯通电桥测电阻   " << "剩余容量：" << of.lab[3] << endl;
	cout << "4. 光电效应   " << "剩余容量：" << of.lab[4] << endl;
}

void Manager::clearfile()      //清空所有预约
{
	cout << "是否确定清空预约？" << endl;
	cout << "1. 确认   0. 取消" << endl;
	int c;
	FLAG:
	cin >> c;
	if (c == 1)
	{
		ofstream f;
		f.open(ORDER_FILE, ios::trunc);
		if (!f)
		{
			cout << "文件读取失败" << endl;
			return;
		}
		f.close();
		cout << "清空成功" << endl;

		Orderfile of;
		of.lab[1] = 30;
		of.lab[2] = 30;
		of.lab[3] = 40;
		of.lab[4] = 50;
		of.updatelab();
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
}

void Manager::initvector()            //初始化学生，教师容器
{
	stus.clear();
	teas.clear();

	//将学生信息存入容器
	ifstream f1;
	f1.open(STUDENT_FILE, ios::in);
	if (!f1)
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (f1 >> s.m_id && f1 >> s.m_name && f1 >> s.m_password)
	{
		stus.push_back(s);
	}
	f1.close();

	//将老师信息存入容器
	ifstream f2;
	f2.open(TEACHER_FILE, ios::in);
	if (!f2)
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (f2 >> t.m_id && f2 >> t.m_name && f2 >> t.m_password)
	{
		teas.push_back(t);
	}
	f2.close();
}

void Manager::shownum()
{
	cout << "当前学生数量为： " << this->stus.size() << endl;
	cout << "老师数量为： " << this->teas.size() << endl;
}

bool Manager::repeat(int id, int type)        //检测是否重复
{
	if (type == 1)
	{
		for (auto it : stus)
		{
			if (it.m_id == id)
				return true;
		}
	}
	else
	{
		for (auto it : teas)
		{
			if (it.m_id == id)
				return true;
		}
	}
	return false;
}

void Manager::search()              //查找人员
{
	cout << " 请选择您要查找的对象：" << endl;
	cout << "  1. 学生    2. 教师" << endl;
	int choice;
	FLAG:
	cin >> choice;
	if (choice == 1)
	{
		cout << " 请选择您要查找的方式：" << endl;
		cout << "  1. 学号    2. 姓名" << endl;
		int s;
		FLAG1:
		cin >> s;
		if (s == 1)
		{
			int id;
			cout << "请输入学号：";
			cin >> id;
			int flag = 0;
			for (auto it : stus)
			{
				if (it.m_id == id)
				{
					flag++;
					cout << "该学生信息为：";
					printstudent(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "未找到该学生" << endl;
			}
		}
		else if (s == 2)
		{
			string name;
			cout << "请输入姓名：";
			cin >> name;
			int flag = 0;
			for (auto it : stus)
			{
				if (it.m_name == name)
				{
					flag++;
					cout << "该学生信息为：";
					printstudent(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "未找到该学生" << endl;
			}
		}
		else
		{
			cout << "请输入正确的数值：";
			goto FLAG1;
		}
	}
	else if (choice == 2)
	{
		cout << " 请选择您要查找的方式：" << endl;
		cout << "  1. 工号    2. 姓名" << endl;
		int s;
		FLAG2:
		cin >> s;
		if (s == 1)
		{
			int id;
			cout << "请输入工号：";
			cin >> id;
			int flag = 0;
			for (auto it : teas)
			{
				if (it.m_id == id)
				{
					flag++;
					cout << "该教师信息为：";
					printteacher(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "未找到该教师" << endl;
			}
		}
		else if (s == 2)
		{
			string name;
			cout << "请输入姓名：";
			cin >> name;
			int flag = 0;
			for (auto it : teas)
			{
				if (it.m_name == name)
				{
					flag++;
					cout << "该教师信息为：";
					printteacher(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "未找到该教师" << endl;
			}
		}
		else
		{
			cout << "请输入正确的数值：";
			goto FLAG2;
		}
	}
	else
	{
		cout << "请输入正确的数值：";
		goto FLAG;
	}
}