#include "mainframe.h"

__MAINFRAME::__MAINFRAME() {}

__MAINFRAME::~__MAINFRAME() {}

void mainFrame::wordInit()		//��ʼ������
{

}

void mainFrame::wordInput()	//¼���µ���
{
	string curEnglish;
	string curChinese;
	/*�����ʾ��Ϣ���������� Ӣ�ĵ���*/
	if (dataBase.searchWord(curEnglish) >= 0)	//����
	{
		/*��ʾ�����Ѵ��ڣ�����Ҫ���,����*/
	}
	else
	{
		/*�����ʾ��Ϣ���������� ���ĵ���*/
		wordList* __BUFFER = new wordList(curEnglish, curChinese);
		dataBase.addWord(*__BUFFER);
		delete __BUFFER;
		/*����ɹ���ӵ��ʵ���Ϣ*/

		//  ����� delete[]�����ڻ��տռ�֮ǰ���ж��󶼻����ȵ����Լ�������������
		//	�������͵Ķ���û���������������Ի��ջ���������ɵ�����ռ��� delete �� delete[] ����Ӧ�ÿ��Եģ�
		//  ���Ƕ�����������飬ֻ���� delete[]��
		//  ���� new �ĵ�������ֻ���� delete ������ delete[] ���տռ䡣
	}
	return ;
}

void mainFrame::wordShow()	//��ʾ�ʵ�
{
	int LEN = dataBase.wordSize();
	/*�����ʾ��Ϣ���鿴�굥�ʱ����ر�*/
	for (int i = 0; i < LEN; i++)
	{
		wordList BUFFER;
		BUFFER = dataBase.getWord(i);
		cout << BUFFER.getEnglish() << " " << BUFFER.getChinese() << endl;
	}
//	system("notepad Data\\dictionary.dat");	//��ȡ�ļ�
	return ;
}

void mainFrame::sortWord()	//��������
{
	dataBase.sortWord();
	return ;
}
void mainFrame::wordChange()	//�޸ĵ���
{
	string curEnglish;
	string curChinese;
	int Num;
	/*�����ʾ��Ϣ����������Ҫ�޸ĵĵ���*/
//	cin >> curEnglish;
	if(dataBase.searchWord(curEnglish) < 0)
	{
		/*��ʾ���ʲ����ڣ�������󣬷���*/
//		cout << "no" << endl;
	}
	else
	{
		/*�����ʾ��Ϣ�����뵥�ʵ�����*/
//		cout << "yes!" << endl;
		cin >> curEnglish >> curChinese;
		Num = dataBase.searchWord(curEnglish) + 1;
		wordList BUFFER(curEnglish, curChinese);
		dataBase.changeWordNum(Num, BUFFER);
		/*��ʾ�޸ĳɹ�*/
	}
}

void mainFrame::wordDelete()	//ɾ������
{
	string curEnglish;
	string curChinese;
	int Num;
	/*�����ʾ��Ϣ����������Ҫɾ���ĵ���*/
//	cin >> curEnglish;
	if (dataBase.searchWord(curEnglish) < 0)	//������
	{
		/*��ʾ���ʲ����ڣ��������,����*/
	}
	else
	{
		Num = dataBase.searchWord(curEnglish) + 1;
		dataBase.removeWord(Num);
		/*��ʾ����ɾ���ɹ�*/
	}
	return;
}

void mainFrame::wordExercise()//������
{

}

void mainFrame::wordExit()	//�˳������
{
	exit(EXIT_SUCCESS);
}

//__DATABASE testMode::getDatabase()	//test
//{
//	return dataBase;
//}