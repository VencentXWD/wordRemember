#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "dataBase.h"

using namespace std;

typedef class __MAINFRAME
{
public:					/*构造、析构函数*/
		__MAINFRAME();
		~__MAINFRAME();
public:					/*功能*/
	void wordInit();	//初始化界面
	void wordInput();	//录入新单词
	void wordShow();	//显示词典
	void sortWord();	//单词排序
	void wordChange();	//修改单词
	void wordDelete();	//删除单词
	void wordExercise();//背单词
	void wordExit();	//退出本软件
//public:
//	__DATABASE getDatabase();	//test
protected:
	__DATABASE dataBase;//数据库
}mainFrame;
