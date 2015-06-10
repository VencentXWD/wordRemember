//mainframe.cpp
#include "mainframe.h"
#include <random>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <conio.h>

__MAINFRAME::__MAINFRAME() //������
{
	fflush(stdin);
	ifstream fileOpen("Data\\motto.dat");
	char temp[400];
	while (!fileOpen.eof())
	{
		fileOpen.getline(temp, sizeof(temp));
		motto.push_back(temp);
	}
	fileOpen.close();
}

void outputBlank(int n)					//����س����滮���档
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
	}
}

void mainFrame::famousMotto()	//��ӡ����
{

	random_device rd;	//����
	uniform_int_distribution<int> dicSeed(0, motto.size() - 1);	//���ɴӴʵ�ȡ���ʵ������������
	int mtrdm = dicSeed(rd);
	cout << motto[mtrdm];
	outputBlank(2);
}

void mainFrame::aboutMe()		//��������
{
	fflush(stdin);
	system("cls");
	outputBlank(10);
	cout << "                                      Young man��" << endl;
	system("Data\\egg.exe");
	outputBlank(10);
}

int mainFrame::CLIwordInit()		//�����а��ʼ������
{
	fflush(stdin);
	int choice;
	bool initFlag = true;
	bool exitflag = false;
	//	system("cls");

	while (1)
	{
		if (exitflag == true)
		{
			outputBlank(12);
			cout << setw(50) << "лл����ʹ�ã�" << setw(20);
			outputBlank(12);
			return EXIT_SUCCESS;
		}
		famousMotto();
		cout << "��աաաաաաաաաաաաաաջ�ӭ����wordKiller�աաաաաաաաաաաաաա�";
		cout << "�쩤������������������������������0.���ʲ�ѯ    ��������������������������������";
		cout << "�쩤������������������������������1.¼���µ���  ��������������������������������";
		cout << "�쩤������������������������������2.��ʾ�ʵ�    ��������������������������������";
		cout << "�쩤������������������������������3.��ʾ��ն���ʩ�������������������������������";
		cout << "�쩤������������������������������4.�ָ���ն���ʩ�������������������������������";
		cout << "�쩤������������������������������5.������      ��������������������������������";
		cout << "�쩤������������������������������6.����ģʽ    ��������������������������������";
		cout << "�쩤������������������������������7.�޸ĵ���    ��������������������������������";
		cout << "�쩤������������������������������8.ɾ������    ��������������������������������";
		cout << "�쩤������������������������������9.��ϰ���    ��������������������������������";
		cout << "�쩤������������������������������Esc.�˳����  ��������������������������������";
		cout << "��աաաաաաաաաաաաաաաաաաաաաաաաաաաաաաաաաաաաաա�";
		outputBlank(1);
		if (initFlag == true)
		{
			cout << "��ѡ������Ҫʹ�õĹ��ܣ�     ";
		}
		else
		{
			cout << "�����������������ԣ�    ";
			fflush(stdin);
		}
		if (choice = _getch())	//��ȡ�ź�
		{
			initFlag = false;
			fflush(stdin);
		}
		if (choice == 27 || (choice >= '0' && choice <= '9') || choice == '0' || choice == 'o')
		{
			initFlag = true;
		}
		else
		{
			initFlag = false;
			system("cls");
			continue;
		}
		if (initFlag)
		{
			switch (choice)
			{
				case '1':	wordInput("!");	 break;
				case '2': wordShow();		 break;
				case '3': killShow();		 break;
				case '4': killedRescue();	 break;
				case '5': wordExercise();	 break;
				case '6': wordExam();		 break;
				case '7': wordChange(); 	 break;
				case '8': wordDelete();		 break;
				case '9': wordReview();		 break;
				case '0': wordLooking();	 break;
				case  27: exitflag = true;	 break;
				case 'O':
				case 'o':	aboutMe();		 break;
			}
		}
		system("cls");
	}
}

