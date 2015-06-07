#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "dataBase.h"

#define NOTFOUND_INT -1
#define NOTFOUND_BOOL false
#define CHANGESUCCESS true

using namespace std;

__DATABASE::__DATABASE()	/*��ʼ������*/
{
	string enBuffer;
	string cnBuffer;
	int tmBuffer;

	ifstream fileRead("Data/dictionary.dat");	//�򿪴ʵ�
	if (!fileRead)
	{	
		/*��ʾ������Ϣ*/
		cerr << "�Ҳ����ʵ��ļ����뽫�ʵ��ļ�����Data�ļ����ڣ�" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	sortWord();
	while (fileRead >> enBuffer >> cnBuffer >> tmBuffer)	//Ӳ���ļ�ת���ڴ�
	{
		wordlist.changeChinese(cnBuffer);
		wordlist.changeEnglish(enBuffer);
		wordlist.changeWrongTimes(tmBuffer);

		word.push_back(wordlist);				//�����������Ա�����
	}
	fileRead.close();
}

__DATABASE::~__DATABASE()						//����ʵ�
{
	ofstream fileWrite("Data/dictionary.dat", ios::out);
	for (int i = 0; i < wordSize(); i++)
	{
		fileWrite << word[i].getEnglish() << " " 
				  << word[i].getChinese() << " " 
				  << word[i].getWrongTimes() << endl;
	}
	fileWrite.close();
}

int DATABASE::wordSize()		//ͳ�Ƶ�����������ֵΪ������
{
	return word.size();
}

bool DATABASE::wordIsEmpty()	//�жϴʵ��Ƿ�Ϊ�գ�����ֵΪ�ж��Ƿ�Ϊ��
{
	return wordSize() == 0 ? true : false;
}

void DATABASE::sortWord()		//���ֵ���Դʵ��������
{
	sort(begin(word), end(word), [](const wordList &a, const wordList &b) //�հ����sort��ֵ����
	{
		return a.getEnglish() < b.getEnglish();
	});
}

void DATABASE::addWord(wordList curwordlist)	//����µ���
{
	word.push_back(curwordlist);
	sortWord();
}

wordList DATABASE::getWord(int num)				//����Ӣ����Ŷ�Ӧ���ʣ�����ֵΪ���ʽڵ�
{
	if (num < 0 || num > wordSize() - 1)
	{
		wordList *null = new wordList();
		return *null;							//�±��Ϸ�������һ���սڵ�
	}
	return word[num];
}

bool DATABASE::removeWord(int num)				//ɾ������
{
	if(num < 0 || num > wordSize())
	{
		return NOTFOUND_BOOL;
	}
	else
	{
		word.erase(begin(word) + num - 1);
		return CHANGESUCCESS;
	}
}

int DATABASE::searchWord(string curEnglish)		//����Ӣ�Ĳ��Ҷ�Ӧ���ʣ�����ֵΪ������ţ����֣�
{
	sortWord();												//����֣�������
	int left = 0;
	int right = wordSize() - 1;
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (word[middle].getEnglish() == curEnglish)
		{
			return middle;
		}
		else if (word[middle].getEnglish() > curEnglish)	//����
		{
			right = middle - 1;
		}
		else												//����
		{
			left = middle + 1;
		}
	}
	return NOTFOUND_INT;
}

bool DATABASE::changeWordNum(int num, wordList curwordlist)				//����Ŷ�Ӧ���ʲ��޸ģ������Ƿ�ɹ�
{
	if (num < 0 || num > wordSize() - 1)
	{
		return NOTFOUND_BOOL;
	}
	word[num] = curwordlist;
	sortWord();				//����
	return CHANGESUCCESS;
}

int DATABASE::getWordWrongTime(int num)	//��ȡ�ôʴ����
{
	return word[num].getWrongTimes();
}

string DATABASE::getChinese(int num)	//��ȡ���ķ���
{
	return word[num].getChinese();
}


void DATABASE::addWrongTimes(int num)
{
	word[num].addWrongTimes();
}

vector<__WORDLIST> DATABASE::getWrongWords()	//��ȡ�����Ϣ
{
	vector<__WORDLIST> wrongWords;
	int LEN = wordSize();
	for (int i = 0; i < LEN; i++)
	{
		if (word[i].getWrongTimes() != 0)
		{
			wrongWords.push_back(word[i]);
		}
	}
	sort(begin(wrongWords), end(wrongWords), [](const wordList &a, const wordList &b)
	{
		return a.getWrongTimes() < b.getWrongTimes();
	});
	return wrongWords;
}

int DATABASE::getWordNum(string curEnglish)				//��ȡ������ţ�����ͳ�ƴ��
{
	return searchWord(curEnglish);
}

void DATABASE::rmFromWrong(string curEnglish)			//�Ӵ�ʿ���ɾ��
{
	int temp = searchWord(curEnglish);
	word[temp].changeWrongTimes(0);
}

//bool DATABASE::changeWordWod(wordList tarwordlist, wordList curwordlist)//�����ʶ�Ӧ���ʲ��޸ģ������Ƿ�ɹ�
//{
//	int LEN = wordSize() - 1;
//	bool FOUND = false;
//	for (int i = 0; i < LEN; i++)
//	{
//		if ()
//	}
//	if (FOUND)
//	{
//		return FOUND;
//	}
//	else
//	{
//		return NOTFOUND_BOOL;
//	}
//}
