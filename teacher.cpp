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
	cout << "��ӭ  ��ʦ��  " << m_name << endl;
	cout << "�����ԣ�" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            1. ��ʾ����ԤԼ             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            2. ����ѧ��ԤԼ             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            3. ���ѧ��ԤԼ             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             0. ע����¼                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "�����룺";
}

void printinfo1(map<string, string> m)      //��ӡԤԼ��Ϣ
{
	cout << "ʵ�����ƣ�";
	if (m["labid"] == "1")
	{
		cout << "ţ�ٻ�" << endl;
	}
	if (m["labid"] == "2")
	{
		cout << "���ڲ��������ٶ�" << endl;
	}
	if (m["labid"] == "3")
	{
		cout << "��˹ͨ���Ų����" << endl;
	}
	if (m["labid"] == "4")
	{
		cout << "���ЧӦ" << endl;
	}
	cout << "���ڣ�";
	if (m["day"] == "1")
	{
		cout << "����һ";
	}
	if (m["day"] == "2")
	{
		cout << "���ڶ�";
	}
	if (m["day"] == "3")
	{
		cout << "������";
	}
	if (m["day"] == "4")
	{
		cout << "������";
	}
	if (m["day"] == "5")
	{
		cout << "������";
	}
	cout << ' ';
	if (m["labid"] == "1")
	{
		cout << "1��2��" << endl;
	}
	if (m["labid"] == "2")
	{
		cout << "3��4��" << endl;
	}
	if (m["labid"] == "3")
	{
		cout << "5��6��" << endl;
	}
	if (m["labid"] == "4")
	{
		cout << "7��8��" << endl;
	}
	cout << "ԤԼ״̬��";
	if (m["status"] == "1")
	{
		cout << "�����" << endl;
	}
	if (m["status"] == "2")
	{
		cout << "���ͨ��" << endl;
	}
	if (m["status"] == "3")
	{
		cout << "���δͨ��" << endl;
	}
	if (m["status"] == "-1")
	{
		cout << "ԤԼ��ȡ��" << endl;
	}
}

void Teacher::showallapply()            //��ʾ����ԤԼ��Ϣ
{
	int i;
	Orderfile of;
	cout << "ȫ��ѧ����ԤԼ��Ϣ���£�" << endl;
	for (i = 0; i < of.size; i++)
	{
		cout << endl;
		cout << "ѧ�ţ�" << of.order[i]["stuid"] << ' ' << "������" << of.order[i]["stuname"] << endl;
		printinfo1(of.order[i]);
	}
	if (i == 0)
	{
		cout << endl << "����ѧ��ԤԼʵ��" << endl;
	}
}

void Teacher::searchapply()                 //����ԤԼ��Ϣ
{
	cout << "��ѡ����ҷ�ʽ��" << endl;
	cout << "1. ����  2. ѧ��" << endl;
	Orderfile of;
	int c;
	int flag = 0;
	FLAG:
	cin >> c;
	if (c == 1)
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < of.size; i++)
		{
			if (of.order[i]["stuname"] == name)
			{
				flag++;
				cout << "ѧ�ţ�" << of.order[i]["stuid"] << ' ' << "������" << of.order[i]["stuname"] << endl;
				cout << "��ѧ��ԤԼ��ϢΪ��" << endl;
				cout << endl;
				printinfo1(of.order[i]);
			}
		}
		if (flag == 0)
		{
			cout << endl << "δ�ҵ���ѧ����ԤԼ��Ϣ" << endl;
		}
	}
	else if (c == 2)
	{
		cout << "������ѧ�ţ�" << endl;
		string id;
		cin >> id;
		for (int i = 0; i < of.size; i++)
		{
			if (of.order[i]["stuid"] == id)
			{
				flag++;
				cout << "ѧ�ţ�" << of.order[i]["stuid"] << ' ' << "������" << of.order[i]["stuname"] << endl;
				cout << "��ѧ��ԤԼ��ϢΪ��" << endl;
				cout << endl;
				printinfo1(of.order[i]);
			}
		}
		if (flag == 0)
		{
			cout << endl << "δ�ҵ���ѧ����ԤԼ��Ϣ" << endl;
		}
	}
	else
	{
		cout << "��������ȷ����ֵ��";
		goto FLAG;
	}
}

void Teacher::validorder()                   //���ԤԼ
{
	Orderfile of;
	cout << "����˵�ԤԼ���£�" << endl;
	int flag = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.order[i]["status"] == "1")
		{
			flag++;
			cout << endl << "ԤԼ" << flag << "��" << endl;
			cout << "ѧ�ţ�" << of.order[i]["stuid"] << ' ' << "������" << of.order[i]["stuname"] << endl;
			printinfo1(of.order[i]);
			cout << endl;
		}
	}
	if (flag == 0)
	{
		cout << endl << "���޿���˵�ԤԼ" << endl;
		return;
	}
	int c1, c2;
	cout << "�����뽫Ҫ������ԤԼ��ţ�";
	FLAG1:
	cin >> c1;
	if (c1<1 || c1>flag)
	{
		cout << "��������ȷ�ı�ţ�";
		goto FLAG1;
	}
	cout << "��ѡ��" << endl;
	cout << "1. ͨ��  2. ��ͨ��" << endl;
	FLAG2:
	cin >> c2;
	if (c2 != 1 && c2 != 2)
	{
		cout << "��������ȷ�ı�ţ�";
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
	cout << "�����ɹ�" << endl;
	of.update();
}