void mainFrame::wordLooking()//��ѯ����
{
	fflush(stdin);
	system("cls");
	string curEnglish = "!";
	cout << "�쩤������������������������������0.���ʲ�ѯ    ��������������������������������";
	outputBlank(2);
	char add = '!';
	while (curEnglish != "#")
	{
		cout << "����������Ҫ��ѯ�ĵ��ʵ�ƴд������\"#\"�˳���ѯ���ܣ�    ";
		cin >> curEnglish;
		if (curEnglish == "#")
		{
			return;
		}
		fflush(stdin);
		int wd = dataBase.searchWord(curEnglish);
		if (wd == -1)
		{
			cout << "��û���ҵ��õ��ʣ���ϣ��������������   (1��/0��)    ";
			while (add = _getch())
			{
				if (add == '1')
				{
					wordInput(curEnglish);
					return ;
				}
				else if (add == '0')
				{
					cout << endl;
					break;
				}
				else
				{
					cout << "���������Ϣ�������������룡    ";
					fflush(stdin);
				}
			}
		}
		else
		{
			cout << "���� " << curEnglish << " �����Ľ���Ϊ�� " << dataBase.getChinese(wd) << endl << endl;
		}
	}
}

void mainFrame::wordInput(string curEnglish = "!")	//¼���µ���
{
	fflush(stdin);
	string curChinese;

	system("cls");
	cout << "�쩤������������������������������1.¼���µ���  ��������������������������������";
	outputBlank(2);
	if (curEnglish != "!")
	{
		/*�����ʾ��Ϣ���������� ���ĵ���*/
		while (curEnglish != "#")
		{
			cout << "��Ҫ��ӵĵ���Ϊ: " << curEnglish << " �������뺺�����⣺      ";
			cin >> curChinese;
			char flag = '0';
			cout << "��Ҫ¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ��\"" << curChinese << "\"��ȷ��¼�뱾������(1ȷ��0������)" << endl;
			while (1)
			{
				flag = _getch();
				if (flag == '1')
				{
					wordList BUFFER(curEnglish, curChinese, 0);
					dataBase.addWord(BUFFER);
					cout << "¼����ϣ���¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ�� " << curChinese << endl << endl;
					system("pause");
					return;
				}
				else if (flag == '0')
				{
					cout << "�����ɹ���" << endl << endl;
					system("pause");
					return;
				}
				else
				{
					cout << "���������Ϣ�������������룡(1ȷ��0������)" << endl;
					fflush(stdin);	//��ջ���������ֹ���ѭ��
				}
			}
		}
	}
	else
	{
		while (curEnglish != "#")
		{
			cout << "����������Ҫ¼���Ӣ�ĵ��ʣ���#�˳���      ";
			cin >> curEnglish;
			if (curEnglish == "#")
			{
				return;
			}
			if (dataBase.searchWord(curEnglish) >= 0)	//����
			{
				/*��ʾ�����Ѵ��ڣ�����Ҫ���,ѯ���Ƿ���Ҫ�޸ġ�*/
				cout << "�����Ѵ��ڣ�" << endl;
			}
			else
			{
				/*�����ʾ��Ϣ���������� ���ĵ���*/
				cout << "�����뺺�����⣺      ";
				cin >> curChinese;
				char flag = '0';
				int exflag = 0;
				cout << "��Ҫ¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ�� " << curChinese << "ȷ��¼�뱾������(1ȷ��0������) ";
				while (!exflag)
				{
					flag = _getch();
					if (flag == '1')
					{
						wordList BUFFER(curEnglish, curChinese, 0);
						dataBase.addWord(BUFFER);
						cout << "¼����ϣ���¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ�� " << curChinese << endl << endl;
						exflag = 1;
					}
					else if (flag == '0')
					{
						cout << "�����ɹ���" << endl << endl;
						exflag = 1;
					}
					else
					{
						cout << endl;
						cout << "���������Ϣ�������������룡(1ȷ��0������)";
						fflush(stdin);
						continue;
					}
				}
			}
		}
	}
}

