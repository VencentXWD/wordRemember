//mainframe.h
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
		~__MAINFRAME() = default;
public:					/*����*/
	int CLIwordInit();	//��ʼ������
	void wordInput(string);	//¼���µ���
	void wordShow();	//��ʾ�ʵ�
	void killShow();	//��ʾ��ն����
	void wordChange();	//�޸ĵ���
	void wordDelete();	//ɾ������
	void wordLooking();//��ѯ����
	int wordKiller(int);//ն��
	void killedRescue();//�ָ���ն����
	void wordExercise();//������(��ն��)
	void wordExam();	//����ģʽ
	void wordReview();	//��ϰ���ʹ���
	void aboutMe();		//��������		
	void famousMotto();	//��ӡ����		**
	void wordExit();	//�˳������
	int datainit();	//��ʼ��ѯ��
//public:							//test
//	__DATABASE getDatabase();	//test
protected:
	__DATABASE dataBase;	//�������ݿ�
	__KILLEDLIST killedBase;//��ն�������ݿ�
	vector<string>	motto;	//�������
}mainFrame;
