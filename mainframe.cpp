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
	/*���*/
}

void mainFrame::wordChange()	//�޸ĵ���
{
	string curEnglish;
	string curChinese;
	int Num = -1;
	/*�����ʾ��Ϣ����������Ҫ�޸ĵĵ������*/
	if (!Num)
	{
		/*��ʾ���ʲ����ڣ�������󣬷���*/
	}
	else
	{
		/*�����ʾ��Ϣ�����뵥�ʵ�Ӣ��*/
		/*�����ʾ��Ϣ�����뵥�ʵ�����*/
		wordList *__BUFFER = new wordList(curEnglish, curChinese);
		dataBase.changeWordNum(Num, *__BUFFER);
		delete __BUFFER;
		/*��ʾ�޸ĳɹ�*/
	}
}

void mainFrame::wordDelete()	//ɾ������
{
	string curEnglish;
	string curChinese;
	int Num = -1;
	/*�����ʾ��Ϣ����������Ҫɾ�����ʵ����*/
	if (!Num)	//������
	{
		/*��ʾ���ʲ����ڣ��������,����*/
	}
	else
	{
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