void mainFrame::wordShow()	//��ʾ�ʵ���Ϣ
{
	fflush(stdin);
	int LEN = dataBase.wordSize();
	/*�����ʾ��Ϣ���鿴�굥�ʱ����ر�*/
	system("cls");
	cout << "�쩤������������������������������2.��ʾ�ʵ�    ��������������������������������";
	outputBlank(2);
	if (LEN <= 30)	//���ʽ��٣�����ֱ���������Ļ��
	{
		for (int i = 0; i < LEN; i++)
		{
			wordList BUFFER;
			BUFFER = dataBase.getWord(i);
			cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
		}
		cout << "���Ĵʵ���һ���� " << dataBase.wordSize() << "�����ʡ�" << endl;
		outputBlank(2);
	}
	else
	{
		char sign;
		cout << "�ʵ���һ���� " << dataBase.wordSize() << "�����ʣ��Ƿ�ϣ���򿪵����ļ���(1��0��)    ";
		while (sign = _getch())
		{
			if (sign == '1')
			{
				system("start Data\\dictionary.dat");	//��ȡ�ļ�
				system("pause");
				return ;
			}
			else if (sign == '0')
			{
				return ;
			}
			else
			{
				cout << endl;
				cout << "�������ָ���������������룡";
				fflush(stdin);
			}
		}
	}
	fflush(stdin);
}

void mainFrame::killShow()	//��ʾ��ն����
{
	fflush(stdin);
	system("cls");
	cout << "�쩤������������������������������3.��ʾ��ն���ʩ�������������������������������";
	if (killedBase.wordSize() == 0)
	{
		int flag;
		cout << endl << "����û��ն�κε��ʣ�����ն��ʹ����(1��/0��)      ";
		cin >> flag;
		if (flag)
		{
			wordExercise();
			return;
		}
		else
		{
			return;
		}
	}
	cout << "��һ��ն��: " << killedBase.wordSize() << " �����ʣ�������ٽ�������" << endl;
	//	system("notepad Data\\killed.dat");	//��ȡ�ļ�
	for (int i = 0; i < killedBase.wordSize(); i++)
	{
		wordList BUFFER;
		BUFFER = killedBase.getWord(i);
		cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
	}
	outputBlank(2);
	system("pause");
	fflush(stdin);
}

void mainFrame::killedRescue()	//�ָ���ն����
{
	fflush(stdin);
	system("cls");
	bool FLAG = true;
	string temp = "!";
	cout << "�쩤������������������������������4.�ָ���ն���ʩ�������������������������������";
	outputBlank(2);
	while (temp != "#")
	{
		if (killedBase.wordIsEmpty())
		{
			char goKill;
			cout << "����նɱ�����ǿյģ���ն��ʹ����(1ȥ/0��ȥ)    ";
			while (cin >> goKill)
			{
				fflush(stdin);
				if (goKill == '1')
				{
					wordExercise();
					return;
				}
				else if (goKill == '0')
				{
					return;
				}
				else
				{
					cout << "���������������������룡   ";
				}
			}
		}
		if (FLAG)
		{
			cout << "��һ��ն��: " << killedBase.wordSize() << " �����ʡ�" << endl;
			for (int i = 0; i < killedBase.wordSize(); i++)
			{
				wordList BUFFER;
				BUFFER = killedBase.getWord(i);
				cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
			}
			FLAG = false;
		}
		else
		{
			cout << "��ʣ�� " << killedBase.wordSize() << " �����ʡ�" << endl;
			for (int i = 0; i < killedBase.wordSize(); i++)
			{
				wordList BUFFER;
				BUFFER = killedBase.getWord(i);
				cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
			}
		}
		outputBlank(2);
		cout << "����������ָ��ĵ��ʵ�Ӣ��ƴд������#�˳��ָ����ܣ�     ";
		cin >> temp;
		if (temp == "#")
		{
			return;
		}
		int Num = killedBase.searchWord(temp);
		if (Num == -1)
		{
			cerr << "û���ҵ��õ��ʣ�" << endl << endl;
		}
		else
		{
			wordList wtmp = killedBase.getWord(Num);
			killedBase.removeWord(Num + 1);	//ɾ����ն���еĵ���
			dataBase.addWord(wtmp);		//�Żشʵ���
		}
	}
	fflush(stdin);
	getchar();
}

