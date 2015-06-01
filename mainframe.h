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
	void wordInit();	//��ʼ������
	void wordInput();	//¼���µ���
	void wordShow();	//��ʾ�ʵ�
	void killShow();	//��ʾ��ն����*
	void sortWord();	//��������
	void wordChange();	//�޸ĵ���
	void wordDelete();	//ɾ������
	void wordExercise();//������
	void wordExam();	//������
	void wordExit();	//�˳������
//public:
//	__DATABASE getDatabase();	//test
protected:
	__DATABASE dataBase;	//�������ݿ�
	__KILLEDLIST killedBase;//��ն�������ݿ�
}mainFrame;
