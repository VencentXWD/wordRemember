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

void mainFrame::famousMotto()	//��ӡ����
{
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
	system("cls");
	outputBlank(10);
	cout << "                  HitomiSAMA�����˲ʵ���Young man��" << endl;
	outputBlank(10);
	system("pause");
}

int mainFrame::CLIwordInit()		//�����а��ʼ������
{
	int choice;
	bool initFlag = true;
	bool exitflag = false;
	//	system("cls");
	while (1)
	{
		if (exitflag == true)
		{
			outputBlank(12);
			cout << setw(50) << "ллHitomiSAMA��ʹ�ã�" << setw(20);
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
		cout << "****                           6.�Ǻ���ģʽ                                ****" << endl;
		cout << "****                           7.�޸ĵ���                                  ****" << endl;
		cout << "****                           8.ɾ������                                  ****" << endl;
		cout << "****                           9.��ϰ���                                  ****" << endl;
		cout << "****                           10.�˳����                                 ****" << endl;
		outputBlank(1);
		if (initFlag == true)
		{
			cout << "��ѡ��HitomiSAMA��Ҫʹ�õĹ��ܣ�     ";
		}
		else
		{
			cout << "HitomiSAMA���������������ԣ�" << endl;
		}
		cin >> choice;
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
		case 9: wordReview();	 break;
		case 0: wordLooking();	 break;
		case 10: exitflag = true; break;
		case 12345: aboutMe();	 break;
		}
		system("cls");
	}
}
void mainFrame::wordLooking()//��ѯ����
{
	system("cls");
	string curEnglish = "!";
	cout << "****                           0.���ʲ�ѯ                                  ****" << endl;
	outputBlank(2);
	while (curEnglish != "#")
	{
		cout << "������HitomiSAMA��Ҫ��ѯ�ĵ��ʵ�ƴд������\"#\"�˳���ѯ���ܣ�    ";
		cin >> curEnglish;
		fflush(stdin);
		int wd = dataBase.searchWord(curEnglish);
		if (wd == -1)
		{
			cout << "��û���ҵ��õ��ʣ�" << endl << endl;
		}
		else
		{
			cout << "���� " << curEnglish << " �����Ľ���Ϊ�� " << dataBase.getChinese(wd) << endl << endl;
		}
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
		cout << "������HitomiSAMA��Ҫ¼���Ӣ�ĵ��ʣ���#�˳���      ";
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
			int flag = 0;
			cout << "HitomiSAMAҪ¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ�� " << curChinese << "ȷ��¼�뱾������(1ȷ��0������)" << endl;
			cin >> flag;
			if (flag == 1)
			{
				wordList BUFFER(curEnglish, curChinese, 0);
				dataBase.addWord(BUFFER);
				cout << "¼����ϣ�HitomiSAMA¼��ĵ���Ϊ: " << curEnglish << "�� ���Ľ���Ϊ�� " << curChinese << endl;
			}
			else if (flag == 0)
			{
				cout << "�����ɹ���" << endl << endl;
			}
			else
			{
				cout << "HitomiSAMA�������Ϣ����" << endl;
			}
		}
	}
}

void mainFrame::wordShow()	//��ʾ�ʵ���Ϣ
{
	int LEN = dataBase.wordSize();
	/*�����ʾ��Ϣ���鿴�굥�ʱ����ر�*/
	system("cls");
	cout << "****                           2.��ʾ�ʵ�                                  ****" << endl;
	outputBlank(2);
	cout << "HitomiSAMA�Ĵʵ���һ���� " << dataBase.wordSize() << "�����ʡ�" << endl;
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
	int flag = 1;
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
			cout << endl << "HitomiSAMA��û������κε��ʣ��Ƿ�Ҫ��ӵ���(1���/0�����)��" << endl;
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
		while (flag == 1 || curEnglish != "#")
		{
			cout << "������HitomiSAMA��Ҫ�޸ĵĵ��ʵ�ƴд������#�˳���      ";		//�ʿ�̫�󣬲��ṩ����޸ķ���
			cin >> curEnglish;
			fflush(stdin);	//��ջ�����
			if (dataBase.searchWord(curEnglish) < 0)
			{
				/*��ʾ���ʲ����ڣ�������󣬷���*/
				cout << "�˵��ʲ����ܴ��ڣ������ԡ�" << endl;
			}
			else
			{
				Num = dataBase.searchWord(curEnglish);
				cout << "�˵��ʵ����Ľ���Ϊ�� " << dataBase.getChinese(Num) << endl;
				cout << "������HitomiSAMA��Ҫ�޸ĵ��ʶ�Ӧ�����Ľ��ͣ�      ";
				cin >> curChinese;
				fflush(stdin);
				wordList BUFFER(curEnglish, curChinese, dataBase.getWordWrongTime(Num));	/*д*/
				dataBase.changeWordNum(Num, BUFFER);
				cout << "�޸ĳɹ��� �Ƿ�����޸ģ�1��/0�񣩣�    ";
				cin >> flag;
			}
		}
		getchar();
		return;
		/*��ʾ�޸ĳɹ�*/
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
		cout << "������HitomiSAMA��ɾ���ĵ��ʵ�Ӣ�ģ�����#�˳���      ";
		cin >> curEnglish;
		if (curEnglish == "#")
		{
			break;
		}
		if (dataBase.searchWord(curEnglish) < 0)	//������
		{
			cout << "HitomiSAMAѡ�ĵ��ʲ������ڣ�������ѡ�� " << endl;
		}
		else
		{
			int flag;
			cout << "ȷ��Ҫɾ�����𣿣�1��/0��    ";
			cin >> flag;
			fflush(stdin);
			if (flag == 1)
			{
				Num = dataBase.searchWord(curEnglish) + 1;
				dataBase.removeWord(Num);
				cout << "ɾ���ɹ���HitomiSAMA��Ҳ����������" << endl;
			}
			else
			{
				cout << "�����ɹ���" << endl;
			}
		}
	}
}