void mainFrame::wordExercise()	//������
{
	fflush(stdin);
	system("cls");
	cout << "�쩤������������������������������5.������      ��������������������������������";
	if (dataBase.wordIsEmpty())
	{
		int ADD = 3;
		while (ADD != 0 || ADD != 1)
		{
			cout << endl << "����û������κε��ʣ��Ƿ�Ҫ��ӵ���(1���/0�����)��    ";
			ADD = _getch();
			ADD -= '0';
			if (ADD == 1)
			{
				wordInput();
				break;
			}
			else if (ADD == 0)
			{
				return;
			}
			else
			{
				cout << "���������Ϣ����" << endl << endl;
				fflush(stdin);
			}
		}
		return;
	}
	int flag = 1;
	while (flag == 1)
	{
		random_device rd;
		uniform_int_distribution<int> dicSeed(0, dataBase.wordSize() - 1);	//���ɴӴʵ�ȡ���ʵ������������
		vector<wordList> answers;
		int TIME = 20;
		cout << "��ӭ���뱳����ģʽ���������������20�����ʹ������䡣����\'ESC\'�˳�" << endl << endl;
		system("pause");
		for (int i = 0; i < TIME && !dataBase.wordIsEmpty(); i++)
		{
			if (dataBase.wordSize() > 0)
			{
				int chosen = dicSeed(rd);
				wordList word = dataBase.getWord(chosen);
				answers.push_back(word);
				cout << "Round " << i + 1 << ":  " << answers[i].getEnglish() << "   " << answers[i].getChinese() << endl;
				if (wordKiller(chosen) == 1)	//ն�ʹ���
				{
					return;
				}
			}
		}
		if (!dataBase.wordIsEmpty())
		{
			cout << endl << "�����ˣ���Ҫ����һ����(1��һ��/0������)      ";
			cin >> flag;
			vector<wordList>().swap(answers);
		}
		else
		{
			cout << endl << "���Ĵʿ������" << endl;
			system("pause");
			return;
		}
	}
}

