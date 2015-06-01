#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "dataBase.h"

using namespace std;

typedef class __TESTMODE
{
public:					/*���졢��������*/
		__TESTMODE();
		~__TESTMODE();
public:					/*����*/

	void wordInit();	//��ʼ������
	void wordInput();	//¼���µ���
	void wordShow();	//��ʾ�ʵ�
	void wordChange();	//�޸ĵ���
	void wordDelete();	//ɾ������
	void wordExam();	//������
	void wordExit();	//�˳������
protected:
	__DATABASE dataBase;
}testMode;
