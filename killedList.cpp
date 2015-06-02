#include "killedList.h"
#include <fstream>

using namespace std;


__KILLEDLIST::__KILLEDLIST() : __DATABASE()
{
	string enBuffer;
	string cnBuffer;
	ifstream fileRead("Data/killed.dat");	//����ն�ʵ�
	if (!fileRead)
	{
		/*��ʾ������Ϣ*/
		cerr << "�Ҳ���ն���ļ���" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	vector<wordList>().swap(word);
//	word.clear();
//	cout << word.capacity() << endl;
	sortWord();
	while (fileRead >> enBuffer >> cnBuffer)	//Ӳ���ļ�ת���ڴ�
	{
		wordlist.changeChinese(cnBuffer);
		wordlist.changeEnglish(enBuffer);
		word.push_back(wordlist);				//�����������Ա�����
	}
	fileRead.close();
}

__KILLEDLIST::~__KILLEDLIST()
{
	ofstream fileWrite("Data/killed.dat", ios::out);
	for (int i = 0; i < wordSize(); i++)
	{
		fileWrite << word[i].getEnglish() << " " << word[i].getChinese() << endl;
	}
	fileWrite.close();
}
