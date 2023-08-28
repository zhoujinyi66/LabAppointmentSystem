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
	cout << "��ӭ  ѧ����  " << m_name << endl;
	cout << "�����ԣ�" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             1. ����ԤԼ                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|            2. �鿴�ҵ�ԤԼ             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             3. ȡ��ԤԼ                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|        4. ɾ����ȡ����ԤԼ��¼         |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|             0. ע����¼                |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "�����룺";
}

void Student::apply()            //����ԤԼ
{
	Orderfile of;
	int labid, day, time;
FLAG:
	cout << "��ѡ��ʵ�飺" << endl;
	cout << "1. ţ�ٻ�" << "  ʣ������" << of.lab[1] << endl;
	cout << "2. ���ڲ��������ٶ�" << "  ʣ������" << of.lab[2] << endl;
	cout << "3. ��˹ͨ���Ų����" << "  ʣ������" << of.lab[3] << endl;
	cout << "4. ���ЧӦ" << "  ʣ������" << of.lab[4] << endl;
	cout << "�����룺" << endl;
FLAG1:
	cin >> labid;
	if (labid != 1 && labid != 2 && labid != 3 && labid != 4)
	{
		cout << "��������ȷ����ֵ��" << endl;
		goto FLAG1;
	}

	of.lab[labid]--;
	if (of.lab[labid] < 0)
	{
		cout << "��ʵ������Ա��������ѡ��" << endl;
		of.lab[labid]++;
		goto FLAG1;
	}
	of.updatelab();

	cout << "��ѡ��ʱ�䣺" << endl;
	cout << "1. ����һ" << endl;
	cout << "2. ���ڶ�" << endl;
	cout << "3. ������" << endl;
	cout << "4. ������" << endl;
	cout << "5. ������" << endl;
	cout << "�����룺" << endl;
FLAG2:
	cin >> day;
	if (day != 1 && day != 2 && day != 3 && day != 4 && day != 5)
	{
		cout << "��������ȷ����ֵ��" << endl;
		goto FLAG2;
	}
	cout << "1. 1��2��" << endl;
	cout << "2. 3��4��" << endl;
	cout << "3. 5��6��" << endl;
	cout << "4. 7��8��" << endl;
	cout << "�����룺" << endl;
FLAG3:
	cin >> time;
	if (time != 1 && time != 2 && time != 3 && time != 4)
	{
		cout << "��������ȷ����ֵ��" << endl;
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
			cout << "��ԤԼ�Ѵ��ڣ�������ѡ��" << endl;
			goto FLAG;
		}
	}

	//д�������ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "labid��" << labid << endl;
	ofs << "day��" << day << endl;
	ofs << "time��" << time << endl;
	ofs << "stuid��" << m_id << endl;
	ofs << "stuname��" << m_name << endl;
	ofs << "status��" << 1 << endl;
	ofs.close();

	cout << "����ɹ����ȴ���ʦ���" << endl;
}

void printinfo(map<string, string> m)    //��ӡԤԼ��Ϣ
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
	if (m["time"] == "1")
	{
		cout << "1��2��" << endl;
	}
	if (m["time"] == "2")
	{
		cout << "3��4��" << endl;
	}
	if (m["time"] == "3")
	{
		cout << "5��6��" << endl;
	}
	if (m["time"] == "4")
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

void Student::showmyapply()      //��ʾ����ԤԼ
{
	Orderfile of;
	int i, flag;
	flag = 0;
	cout << "����ԤԼ��ϢΪ��" << endl;
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
		cout << endl << "����δ����ԤԼ" << endl;
	}
	cout << endl;
}

void Student::cancelapply()            //ȡ��ԤԼ
{
	Orderfile of;
	int flag = 0;
	cout << "��ȡ����ԤԼ���£�" << endl;
	for (int i = 0; i < of.size; i++)
	{
		if (of.order[i]["status"] == "1" || of.order[i]["status"] == "2")
		{
			flag++;
			cout << endl << "ԤԼ" << flag << "��" << endl;
			printinfo(of.order[i]);
		}
	}
	if (flag == 0)
	{
		cout << "���޿�ȡ����ԤԼ" << endl;
		return;
	}
	cout << endl << "�����뽫Ҫȡ����ԤԼ��ţ�";
	int c;
	FLAG:
	cin >> c;
	if (c<1 || c>flag)
	{
		cout << "��������ȷ�ı�ţ�";
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
	cout << "ԤԼȡ���ɹ�" << endl;
	of.update();
}

void Student::deletecancel()              //ɾ����ȡ����ԤԼ��¼
{
	cout << "�����ǽ�Ҫɾ����ԤԼ��¼��" << endl;
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
		cout << "���޿�ȡ����ԤԼ" << endl;
		return;
	}
	cout << endl << "1. ȷ��  0. ȡ��" << endl;
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
				ofs << "labid��" << it->second["labid"] << endl;
				ofs << "day��" << it->second["day"] << endl;
				ofs << "time��" << it->second["time"] << endl;
				ofs << "stuid��" << it->second["stuid"] << endl;
				ofs << "stuname��" << it->second["stuname"] << endl;
				ofs << "status��" << it->second["status"] << endl;
			}
		}
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
	cout << "ɾ���ɹ�" << endl;
}
