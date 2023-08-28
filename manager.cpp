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
	cout << "��ӭ  ����Ա��  " << m_name << endl;
	cout << "�����ԣ�" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|           1. ����µ��˺�              |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|           2. �鿴�����˺�              |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|          3. �鿴ʵ������Ϣ             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|           4. �������ԤԼ              |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|         5. ��ʾ����ӵ���Ա��          |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            6. ������Ա��Ϣ             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             0. ע����¼                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "�����룺";
}

void Manager::addperson()      //����µ��˺� 
{
	cout << "��ѡ��Ҫ����˺ŵ����ͣ�" << endl;
	cout << "   1.ѧ��     2.��ʦ   " << endl;
	cout << "�����룺" << endl;
	string filename;     //����������Ҫ���ɵ���ʾ
	string tipseed;
	int choice;
	FLAG:
	cin >> choice;
	switch (choice)
	{
	case 1:
		filename = STUDENT_FILE;
		tipseed = "������ѧ�ţ�";
		break;
	case 2:
		filename = TEACHER_FILE;	
		tipseed = "�����빤�ţ�";
		break;
	default:
		cout << "��������ȷ����ֵ��";
		goto FLAG;
	}
	fstream f;
	f.open(filename, ios::out | ios::app);
	if (!f)
	{
		cout << "�ļ���ȡʧ��" << endl;
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
			cout << "ѧ���ظ������������룺" << endl;
		}
		else
		{
			cout << "�����ظ������������룺" << endl;
		}
		goto FLAG1;
	}
	cout << "������������";
	cin >> fname;
	cout << "���������룺";
	cin >> fpassword;
	f << fid << ' ' << fname << ' ' << fpassword << endl;   //д���ļ�
	cout << "��ӳɹ�" << endl;
	f.close();
	initvector();
}

void printstudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_id << "  ������" << s.m_name << "  ���룺" << s.m_password << endl;

}

void printteacher(Teacher& t)
{
	cout << "���ţ�" << t.m_id << "  ������" << t.m_name << "  ���룺" << t.m_password << endl;
}

void Manager::showperson()     //�鿴�����˺�
{
	cout << "ѧ����Ϣ���£�" << endl;
	for_each(stus.begin(), stus.end(), printstudent);
	cout << endl;
	cout << "��ʦ��Ϣ���£�" << endl;
	for_each(teas.begin(), teas.end(), printteacher);
}

void Manager::showlab()       //�鿴ʵ������Ϣ
{
	cout << "ʵ������Ϣ���£�" << endl;
	Orderfile of;
	cout << "1. ţ�ٻ�   " << "ʣ��������" << of.lab[1] << endl;
	cout << "2. ���ڲ��������ٶ�   " << "ʣ��������" << of.lab[2] << endl;
	cout << "3. ��˹ͨ���Ų����   " << "ʣ��������" << of.lab[3] << endl;
	cout << "4. ���ЧӦ   " << "ʣ��������" << of.lab[4] << endl;
}

void Manager::clearfile()      //�������ԤԼ
{
	cout << "�Ƿ�ȷ�����ԤԼ��" << endl;
	cout << "1. ȷ��   0. ȡ��" << endl;
	int c;
	FLAG:
	cin >> c;
	if (c == 1)
	{
		ofstream f;
		f.open(ORDER_FILE, ios::trunc);
		if (!f)
		{
			cout << "�ļ���ȡʧ��" << endl;
			return;
		}
		f.close();
		cout << "��ճɹ�" << endl;

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
		cout << "��������ȷ����ֵ��" << endl;
		goto FLAG;
	}
}

void Manager::initvector()            //��ʼ��ѧ������ʦ����
{
	stus.clear();
	teas.clear();

	//��ѧ����Ϣ��������
	ifstream f1;
	f1.open(STUDENT_FILE, ios::in);
	if (!f1)
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (f1 >> s.m_id && f1 >> s.m_name && f1 >> s.m_password)
	{
		stus.push_back(s);
	}
	f1.close();

	//����ʦ��Ϣ��������
	ifstream f2;
	f2.open(TEACHER_FILE, ios::in);
	if (!f2)
	{
		cout << "�ļ���ȡʧ��" << endl;
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
	cout << "��ǰѧ������Ϊ�� " << this->stus.size() << endl;
	cout << "��ʦ����Ϊ�� " << this->teas.size() << endl;
}

bool Manager::repeat(int id, int type)        //����Ƿ��ظ�
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

void Manager::search()              //������Ա
{
	cout << " ��ѡ����Ҫ���ҵĶ���" << endl;
	cout << "  1. ѧ��    2. ��ʦ" << endl;
	int choice;
	FLAG:
	cin >> choice;
	if (choice == 1)
	{
		cout << " ��ѡ����Ҫ���ҵķ�ʽ��" << endl;
		cout << "  1. ѧ��    2. ����" << endl;
		int s;
		FLAG1:
		cin >> s;
		if (s == 1)
		{
			int id;
			cout << "������ѧ�ţ�";
			cin >> id;
			int flag = 0;
			for (auto it : stus)
			{
				if (it.m_id == id)
				{
					flag++;
					cout << "��ѧ����ϢΪ��";
					printstudent(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "δ�ҵ���ѧ��" << endl;
			}
		}
		else if (s == 2)
		{
			string name;
			cout << "������������";
			cin >> name;
			int flag = 0;
			for (auto it : stus)
			{
				if (it.m_name == name)
				{
					flag++;
					cout << "��ѧ����ϢΪ��";
					printstudent(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "δ�ҵ���ѧ��" << endl;
			}
		}
		else
		{
			cout << "��������ȷ����ֵ��";
			goto FLAG1;
		}
	}
	else if (choice == 2)
	{
		cout << " ��ѡ����Ҫ���ҵķ�ʽ��" << endl;
		cout << "  1. ����    2. ����" << endl;
		int s;
		FLAG2:
		cin >> s;
		if (s == 1)
		{
			int id;
			cout << "�����빤�ţ�";
			cin >> id;
			int flag = 0;
			for (auto it : teas)
			{
				if (it.m_id == id)
				{
					flag++;
					cout << "�ý�ʦ��ϢΪ��";
					printteacher(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "δ�ҵ��ý�ʦ" << endl;
			}
		}
		else if (s == 2)
		{
			string name;
			cout << "������������";
			cin >> name;
			int flag = 0;
			for (auto it : teas)
			{
				if (it.m_name == name)
				{
					flag++;
					cout << "�ý�ʦ��ϢΪ��";
					printteacher(it);
					break;
				}
			}
			if (flag == 0)
			{
				cout << "δ�ҵ��ý�ʦ" << endl;
			}
		}
		else
		{
			cout << "��������ȷ����ֵ��";
			goto FLAG2;
		}
	}
	else
	{
		cout << "��������ȷ����ֵ��";
		goto FLAG;
	}
}