/*ֱ�Ӷ��ļ���������*/

#pragma once

#include <iostream> 
#include <vector>
#include "wordList.h"

using namespace std;

typedef class __DATABASE
{
public:	
	__DATABASE();	//��ȡ�ļ�
	~__DATABASE();	//�����ļ�
public:
	int wordSize();						//ͳ�Ƶ�����������ֵΪ������
	bool wordIsEmpty();					//�жϴʵ��Ƿ�Ϊ�գ�����ֵΪ�ж��Ƿ�Ϊ��
	void sortWord();					//���ֵ���Դʵ��������
	void addWord(__WORDLIST);			//����µ���
	bool removeWord(int);				//����Ӣ����Ų��Ҳ�ɾ������
	__WORDLIST getWord(int);			//����Ӣ����Ŷ�Ӧ���ʣ�����ֵΪ������
	int searchWord(string);				//����Ӣ�Ĳ��Ҷ�Ӧ���ʣ�����ֵΪ������ţ����֣�
	bool changeWordNum(int, __WORDLIST);//����Ŷ�Ӧ���ʲ��޸ģ������Ƿ�ɹ�
protected:
	vector<__WORDLIST> word;
	__WORDLIST wordlist;
}DATABASE;
