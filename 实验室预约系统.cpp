#include<iostream>
#include<string.h>
#include<fstream>
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

using namespace std;

void managerMenu(Identity*& m)            //����Ա�˵�
{
	while (1)
	{
		m->menu();

		Manager* manager = (Manager*)m;   //ǿת�����ڵ������ຯ��
		int choice;
	FLAG:
		cin >> choice;     //�����û�ѡ��
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "��������ȷ����ֵ��";
			goto FLAG;
		}
		system("pause");
		system("cls");
	}
}

void studentMenu(Identity*& s)            //ѧ���˵�
{
	while (1)
	{
		s->menu();

		Student* student = (Student*)s;
		int choice;
	FLAG:
		cin >> choice;     //�����û�ѡ��
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "��������ȷ����ֵ��";
			goto FLAG;
		}
		system("pause");
		system("cls");
	}
}

void teacherMenu(Identity*& s)                //��ʦ�˵�
{
	while (1)
	{
		s->menu();

		Teacher* teacher = (Teacher*)s;
		int choice;
	FLAG:
		cin >> choice;     //�����û�ѡ��
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "��������ȷ����ֵ��";
			goto FLAG;
		}
		system("pause");
		system("cls");
	}
}

void login(string filename, int n)           //��¼
{
	Identity* person = NULL;

	fstream f;
	f.open(filename, ios::in);
	if (!f)
	{
		cout << "�ļ�������" << endl;
		exit(0);
	}

	int id = 0;
	string name;
	string password;

	if (n == 1)
	{
		cout << "������ѧ�ţ�";
		cin >> id;
	}
	else if (n == 2)
	{
		cout << "�����빤�ţ�";
		cin >> id;
	}
	cout << "�������û�����";
	cin >> name;
	cout << "���������룺";
	cin >> password;
	//��¼��֤
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
				cout << "��¼�ɹ�" << endl;
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
				cout << "��¼�ɹ�" << endl;
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
				cout << "��¼�ɹ�" << endl;
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
	cout << "��¼��֤ʧ��" << endl;

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
		cout << "\t\t*******   ��ӭʹ��ʵ����ԤԼϵͳ   *******" << endl;
		cout << "\t\t******************************************" << endl;
		cout << endl;
		cout << "\t\t-----------------  ��¼  -----------------" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              1.ѧ����¼                |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              2.��ʦ��¼                |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              3.����Ա��¼              |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              0.�˳�ϵͳ                |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t------------------------------------------" << endl;
		cout << "�����룺";
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
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			cout << "��������ȷ����ֵ��";
			goto FLAG;
		}
	}


	system("pause");
	return 0;
}