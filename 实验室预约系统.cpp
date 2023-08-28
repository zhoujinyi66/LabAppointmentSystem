#include<iostream>
#include<string.h>
#include<fstream>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

using namespace std;

void managerMenu(Identity*& m)            //管理员菜单
{
	while (1)
	{
		m->menu();

		Manager* manager = (Manager*)m;   //强转，用于调用子类函数
		int choice;
	FLAG:
		cin >> choice;     //接收用户选项
		switch (choice)
		{
		case(1):
			manager->addperson();
			break;
		case(2):
			manager->showperson();
			break;
		case(3):
			manager->showlab();
			break;
		case(4):
			manager->clearfile();
			break;
		case(5):
			manager->shownum();
			break;
		case(6):
			manager->search();
			break;
		case(0):
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "请输入正确的数值：";
			goto FLAG;
		}
		system("pause");
		system("cls");
	}
}

void studentMenu(Identity*& s)            //学生菜单
{
	while (1)
	{
		s->menu();

		Student* student = (Student*)s;
		int choice;
	FLAG:
		cin >> choice;     //接收用户选项
		switch (choice)
		{
		case(1):
			student->apply();
			break;
		case(2):
			student->showmyapply();
			break;
		case(3):
			student->cancelapply();
			break;
		case(4):
			student->deletecancel();
			break;
		case(0):
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "请输入正确的数值：";
			goto FLAG;
		}
		system("pause");
		system("cls");
	}
}

void teacherMenu(Identity*& s)                //教师菜单
{
	while (1)
	{
		s->menu();

		Teacher* teacher = (Teacher*)s;
		int choice;
	FLAG:
		cin >> choice;     //接收用户选项
		switch (choice)
		{
		case(1):
			teacher->showallapply();
			break;
		case(2):
			teacher->searchapply();
			break;
		case(3):
			teacher->validorder();
			break;
		case(0):
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "请输入正确的数值：";
			goto FLAG;
		}
		system("pause");
		system("cls");
	}
}

void login(string filename, int n)           //登录
{
	Identity* person = NULL;

	fstream f;
	f.open(filename, ios::in);
	if (!f)
	{
		cout << "文件不存在" << endl;
		exit(0);
	}

	int id = 0;
	string name;
	string password;

	if (n == 1)
	{
		cout << "请输入学号：";
		cin >> id;
	}
	else if (n == 2)
	{
		cout << "请输入工号：";
		cin >> id;
	}
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> password;
	//登录验证
	switch (n)
	{
	case 1:
	{
		int fid;
		string fname;
		string fpassword;
		while (f >> fid && f >> fname && f >> fpassword)
		{
			if (fid == id && fname == name && fpassword == password)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				studentMenu(person);
				return;
			}
		}
		break;
	}
	case 2:
	{
		int fid;
		string fname;
		string fpassword;
		while (f >> fid && f >> fname && f >> fpassword)
		{
			if (fid == id && fname == name && fpassword == password)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				teacherMenu(person);
				return;
			}
		}
		break;
	}
	case 3:
	{
		string fname;
		string fpassword;
		while (f >> fname && f >> fpassword)
		{
			if (fname == name && fpassword == password)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);
				managerMenu(person);
				return;
			}
		}
		break;
	}
	}
	cout << "登录验证失败" << endl;

	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;
	while (1)
	{
		cout << "\t\t******************************************" << endl;
		cout << "\t\t*******   欢迎使用实验室预约系统   *******" << endl;
		cout << "\t\t******************************************" << endl;
		cout << endl;
		cout << "\t\t-----------------  登录  -----------------" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              1.学生登录                |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              2.教师登录                |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              3.管理员登录              |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              0.退出系统                |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t------------------------------------------" << endl;
		cout << "请输入：";
		FLAG:
		cin >> select;
		switch (select)
		{
		case 1:
			login(STUDENT_FILE, 1);
			break;
		case 2:
			login(TEACHER_FILE, 2);
			break;
		case 3:
			login(MANAGER_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			cout << "请输入正确的数值：";
			goto FLAG;
		}
	}


	system("pause");
	return 0;
}