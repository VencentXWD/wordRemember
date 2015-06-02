#include "mainframe.h"
#include <random>
#include <algorithm>
#include <iomanip>

__MAINFRAME::__MAINFRAME() {}

__MAINFRAME::~__MAINFRAME() {}

void outputBlank(int n)					//����س����滮���档
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
	}
}

void mainFrame::CLIwordInit()		//�����а��ʼ������
{
	int choice;
	bool initFlag = true;
	bool exitflag = false;
	system("cls");
	while (1)
	{
		if (exitflag == true)
		{
			return;
		}
		cout << "*******************************��ӭ����wordKiller*******************************" << endl;
		cout << "****                                                                       ****" << endl;
		cout << "****                           1.¼���µ���                                ****" << endl;
		cout << "****                           2.��ʾ�ʵ�                                  ****" << endl;
		cout << "****                           3.��ʾ��ն����                              ****" << endl;
		cout << "****                           4.�ָ���ն����                              ****" << endl;
		cout << "****                           5.������                                    ****" << endl;
		cout << "****                           6.������ģʽ                                ****" << endl;
		cout << "****                           7.�޸ĵ���                                  ****" << endl;
		cout << "****                           8.ɾ������                                  ****" << endl;
		cout << "****                           9.�˳����                                  ****" << endl;
		outputBlank(1);
		if (initFlag == true)
		{
			cout << "��ѡ������Ҫʹ�õĹ��ܣ�     ";
		}
		else
		{
			cout << "����������������ԣ�" << endl;
		}
		cin >> choice;
		if (choice > 0 && choice < 10)
		{
			initFlag = true;
		}
		else
		{
			initFlag = false;
			system("cls");
			continue;
		}
		switch (choice)
		{
		case 1:	wordInput();	 break;
		case 2: wordShow();		 break;
		case 3: killShow();		 break;
		case 4: killedRescue();	 break;
		case 5: wordExercise();  break;
		case 6: wordExam();		 break;
		case 7: wordChange(); 	 break;
		case 8: wordDelete();	 break;
		case 9: exitflag = true; break;
		}
		system("cls");
	}
}

void mainFrame::wordInput()	//¼���µ���
{
	string curEnglish = "!";
	string curChinese;

	system("cls");
	cout << "****                           1.¼���µ���                                ****" << endl;
	outputBlank(2);
	while (curEnglish != "#")
	{
		cout << "����������Ҫ¼���Ӣ�ĵ��ʣ���#�˳���      ";
		cin >> curEnglish;
		if (curEnglish == "#")
		{
			break;
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
			wordList BUFFER(curEnglish, curChinese);
			dataBase.addWord(BUFFER);
			cout << "¼����ϣ���¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ�� " << curChinese << endl;
		}
	}
}

void mainFrame::wordShow()	//��ʾ�ʵ�
{
	int LEN = dataBase.wordSize();
	/*�����ʾ��Ϣ���鿴�굥�ʱ����ر�*/
	system("cls");
	cout << "****                           2.��ʾ�ʵ�                                  ****" << endl;
	outputBlank(2);
	cout << "���Ĵʵ���һ���� " << dataBase.wordSize() << "�����ʡ�" << endl << endl;
	for (int i = 0; i < LEN; i++)
	{
		wordList BUFFER;
		BUFFER = dataBase.getWord(i);
		cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
	}
	//	system("notepad Data\\dictionary.dat");	//��ȡ�ļ�
	outputBlank(2);
	cout << "����������ء� " << endl;
	fflush(stdin);
	getchar();
}

void mainFrame::sortWord()	//��������
{
	dataBase.sortWord();
}

void mainFrame::wordChange()	//�޸ĵ���
{
	int Num;
	string curEnglish = "!";
	string curChinese;
	system("cls");
	cout << "****                           7.�޸ĵ���                                  ****" << endl;
	outputBlank(2);
	while (curEnglish != "#")
	{
		if (dataBase.wordIsEmpty())
		{
			bool ADD;
			cout << "�㻹û������κε��ʣ��Ƿ�Ҫ��ӵ���(1���/0�����)��" << endl;
			cin >> ADD;
			fflush(stdin);
			if (ADD)
			{
				wordInput();
				break;
			}
			else
			{
				return;
			}
		}
		cout << "����������Ҫ�޸ĵĵ��ʵ�ƴд������#�˳���      ";
		cin >> curEnglish;
		fflush(stdin);	//��ջ�����
		if (dataBase.searchWord(curEnglish) < 0)
		{
			/*��ʾ���ʲ����ڣ�������󣬷���*/
			cout << "�˵��ʲ����ܴ��ڣ������ԡ�" << endl;
		}
		else
		{
			/*�����ʾ��Ϣ�����뵥�ʵ�����*/
			cout << "����������Ҫ�޸ĵ��ʶ�Ӧ�����Ľ��ͣ�      ";
			cin >> curChinese;
			fflush(stdin);
			Num = dataBase.searchWord(curEnglish);
			wordList BUFFER(curEnglish, curChinese);
			dataBase.changeWordNum(Num, BUFFER);
			cout << "�޸ĳɹ�����������˳��� " << endl;
			getchar();
			return ;
			/*��ʾ�޸ĳɹ�*/
		}
	}
}

