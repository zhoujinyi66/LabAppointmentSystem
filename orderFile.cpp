#include"orderFile.h"
#include<fstream>

void divide(map<string, string> &valuemap, string &s)     //�ָ�ð��ǰ����ַ���
{
	string key, value;
	int pos = s.find("��");
	key = s.substr(0, pos);
	value = s.substr(pos + 2, s.size() - pos - 1);   //"��"Ϊ�����ַ���posλ����Ϊ���ֽ�
	valuemap.insert(make_pair(key, value));
}

Orderfile::Orderfile()
{
	size = 0;

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string labid;
	string day;
	string time;
	string stuid;
	string stuname;
	string status;

	while (ifs >> labid && ifs >> day && ifs >> time && ifs >> stuid && ifs >> stuname && ifs >> status)
	{
		map<string, string> valuemap;
		divide(valuemap, labid);
		divide(valuemap, day);
		divide(valuemap, time);
		divide(valuemap, stuid);
		divide(valuemap, stuname);
		divide(valuemap, status);
		order.insert(make_pair(size, valuemap));
		size++;
	}

	ifs.close();

	ifstream ifs1;                             //��¼ÿ��ʵ��ÿ�ܵ��������
	ifs1.open(LAB_FILE, ios::in);

	int key, value;
	while (ifs1 >> key && ifs1 >> value)
	{
		lab.insert(make_pair(key, value));
	}

	ifs1.close();
}

void Orderfile::update()           //����ԤԼ��Ϣ
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < size; i++)
	{
		ofs << "labid��" << order[i]["labid"] << endl;
		ofs << "day��" << order[i]["day"] << endl;
		ofs << "time��" << order[i]["time"] << endl;
		ofs << "stuid��" << order[i]["stuid"] << endl;
		ofs << "stuname��" << order[i]["stuname"] << endl;
		ofs << "status��" << order[i]["status"] << endl;
	}

	ofs.close();
}

void Orderfile::updatelab()         //����ʵ����������Ϣ
{
	ofstream ofs;
	ofs.open(LAB_FILE, ios::out | ios::trunc);

	for (int i = 1; i <= lab.size(); i++)
	{
		ofs << i << ' ' << lab[i] << endl;
	}

	ofs.close();
}