void mainFrame::wordExercise()	//������
{
	system("cls");
	cout << "****                           5.������                                    ****" << endl;
	random_device rd;
	uniform_int_distribution<int> dicSeed(0, dataBase.wordSize() - 1);	//���ɴӴʵ�ȡ���ʵ������������
	dicSeed(rd);
	vector<wordList> answers;
	int flag = 1;
	while (flag == 1)
	{
		if (flag != 1)
		{
			return;
		}
		int TIME;
		cout << "HitomiSAMA�Ĵʵ�����" << dataBase.wordSize() << "�����ʣ�HitomiSAMA�뱳�������ʣ�      ";
		cin >> TIME;
		fflush(stdin);
		for (int i = 0; i < TIME; i++)
		{
			int chosen = dicSeed(rd);
			wordList word = dataBase.getWord(chosen);
			answers.push_back(word);
			cout << "Round " << i + 1 << ":  " << answers[i].getEnglish() << setw(10) << answers[i].getChinese() << endl;
			wordKiller(chosen);	//ն�ʹ���
		}
		cout << endl << "�����ˣ���Ҫ����һ����(1��һ��/0������)      ";
		cin >> flag;
	}
}

void mainFrame::wordExam()	//�Ǻ���ģʽ
{
	system("cls");
	cout << "****                           6.�Ǻ���ģʽ                                ****" << endl;
	random_device rd;	//����
	uniform_int_distribution<int> dicSeed(0, dataBase.wordSize() - 1);	//���ɴӴʵ�ȡ���ʵ������������
	uniform_int_distribution<int> ansSeed(0, 3);						//�����ĸ����е�һ����Ϊ�𰸵�����
	uniform_int_distribution<int> exaSeed(0, 1);						//������Ŀ�Ǻ���Ӣ����Ӣ�뺺������
	dicSeed(rd);
	wordList optAns[4];	//�洢�ĸ���ѡ��
	wordList temp;		//���ڴ洢��ĵ���
	string answer;	//������Ŵ�
	int ansNum, chsNum;
	int score = 0, count = 1;
	int range;	//������Ŀ
	int exam;
	double ratio;
	cout << "��ӭ����\"�Ǻ���\"ģʽ��HitomiSAMAϣ�������������أ�      ";
	cin >> range;
	//range = 5;	//test
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
				cout << "HitomiSAMA�����" << endl;
			}
			else
			{
				int wr = dataBase.searchWord(optAns[ansNum].getEnglish());	//���´���ڴʵ�vector�е�λ��
				cout << "�Բ���HitomiSAMA����ˡ�" << endl;
				dataBase.addWrongTimes(wr);
				//cout << "+1" << endl;
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
				cout << "HitomiSAMA�����" << endl;
			}
			else
			{
				int wr = dataBase.searchWord(optAns[ansNum].getEnglish());	//���´���ڴʵ�vector�е�λ��
				cout << "�Բ���HitomiSAMA����ˡ�" << endl;
				dataBase.addWrongTimes(wr);
				//cout << "+1" << endl;
			}
		}
	}
	ratio = double(score) / double(range);
	cout << "Stop��HitomiSAMAһ������ " << score << "��" << "��ȷ��Ϊ " << ratio * 100 << "%�����ٽ�������" << endl;
	cout << endl << "��������˳���" << endl;
	fflush(stdin);
	getchar();
}