void mainFrame::wordDelete()	//ɾ������
{
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
			cout << "����ѡ���ʲ������ڣ�������ѡ�� " << endl;
		}
		else
		{
			Num = dataBase.searchWord(curEnglish) + 1;
			dataBase.removeWord(Num);
			cout << "ɾ���ɹ�������Ҳ����������" << endl;
		}
	}
}

void mainFrame::wordExercise()	//������
{
	system("cls");
	cout << "****                           5.������                                    ****" << endl;
	random_device rd;
	uniform_int_distribution<int> dicSeed(1, dataBase.wordSize() - 1);	//���ɴӴʵ�ȡ���ʵ������������
	dicSeed(rd);
	vector<wordList> answers;
	int len;
	cout << "���Ĵʵ�����" << dataBase.wordSize() << "�����ʣ������뱳�������ʣ�      ";
	cin >> len;
	fflush(stdin);
	for (int i = 0; i < len; i++)
	{
		int chosen = dicSeed(rd);
		wordList word = dataBase.getWord(chosen);
		answers.push_back(word);
		cout << answers[i].getEnglish() << setw(10) << answers[i].getChinese() << endl;
		wordKiller(chosen);	//ն�ʹ���
	}
}

void mainFrame::wordExam()	//������ģʽ
{
	system("cls");
	cout << "****                           6.������ģʽ                                ****" << endl;
	random_device rd;	//����
	uniform_int_distribution<int> dicSeed(1, dataBase.wordSize() - 1);	//���ɴӴʵ�ȡ���ʵ������������
	uniform_int_distribution<int> ansSeed(0, 3);						//�����ĸ����е�һ����Ϊ�𰸵�����
	uniform_int_distribution<int> exaSeed(0, 1);						//������Ŀ�Ǻ���Ӣ����Ӣ�뺺������
	dicSeed(rd);
	wordList optAns[4];	//�洢�ĸ���ѡ��
	string answer;	//������Ŵ�
	int ansNum, chsNum;
	int score = 0, count = 1;
	int range;	//������Ŀ
	int exam;
	double ratio;
	cout << "��ӭ����\"������\"ģʽ������ϣ�������������أ�      ";	//�����ĳɿ�ѡ
	cin >> range;
	cout << "Link start!" << endl << endl;
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

			cin >> chsNum;
			chsNum--;	//ƥ��������ϰ��
			if (chsNum == ansNum)
			{
				score++;
				cout << "������" << endl;
			}
			else
			{
				cout << "�Բ��������ˡ�" << endl;
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
				cout << "������" << endl;
			}
			else
			{
				cout << "�Բ��������ˡ�" << endl;
			}
		}
	}
	ratio = double(score) / double(range);
	cout << "���Խ�������һ������ " << score << "��" << "��ȷ��Ϊ " << ratio*100 <<"%�����ٽ�������" << endl;
}

void mainFrame::killShow()	//��ʾ��ն����
{
	system("cls");
	cout << "****                           3.��ʾ��ն����                              ****" << endl;
	cout << "��һ��ն��: " << killedBase.wordSize() << " �����ʣ�������ٽ�������" << endl;
//	system("notepad Data\\killed.dat");	//��ȡ�ļ�
	for (int i = 0; i < killedBase.wordSize(); i++)
	{
		wordList BUFFER;
		BUFFER = killedBase.getWord(i);
		cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
	}
	outputBlank(2);
	cout << "����������ء� " << endl;
	fflush(stdin);
	getchar();
}

void mainFrame::wordKiller(int Num)
{
	int judge;
	cout << "����1ն����������0��������      ";
	cin >> judge;
	if (judge == 1)
	{
		killedBase.addWord(dataBase.getWord(Num));
		dataBase.removeWord(Num+1);
	}
}

void mainFrame::killedRescue()	//�ָ���ն����
{
	system("cls");
	bool FLAG = true;
	string temp = "!";
	cout << "****                           4.�ָ���ն����                              ****" << endl;
	outputBlank(2);
	while (temp != "#")
	{
		if (killedBase.wordIsEmpty())
		{
			int goKill;
			cout << "����նɱ�����ǿյģ���ն��ʹ����(1ȥ/0��ȥ)" << endl;
			cin >> goKill;
			fflush(stdin);
			if (goKill)
			{
				wordExercise();
				return ;
			}
			else
			{
				return ;
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
		cout << "����������ָ��ĵ��ʵ�Ӣ��ƴд������#�˳��ָ����ܣ�" << endl;
		cin >> temp;
		if (temp == "#")
		{
			return ;
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
