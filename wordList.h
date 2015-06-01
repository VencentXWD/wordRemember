#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

typedef class __WORDLIST
{
public:							/*������������*/
	__WORDLIST();
	~__WORDLIST();
public:	
	const string &getEnglish() const;		//��ȡ������Ϣ��Ϊ��dataBase�е�����հ�����˷���const
	const string &getChinese() const;

	void changeEnglish(string);	//�޸ĵ��ʳ�Ա
	void changeChinese(string);
protected:						//����˫��
	string English;
	string Chinese;
}wordList;

