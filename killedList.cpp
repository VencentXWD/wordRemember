#include "killedList.h"
#include <fstream>
using namespace std;


__KILLEDLIST::__KILLEDLIST()
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
	sortWord();
	while (fileRead >> enBuffer >> cnBuffer)	//Ӳ���ļ�ת���ڴ�
	{
		wordlist.changeChinese(cnBuffer);
		wordlist.changeEnglish(enBuffer);
		word.push_back(wordlist);				//�����������Ա�����
	}
	fileRead.close();
}


__KILLEDLIST::~__KILLEDLIST() {}
