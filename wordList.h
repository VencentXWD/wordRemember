#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

typedef class __WORDLIST
{
public:							/*������������*/
	__WORDLIST();				//Ĭ�ϱ����ǿգ�������getWord�������صľͲ���NULLָ����
	__WORDLIST(string, string);	//���ڳ�ʼ�����������Լ��޸ĵ��ʵĹ��캯��
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

