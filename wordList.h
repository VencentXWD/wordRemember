//wordList.h
#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;



typedef class __WORDLIST
{
public:	/*������������*/
	__WORDLIST() = default;				//Ĭ�Ϲ��캯��
	__WORDLIST(string, string, int);	//���ڳ�ʼ���������ʶ����صĹ��캯��
	__WORDLIST(string, string);			//�����޸ĵ��ʶ����صĹ��캯�� 
	~__WORDLIST() = default;
public:	
	const string &getEnglish() const;	//��ȡ������Ϣ��Ϊ��dataBase�е�����հ�����˷���const
	const string &getChinese() const;
	const int &getWrongTimes() const;
	void changeEnglish(string);			//�޸ĵ��ʳ�Ա
	void changeChinese(string);
	void changeWrongTimes(int);
	void addWrongTimes();
protected:								//����˫��
	string English;
	string Chinese;
	int WrongTimes;						//���ʴ�Ĵ���
}wordList;