void mainFrame::wordExam()	//����ģʽ
{
	fflush(stdin);
	system("cls");
	cout << "�쩤������������������������������6.����ģʽ    ��������������������������������";
	if (dataBase.wordIsEmpty())
	{
		int ADD = 3;
		while (ADD != 0 || ADD != 1)
		{
			cout << endl << "����û������κε��ʣ��Ƿ�Ҫ��ӵ���(1���/0�����)��    ";
			cin >> ADD;
			if (ADD == 1)
			{
				wordInput();
				break;
			}
			else if (ADD == 0)
			{
				return;
			}
			else
			{
				cout << "���������Ϣ����" << endl << endl;
				fflush(stdin);
			}
		}
		return;
	}
	random_device rd;	//����
	uniform_int_distribution<int> dicSeed(0, dataBase.wordSize() - 1);	//���ɴӴʵ�ȡ���ʵ������������
	uniform_int_distribution<int> ansSeed(0, 3);						//�����ĸ����е�һ����Ϊ�𰸵�����
	uniform_int_distribution<int> exaSeed(0, 1);						//������Ŀ�Ǻ���Ӣ����Ӣ�뺺������
	wordList optAns[4];	//�洢�ĸ���ѡ��
	wordList temp;		//���ڴ洢��ĵ���
	string answer;	//������Ŵ�
	int ansNum;
	char chsNum;
	int score = 0, count = 1;
	int range;	//������Ŀ
	int exam;
	double ratio;
	cout << "��ӭ���뿼��ģʽ��һ����20�����ʣ���ɿ���������Ҳ������Ӣ�ģ�����ESC�����˳���ף����ˡ�" << endl;
	system("pause");
	range = 20;	//test
	cout << "Link start!" << endl << endl;
	fflush(stdin);
	for (int i = 0; i < range; i++)
	{
		exam = exaSeed(rd);
		if (exam == 0)	/*�������ѡ��Ӣ��*/
		{
			for (int i = 0; i < 4; i++)	//���ĸ��𰸸�ֵ
			{
				optAns[i] = dataBase.getWord(dicSeed(rd));
			}
			ansNum = ansSeed(rd);	//���������
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1 << ": " << left << setw(10) << optAns[i].getEnglish();
				if ((i + 1) % 2 == 0)
				{
					cout << endl;
				}
			}
			cout << "Round " << count++ << ": ��ѡ��Ӣ��Ϊ\"" << optAns[ansNum].getChinese() << "\"�ĵ��ʡ�    ";

			chsNum = _getch();
			if (chsNum == 27)
			{
				return ;
			}
			chsNum = chsNum - '0' - 1;
			if (chsNum == ansNum)
			{
				score++;
				cout << "�������" << endl;
				fflush(stdin);
			}
			else
			{
				int wr = dataBase.searchWord(optAns[ansNum].getEnglish());	//���´���ڴʵ�vector�е�λ��
				cout << "�Բ���������ˡ�" << endl;
				dataBase.addWrongTimes(wr);
				//cout << "+1" << endl;
				fflush(stdin);
			}
		}
		else if (exam == 1)	/*���Ӣ��ѡ������*/
		{
			for (int i = 0; i < 4; i++)	//���ĸ��𰸸�ֵ
			{
				optAns[i] = dataBase.getWord(dicSeed(rd));
			}
			ansNum = ansSeed(rd);	//���������
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1 << ": " << left << setw(10) << optAns[i].getChinese();
				if ((i + 1) % 2 == 0)
				{
					cout << endl;
				}
			}
			cout << "Round " << count++ << ": ��ѡ������Ϊ\"" << optAns[ansNum].getEnglish() << "\"�ĺ��    ";

			chsNum = _getch();
			chsNum = chsNum - '0' - 1;	//ƥ��������ϰ��
			if (chsNum == 27)
			{
				return;
			}
			if (chsNum == ansNum)
			{
				score++;
				cout << "�������" << endl;
			}
			else
			{
				int wr = dataBase.searchWord(optAns[ansNum].getEnglish());	//���´���ڴʵ�vector�е�λ��
				cout << "�Բ���������ˡ�" << endl;
				dataBase.addWrongTimes(wr);	//���Ӵ������
			}
		}
	}
	ratio = double(score) / double(range);
	cout << "Stop����һ������ " << score << "��" << "��ȷ��Ϊ " << ratio * 100 << "%�����ٽ�������" << endl;
	cout << endl << "��������˳���" << endl;
	fflush(stdin);
	getchar();
}


