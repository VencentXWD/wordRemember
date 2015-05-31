#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

typedef struct __CONFIG
{
	bool FIRST = false;	//�Ƿ��ǵ�һ��ʹ��
	int VER;			//�汾��
	int wordNum;		//��������
	/*...*/
}__CONFIG;

class Word
{
public:
	/*��ʼ���Լ�����*/
	Word();
	~Word();
	void wordInit();	//������һ��ʹ�ñ����ʱ����
public:
	/*�ʵ����ù���*/
	void wordInput();
	void wordShow();
	void wordChange();
	void wordDelete();
public:
	/*���书��*/
	void wordRmber();
protected:
	vector<string> English;
	vector<string> Chinese;
	__CONFIG confFile;
};
