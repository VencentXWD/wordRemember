#include "mainframe.h"
#include <random>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cctype>

__MAINFRAME::__MAINFRAME() 
{
}

__MAINFRAME::~__MAINFRAME() 
{
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
	fflush(stdin);
	ifstream fileOpen("Data\\motto.dat");
	string temp;
	vector<string> motto;
	while (fileOpen >> temp)
	{
		motto.push_back(temp);
	}
	random_device rd;	//����
	uniform_int_distribution<int> dicSeed(0, 10);	//���ɴӴʵ�ȡ���ʵ������������
	int mtrdm = dicSeed(rd);
	cout << "*********�������ԣ� " << motto[mtrdm] << "*********" << endl;
	fileOpen.close();
}

void mainFrame::aboutMe()		//��������
{
	fflush(stdin);
	system("cls");
	outputBlank(10);
	cout << "                  �������˲ʵ���Young man��" << endl;
	system("Data\\egg.exe");
	outputBlank(10);
	system("pause");
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
		//		famousMotto();
		cout << "*******************************��ӭ����wordKiller*******************************" << endl;
		cout << "****                                                                       ****" << endl;
		cout << "****                           0.���ʲ�ѯ                                  ****" << endl;
		cout << "****                           1.¼���µ���                                ****" << endl;
		cout << "****                           2.��ʾ�ʵ�                                  ****" << endl;
		cout << "****                           3.��ʾ��ն����                              ****" << endl;
		cout << "****                           4.�ָ���ն����                              ****" << endl;
		cout << "****                           5.������                                    ****" << endl;
		cout << "****                           6.����ģʽ                                  ****" << endl;
		cout << "****                           7.�޸ĵ���                                  ****" << endl;
		cout << "****                           8.ɾ������                                  ****" << endl;
		cout << "****                           9.��ϰ���                                  ****" << endl;
		cout << "****                           10.�˳����                                 ****" << endl;
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
		if (!scanf_s("%d", &choice))	//����scanf�ķ���ֵ�ж��ǲ������������
		{
			initFlag = false;
			fflush(stdin);
		}
		if (choice == 12345 || (choice >= 0 && choice <= 10))
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
				case 1:	wordInput("!");	 break;
				case 2: wordShow();		 break;
				case 3: killShow();		 break;
				case 4: killedRescue();	 break;
				case 5: wordExercise();  break;
				case 6: wordExam();		 break;
				case 7: wordChange(); 	 break;
				case 8: wordDelete();	 break;
				case 9: wordReview();	 break;
				case 0: wordLooking();	 break;
				case 10: exitflag = true; break;
				case 12345: aboutMe();	 break;
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
	cout << "****                           0.���ʲ�ѯ                                  ****" << endl;
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
			while (cin >> add)
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
	cout << "****                           1.¼���µ���                                ****" << endl;
	outputBlank(2);
	if (curEnglish != "!")
	{
		/*�����ʾ��Ϣ���������� ���ĵ���*/
		while (curEnglish != "#")
		{
			cout << "��Ҫ��ӵĵ���Ϊ: " << curEnglish << " �������뺺�����⣺      ";
			cin >> curChinese;
			char flag = '0';
			cout << "��Ҫ¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ��\"" << curChinese << "\"��ȷ��¼�뱾������(1ȷ��0������) ";
			while (1)
			{
				cin >> flag;
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
					cout << "���������Ϣ�������������룡(1ȷ��0������)    ";
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
				/*��ʾ�����Ѵ��ڣ�����Ҫ���,����*/
				cout << "�����Ѵ��ڣ�������Ҫ�ٴ���ӡ�" << endl;
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
					cin >> flag;
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
						cout << "���������Ϣ�������������룡(1ȷ��0������)    ";
						fflush(stdin);	//��ջ���������ֹ���ѭ��
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
	cout << "****                           2.��ʾ�ʵ�                                  ****" << endl;
	outputBlank(2);
	for (int i = 0; i < LEN; i++)
	{
		wordList BUFFER;
		BUFFER = dataBase.getWord(i);
		cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
	}
	//	system("notepad Data\\dictionary.dat");	//��ȡ�ļ�
	cout << "���Ĵʵ���һ���� " << dataBase.wordSize() << "�����ʡ�" << endl;
	outputBlank(2);
	fflush(stdin);
	system("pause");
}

void mainFrame::wordChange()	//�޸ĵ���
{
	fflush(stdin);
	int Num;
	char flag = '1';
	string curEnglish = "!";
	string curChinese;
	system("cls");
	cout << "****                           7.�޸ĵ���                                  ****" << endl;
	outputBlank(2);
	while (curEnglish != "#")
	{
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
				cout << "��Ҫ�޸ĵĵ���Ϊ:" << curEnglish << "�����Ľ���Ϊ\"" << curChinese << "\"��ȷ���޸���?(1��/0��)  ";
				char comflag;
				bool finish = false;
				while (cin >> comflag && !finish)
				{
					if (comflag == '1')
					{
						wordList BUFFER(curEnglish, curChinese, dataBase.getWordWrongTime(Num));	/*д*/
						dataBase.changeWordNum(Num, BUFFER);
						cout << "�޸ĳɹ��� �Ƿ�����޸ģ�1��/0�񣩣�     ";
						while (cin >> cont)
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
								cout << "���������Ϣ���������ԣ�    ";
							}
						}
						break;
					}
					else if (comflag == '0')
					{
						finish = true;
						cout << "�����ɹ��� �Ƿ�����޸ģ�1��/0�񣩣�     ";
						while (cin >> cont)
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
								cout << "���������Ϣ���������ԣ�    ";
							}
						}
					}
					else
					{
						cout << "���������Ϣ�������������룡    ";
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
	cout << "****                           8.ɾ������                                  ****" << endl;
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
			cin >> flag;
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

void mainFrame::wordExercise()	//������
{
	fflush(stdin);
	system("cls");
	cout << "****                           5.������                                    ****" << endl;
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
	int flag = 1;
	while (flag == 1)
	{
		random_device rd;
		uniform_int_distribution<int> dicSeed(0, dataBase.wordSize() - 1);	//���ɴӴʵ�ȡ���ʵ������������
		vector<wordList> answers;
		int TIME = 20;
		cout << "��ӭ���뱳����ģʽ���������������20�����ʹ������䡣����\'#\'�˳�" << endl << endl;
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
			return ; 
		}
	}
}

int mainFrame::wordKiller(int Num)		//ն��
{
	fflush(stdin);
	char judge;
	cout << "����1ն����������0��������      ";
	while (cin >> judge)
	{
		if (judge == '1')
		{
			killedBase.addWord(dataBase.getWord(Num));
			dataBase.removeWord(Num + 1);
			break;
		}
		else if (judge == '0')
		{
			break;
		}
		else if (judge == '#')
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

void mainFrame::wordExam()	//����ģʽ
{
	fflush(stdin);
	system("cls");
	cout << "****                           6.����ģʽ                                  ****" << endl;
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
	int ansNum, chsNum;
	int score = 0, count = 1;
	int range;	//������Ŀ
	int exam;
	double ratio;
	cout << "��ӭ���뿼��ģʽ��һ����20�����ʣ���ɿ���������Ҳ������Ӣ�ģ�ף����ˡ�" << endl;
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

			scanf_s("%d", &chsNum);
			chsNum--;
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

			cin >> chsNum;
			chsNum--;	//ƥ��������ϰ��
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
				//cout << "+1" << endl;
			}
		}
	}
	ratio = double(score) / double(range);
	cout << "Stop����һ������ " << score << "��" << "��ȷ��Ϊ " << ratio * 100 << "%�����ٽ�������" << endl;
	cout << endl << "��������˳���" << endl;
	fflush(stdin);
	getchar();
}

void mainFrame::killShow()	//��ʾ��ն����
{
	fflush(stdin);
	system("cls");
	cout << "****                           3.��ʾ��ն����                              ****" << endl;
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
	cout << "****                           4.�ָ���ն����                              ****" << endl;
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

void mainFrame::wordReview()	//��ϰ���ʹ���
{
	fflush(stdin);
	int fuck = 1;
	bool flag = true;
	string curEnglish = "!";
	system("cls");
	cout << "****                           9.��ϰ���                                  ****" << endl;
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
	while (fuck == 1)
	{
		if (flag)
		{
			cout << "��������һ����ս���ǵĻ��ᣬ�Ƿ�ӭս������ʾ��������ս��ͬһ�㣩(1��/0��)   ";
			flag = false;
		}
		else if (!flag && curEnglish != "#")
		{
			cout << "ˬ�գ��Ƿ�����һ�Σ�(1��/0��)" << endl;
		}
		else
		{
			outputBlank(5);
			cout << "*******************���ˣ�*******************" << endl;
			outputBlank(5);
			fflush(stdin);
			system("pause");
			return;
		}
		cin >> fuck;
		if (fuck == 1)
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
					cout << "���ش���ˣ���ȷ��Ӧ���ǣ� " << temp[rdm].getEnglish() << endl << endl;
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
		else if (fuck == 0)
		{
			return;
		}
		else
		{
			cout << "���������Ϣ�������������룡";
		}
	}
	fflush(stdin);
	getchar();
}