void mainFrame::wordChange()	//�޸ĵ���
{
	fflush(stdin);
	int Num;
	char flag = '1';
	string curEnglish = "!";
	string curChinese;
	system("cls");
	cout << "�쩤������������������������������7.�޸ĵ���    ��������������������������������";
	outputBlank(2);
	while (curEnglish != "#")
	{
		if (dataBase.wordIsEmpty())
		{
			char ADD = '3';
			while (ADD != '0' || ADD != '1')
			{
				cout << endl << "����û������κε��ʣ��Ƿ�Ҫ��ӵ���(1���/0�����)��    ";
				ADD = _getch();
				if (ADD == '1')
				{
					wordInput();
					break;
				}
				else if (ADD == '0')
				{
					return;
				}
				else
				{
					cout << "���������Ϣ����" << endl << endl;
					fflush(stdin);
				}
			}
			return;
		}
		while (curEnglish != "#")
		{
			char cont = '1';
			cout << "����������Ҫ�޸ĵĵ��ʵ�ƴд������#�˳���      ";		//�ʿ�̫�󣬲��ṩ����޸ķ���
			cin >> curEnglish;
			fflush(stdin);	//��ջ�����
			if (curEnglish == "#")
			{
				return ;
			}
			if (dataBase.searchWord(curEnglish) < 0)
			{
				/*��ʾ���ʲ����ڣ�������󣬷���*/
				cout << "�˵��ʲ������ڣ������ԡ� " << endl;
			}
			else
			{
				Num = dataBase.searchWord(curEnglish);
				cout << "�˵��ʵ����Ľ���Ϊ�� " << dataBase.getChinese(Num) << endl;
				cout << "����������Ҫ�޸ĵ��ʶ�Ӧ�����Ľ��ͣ�    ";
				cin >> curChinese;
				fflush(stdin);
				cout << "��Ҫ�޸ĵĵ���Ϊ:" << curEnglish << "�����Ľ���Ϊ\"" << curChinese << "\"��ȷ���޸���?(1��/0��)" << endl;
				char comflag;
				bool finish = false;
				while (!finish)
				{
					comflag = _getch();
					if (comflag == '1')
					{
						wordList BUFFER(curEnglish, curChinese, dataBase.getWordWrongTime(Num));	/*д*/
						dataBase.changeWordNum(Num, BUFFER);
						cout << "�޸ĳɹ��� �Ƿ�����޸ģ�1��/0�񣩣�" << endl;
						while (cont = _getch())
						{
							if (cont == '0')
							{
								return ;
							}
							else if (cont == '1')
							{
								break ;
							}
							else
							{
								cout << "���������Ϣ���������ԣ�" << endl;
							}
						}
						break;
					}
					else if (comflag == '0')
					{
						finish = true;
						cout << "�����ɹ��� �Ƿ�����޸ģ�1��/0�񣩣�" << endl;
						while (cont = _getch())
						{
							if (cont == '0')
							{
								return;
							}
							else if (cont == '1')
							{
								break;
							}
							else
							{
								cout << "���������Ϣ���������ԣ�" << endl;
							}
						}
					}
					else
					{
						cout << "���������Ϣ�������������룡" << endl;
						fflush(stdin);
					}
				}
			}
		}
		/*��ʾ�޸ĳɹ�*/
	}
}

void mainFrame::wordDelete()	//ɾ������
{
	fflush(stdin);
	system("cls");
	string curEnglish = "!";
	string curChinese;
	int Num;
	cout << "�쩤������������������������������8.ɾ������    ��������������������������������";
	outputBlank(2);
	while (curEnglish != "#")
	{
		cout << "����������ɾ���ĵ��ʵ�Ӣ�ģ�����#�˳���      ";
		cin >> curEnglish;
		if (curEnglish == "#")
		{
			break;
		}
		if (dataBase.searchWord(curEnglish) < 0)	//������
		{
			cout << "��ѡ�ĵ��ʲ������ڣ�������ѡ�� " << endl << endl;
		}
		else
		{
			string curChinese = dataBase.getChinese(dataBase.searchWord(curEnglish));
			int flag;
			cout << "����ѡ�ĵ���Ϊ " << curEnglish << " �����Ľ���Ϊ��\"" << curChinese << "\"��" << endl;
			cout << "ȷ��Ҫɾ�����𣿣�1��/0��    ";
			flag = _getch();
			flag -= '0';
			fflush(stdin);
			if (flag == 1)
			{
				Num = dataBase.searchWord(curEnglish) + 1;
				dataBase.removeWord(Num);
				cout << "ɾ���ɹ�������Ҳ����������" << endl << endl;
			}
			else
			{
				cout << "�����ɹ���" << endl << endl;
			}
		}
	}
}