void mainFrame::killShow()	//��ʾ��ն����
{
	system("cls");
	cout << "****                           3.��ʾ��ն����                              ****" << endl;
	if (killedBase.wordSize() == 0)
	{
		int flag;
		cout << endl << "HitomiSAMA��û��ն�κε��ʣ�HitomiSAMA��ն��ʹ����(1��/0��)      ";
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
	cout << "HitomiSAMAһ��ն��: " << killedBase.wordSize() << " �����ʣ�������ٽ�������" << endl;
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

void mainFrame::wordKiller(int Num)		//ն��
{
	int judge;
	cout << "����1ն����������0��������      ";
	cin >> judge;
	if (judge == 1)
	{
		killedBase.addWord(dataBase.getWord(Num));
		dataBase.removeWord(Num + 1);
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
			cout << "HitomiSAMA��նɱ�����ǿյģ���ն��ʹ����(1ȥ/0��ȥ)    ";
			cin >> goKill;
			fflush(stdin);
			if (goKill)
			{
				wordExercise();
				return;
			}
			else
			{
				return;
			}
		}
		if (FLAG)
		{
			cout << "HitomiSAMAһ��ն��: " << killedBase.wordSize() << " �����ʡ�" << endl;
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
		cout << "������HitomiSAMA��ָ��ĵ��ʵ�Ӣ��ƴд������#�˳��ָ����ܣ�" << endl;
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
	int fuck = 1;
	bool flag = true;
	string curEnglish = "!";
	system("cls");
	cout << "****                           9.��ϰ���                                  ****" << endl;
	outputBlank(2);
	vector<__WORDLIST> temp = dataBase.getWrongWords();	//��ȡ��ʵ�����
	int LEN = temp.size();
	if (LEN == 0)
	{
		cout << "HitomiSAMAһ����ʶ�û�У���һ����û�кúñ����ʣ���ȥ�����ʣ�" << endl;
		system("pause");
		wordExam();
		return;
	}
	cout << "�ڹ�ȥ�������HitomiSAMAһ������ " << temp.size() << "�����ʣ����Ƿֱ��ǣ�   " << endl;
	for (int i = LEN - 1; i >= 0; i--)
	{
		cout << temp[i].getEnglish() << "  \""
			<< temp[i].getChinese() << "\"  "
			<< "���� " << temp[i].getWrongTimes() << "�Ρ�" << endl;
	}
	outputBlank(5);
	while (fuck == 1)
	{
		if (flag)
		{
			cout << "����HitomiSAMA��һ����ս���ǵĻ��ᣬ�Ƿ�ӭս������ʾ��������ս��ͬһ�㣩(1��/0��)   ";
			flag = false;
		}
		else if (!flag && curEnglish != "#")
		{
			cout << "HitomiSAMAˬ�գ��Ƿ�����һ�Σ�(1��/0��)" << endl;
		}
		else
		{
			outputBlank(5);
			cout << "*******************HitomiSAMA���ˣ�*******************" << endl;
			outputBlank(5);
			fflush(stdin);
			system("pause");
			return;
		}
		cin >> fuck;
		if (fuck == 1)
		{
			system("cls");
			random_device rd;	//����
			uniform_int_distribution<int> dicSeed(0, LEN - 1);	//���ɴӴʵ�ȡ���ʵ������������
			dicSeed(rd);
			int rdm;
			cout << "HitomiSAMA��ˬ�죡��ս20���غϣ��볷�˵Ļ�����ʹ��\"#\"" << endl;
			for (int i = 0; i < 20; i++)
			{
				if (curEnglish == "#")
				{
					break;
				}
				rdm = dicSeed(rd);
				cout << "Round " << i + 1 << ": ��д����˼Ϊ \"" << temp[rdm].getChinese() << "\" �ĵ��ʵ�ƴд��    ";
				cin >> curEnglish;
				fflush(stdin);
				if (curEnglish != temp[rdm].getEnglish())
				{
					cout << "HitomiSAMA�ش���ˣ���ȷ��Ӧ���ǣ� " << temp[rdm].getEnglish() << endl;
				}
				else if (curEnglish == temp[rdm].getEnglish())
				{
					int choice;
					cout << "HitomiSAMA�ش���ȷ���Ƿ�����Żأ��ŻؾͲ�������������ˣ�����(1���˰�/0����)    ";
					cin >> choice;
					if (choice == 1)
					{
						dataBase.rmFromWrong(curEnglish);
						LEN--;
					}
					if (LEN == 0)
					{
						cout << "HitomiSAMAû���κδ�����~" << endl;
						system("pause");
						return ;
					}
				}
			}
		}
		else
		{
			return;
		}
	}
	fflush(stdin);
	getchar();
}
