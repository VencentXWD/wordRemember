#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef class __WORDLIST
{
public:							/*������������*/
	__WORDLIST();				//Ĭ�ϱ����ǿգ�������getWord�������صľͲ���NULLָ����
	__WORDLIST(string, string, int);	//���ڳ�ʼ���������ʵĹ��캯��
	__WORDLIST(string, string);	//�����޸ĵ��ʵĹ��캯��
	~__WORDLIST();
public:	
	const string &getEnglish() const;		//��ȡ������Ϣ��Ϊ��dataBase�е�����հ�����˷���const
	const string &getChinese() const;
	const int &getWrongTimes() const;
	void changeEnglish(string);	//�޸ĵ��ʳ�Ա
	void changeChinese(string);
	void changeWrongTimes(int);
	void addWrongTimes();
protected:						//����˫��
	string English;
	string Chinese;
	int WrongTimes;	//���ʴ�Ĵ���
}wordList;