void mainFrame::wordReview()	//��ϰ���ʹ���
{
	fflush(stdin);
	char fuck ='1';
	bool cflag = false;
	bool flag = true;
	string curEnglish = "!";
	system("cls");
	cout << "�쩤������������������������������9.��ϰ���    ��������������������������������";
	outputBlank(2);
	vector<__WORDLIST> temp = dataBase.getWrongWords();	//��ȡ��ʵ�����
	if (temp.size() == 0)
	{
		cout << "һ����ʶ�û�У���һ����û�кúñ����ʣ���ȥ�����ʣ�" << endl << endl;
		system("pause");
		wordExam();
		return;
	}
	cout << "�ڹ�ȥ���������һ������ " << temp.size() << "�����ʣ����Ƿֱ��ǣ�   " << endl;
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		cout << temp[i].getEnglish() << "  \""
			<< temp[i].getChinese() << "\"  "
			<< "���� "	 << temp[i].getWrongTimes() << "�Ρ�" << endl;
	}
	outputBlank(5);
	while (1)
	{
		if (flag)
		{
			cout << "��������һ����ս���ǵĻ��ᣬ�Ƿ�ӭս������ʾ��������ս��ͬһ�㣩(1��/0��)   ";
			flag = false;
		}
		else if (!flag && curEnglish != "#" && cflag == true)
		{
			cout << "ˬ�գ��Ƿ�����һ�Σ�(1��/0��)" << endl;
		}
		else
		{
			outputBlank(5);
			cout << "*******************������������������*******************" << endl;
			outputBlank(5);
			fflush(stdin);
			system("pause");
			return;
		}
		hflag:	fuck = _getch();	//�����н���һ����goto������goto������ѡ������β����˲���Ӱ�쵽���������������С�
		if (fuck == '1')
		{
			system("cls");
			int rdm;
			cout << "��ˬ�죡��Ϊ�޾�ģʽ���볷�˵Ļ�����ʹ��\"#\"" << endl << endl;
			while (1)
			{
				int i = 0;
				i++;
				if (curEnglish == "#")
				{
					break;
				}
				random_device rd;	//����
				uniform_int_distribution<int> dicSeed(0, temp.size() - 1);	//���ɴӴʵ�ȡ���ʵ�����������ӣ���Ϊsize�ǻ�仯��
				rdm = dicSeed(rd);
				cout << "Round " << i + 1 << ": ��д����˼Ϊ \"" << temp[rdm].getChinese() << "\" �ĵ��ʵ�ƴд��    ";
				cin >> curEnglish;
				fflush(stdin);
				if (curEnglish != temp[rdm].getEnglish())
				{
					if (curEnglish == "#")
					{
						continue;
					}
					cout << "���ش���ˣ���ȷ��Ӧ���ǣ� " << temp[rdm].getEnglish() << endl << endl;
					dataBase.addWrongTimes(dataBase.getWordNum(temp[rdm].getEnglish()));	//���ݴ����dataBase�е�λ��������������	
				}
				else if (curEnglish == temp[rdm].getEnglish())
				{
					int choice;
					cout << "���ش���ȷ���Ƿ�����Żأ��ŻؾͲ�������������ˣ�����(1���˰�/0����)    ";
					cin >> choice;
					if (choice == 1)
					{
						dataBase.rmFromWrong(curEnglish);
						swap(temp[rdm], temp[temp.size() - 1]);
						temp.pop_back();
					}
					if (dataBase.getWrongWords().size() == 0)
					{
						cout << endl << "��û���κδ�����~" << endl;
						system("pause");
						return ;
					}
				}
			}
		}
		else if (fuck == '0')
		{
			return;
		}
		else
		{
			cout << "���������Ϣ�������������룡" << endl;
			goto hflag;
		}
	}
	fflush(stdin);
	getchar();
}


int mainFrame::wordKiller(int Num)		//ն��
{
	fflush(stdin);
	char judge;
	cout << "����Kն����������S��������      ";
	while (judge = _getch())
	{
		if (judge == 'K' || judge == 'k')
		{
			killedBase.addWord(dataBase.getWord(Num));
			dataBase.removeWord(Num + 1);
			cout << "��ն!��" << endl;
			break;
		}
		else if (judge == 'S' || judge == 's')
		{
			cout << endl;
			break;
		}
		else if (judge == 27)
		{
			return 1;
		}
		else
		{
			cout << "���������Ϣ�������������룡    ";
			fflush(stdin);
		}
	}
	return 0;
}
