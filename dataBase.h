/*ֱ�Ӷ��ļ���������*/

#pragma once

#include <iostream> 
#include <vector>
#include "wordList.h"
using namespace std;


typedef class __DATABASE
{
public:									/*���졢������	��*/
	__DATABASE();
	~__DATABASE();
public:
	int wordSize();						//ͳ�Ƶ�����������ֵΪ������
	bool wordIsEmpty();					//�жϴʵ��Ƿ�Ϊ�գ�����ֵΪ�ж��Ƿ�Ϊ��
	void sortWord();					//���ֵ���Դʵ��������
	void addWord(wordList);				//����µ���
	int searchWord(string);				//����Ӣ�Ĳ��Ҷ�Ӧ���ʣ�����ֵΪ������ţ����֣�
	bool wordCompare(wordList, wordList);//�����ʵ�����ʹ�õ�sort������
protected:
	vector<wordList> word;
	wordList wordlist;
}DATABASE;
