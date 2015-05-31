#include "Word.h"

Word::Word()
{
	/*��ȡjson�ļ�������������Ϣ��Ӧд��__CONFIG��confFile�ṹ���ڡ�*/
}

Word::~Word()
{
	/**/
}
void Word::wordInit()
{
	if (confFile.FIRST)
	{
		ifstream fileInit("Data/config.json", ios::_Noreplace);
		/*��ʼ��config.json*/
		confFile.FIRST = false;
		fileInit.close();
	}
}

void Word::wordInput()
{
	ofstream dataWrite("Data/wordList.rw", ios::out|ios::app);
	confFile.wordNum = 0;
	if (!dataWrite)
	{
		cerr << "�ʿ��ļ��򿪴��������ԣ�" << endl;
		exit(EXIT_FAILURE);
	}
	string Buffer = "#";
	int Sign = 1;
	cout << "��ӭ���뵥��¼��ϵͳ���밴����ʾ�������¼�빤�� :-)" << endl << endl;
	while (Sign)
	{
		cout << "����������Ҫ����ĵ��ʵ�Ӣ��ƴд��" << endl;
		cin >> Buffer;
		dataWrite << Buffer << " ";
		cout << "�����뵥�ʵ�������˼��" << endl;
		cin >> Buffer;
		dataWrite << Buffer << endl;
		confFile.wordNum = confFile.wordNum + 1;
		cout << "¼��ɹ�����ǰ������Ϊ : " << confFile.wordNum << endl;
		cout << "���������밴1���˳������밴0��" << endl;
		cin >> Sign;
	}
	dataWrite << "__ENDSIGN!@#" << endl;
	dataWrite.close();
}

void Word::wordShow()
{
	ifstream dataRead("Data/wordList.rw");
	string buffer;
	if (!dataRead)
	{
		cerr << "�ʿ��ļ��򿪴��������ԣ�" << endl;
		exit(EXIT_FAILURE);
	}
	dataRead >> buffer;
	while (buffer != "__ENDSIGN!@#")
	{
		English.push_back(buffer);
		dataRead >> buffer;
		Chinese.push_back(buffer);
		dataRead >> buffer;
	}
	cout << "*******���Ĵʿ��������µ���*******" << endl;
	for (int i = 0; i != English.size(); i++)
	{
		setiosflags(ios::left);
		cout << "|" << left << "[" << i + 1 << "]: " << English[i] << " " << Chinese[i] << endl;
	}
	cout << "**********************************" << endl << endl;
	dataRead.close();
}

void Word::wordChange()
{
	int Num;
	int conCg;
	bool enFlag = false;
	Word::wordShow();
	ofstream dataWrite("Data/wordList.rw", ios::out | ios::app);
	if (!dataWrite)
	{
		cerr << "*�ʿ��ļ��򿪴��������ԣ�*" << endl;
		exit(EXIT_FAILURE);
	}
	cout << endl;
	cout << "|��ӭ���뵥���滻�޸�ϵͳ�������޸���һ�����ʣ������뵥�α�š�����0��ֹ��" << endl;
	cin >> Num;
	while (Num != 0)
	{
		if (enFlag)
		{
			cout << "|�����޸���һ�����ʣ������뵥�ʱ�š�����0��ֹ��" << endl;
			cin >> Num;
			if (Num == 0)
			{
				break;
			}
		}
		if (Num <= English.size())
		{
			cout << "||��ѡ��ĵ�����" << " [" << Num << "] " << English[Num - 1] << " " << Chinese[Num - 1] << endl;
			cout << "|||��1ȷ���޸ģ����������밴0��" << endl;
			cin >> conCg;
			if (conCg == 1)
			{
				/*�޸ĵ��ʲ���*/
				cout << "||||�޸ĳɹ���" << endl << endl;
			}
			else if (conCg == 0)
			{
				/*�����޸Ĳ���*/
				cout << "||||���������޸ģ�" << endl << endl;
			}
			else
			{
				cerr << "||||�������" << endl << endl;
			}
		}
		else if (Num > English.size())
		{
			cout << "|���������Ϣ�������������룡" << endl;
			cin >> Num;
		}
		enFlag = true;
	}
	dataWrite.close();
}

void Word::wordDelete()
{
	int Num;
	int conCg;
	bool enFlag = false;
	Word::wordShow();
	ofstream dataWrite("Data/wordList.rw", ios::out | ios::app);
	if (!dataWrite)
	{
		cerr << "*�ʿ��ļ��򿪴��������ԣ�*" << endl;
		exit(EXIT_FAILURE);
	}
	cout << endl;
	cout << "|��ӭ���뵥���滻�޸�ϵͳ������ɾ����һ�����ʣ������뵥�α�š�����0��ֹ��" << endl;
	cin >> Num;
	while (Num != 0)
	{
		if (enFlag)
		{
			cout << "|�����޸���һ�����ʣ������뵥�ʱ�š�����0��ֹ��" << endl;
			cin >> Num;
			if (Num == 0)
			{
				break;
			}
		}
		if (Num <= English.size())
		{
			cout << "||��ѡ��ĵ�����" << " [" << Num << "] " << English[Num - 1] << " " << Chinese[Num - 1] << endl;
			cout << "|||��1ȷ���޸ģ����������밴0��" << endl;
			cin >> conCg;
			if (conCg == 1)
			{
				/*ɾ�����ʲ���*/
				confFile.wordNum = confFile.wordNum - 1;
				cout << "||||ɾ���ɹ������ڵĵ�����Ϊ�� " << confFile.wordNum << endl << endl;
			}
			else if (conCg == 0)
			{
				/*����ɾ������*/
				cout << "||||��������ɾ����" << endl << endl;
			}
			else
			{
				cerr << "||||�������" << endl << endl;
			}
		}
		else if (Num > English.size())
		{
			cout << "|���������Ϣ�������������룡" << endl;
			cin >> Num;
		}
		enFlag = true;
	}
	dataWrite.close();
}