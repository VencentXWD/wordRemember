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
	int wordSize();							//ͳ�Ƶ�����������ֵΪ������
	bool wordIsEmpty();						//�жϴʵ��Ƿ�Ϊ�գ�����ֵΪ�ж��Ƿ�Ϊ��
	void sortWord();						//���ֵ���Դʵ��������
	void addWord(wordList);					//����µ���
	wordList getWord(int);					//����Ӣ����Ŷ�Ӧ���ʣ�����ֵΪ������
	int searchWord(string);					//����Ӣ�Ĳ��Ҷ�Ӧ���ʣ�����ֵΪ������ţ����֣�
	bool changeWordNum(int, wordList);		//����Ŷ�Ӧ���ʲ��޸ģ������Ƿ�ɹ�
//	bool changeWordWod(wordList, wordList);	//�����ʶ�ӦӢ�Ĳ��޸ģ������Ƿ�ɹ�
protected:
	vector<wordList> word;
	wordList wordlist;
}DATABASE;
