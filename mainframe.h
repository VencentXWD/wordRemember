#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "dataBase.h"
#include "killedList.h"

using namespace std;

typedef class __MAINFRAME
{
public:					/*���졢��������*/
		__MAINFRAME();
		~__MAINFRAME();
public:					/*����*/
	int CLIwordInit();	//��ʼ������
	void wordInput();	//¼���µ���
	void wordShow();	//��ʾ�ʵ�
	void killShow();	//��ʾ��ն����
	void sortWord();	//��������
	void wordChange();	//�޸ĵ���
	void wordDelete();	//ɾ������
	void wordLooking();//��ѯ����
	void wordKiller(int);//ն��
	void killedRescue();//�ָ���ն����
	void wordExercise();//������(��ն��)
	void wordExam();	//�Ǻ���ģʽ
	void wordReview();	//��ϰ���ʹ���
	void aboutMe();		//��������		
	void famousMotto();	//��ӡ����		**
	void wordExit();	//�˳������
//public:							//test
//	__DATABASE getDatabase();	//test
protected:
	__DATABASE dataBase;	//�������ݿ�
	__KILLEDLIST killedBase;//��ն�������ݿ�
}mainFrame;
