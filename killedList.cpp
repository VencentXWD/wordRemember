//killedList.cpp
#include "killedList.h"
#include <fstream>

using namespace std;


__KILLEDLIST::__KILLEDLIST() : __DATABASE()
{
	string enBuffer;
	string cnBuffer;
	int tmBuffer;
	ifstream fileRead("Data/killed.dat");	//����ն�ʵ�
	if (!fileRead)
	{
		/*��ʾ������Ϣ*/
		cerr << "�Ҳ���ն���ļ���" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	vector<wordList>().swap(word);//�����Ǽ̳����ģ������ڵ������๹�캯��ʱһ������ø���ġ�
								  //��ʱ��vector�ڷǿգ�������������vector��
//	word.clear();				  //�����У��õ���ֵ��һ����0��word��һ���ǿգ�
//	cout << word.capacity() << endl;
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

__KILLEDLIST::~__KILLEDLIST()
{
	ofstream fileWrite("Data/killed.dat", ios::out);
	for (int i = 0; i < wordSize(); i++)
	{
		fileWrite << word[i].getEnglish() << " " 
				  << word[i].getChinese() << " " 
				  << word[i].getWrongTimes() << endl;
	}
	fileWrite.close();
}
