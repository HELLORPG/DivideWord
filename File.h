#pragma once
#include "Define.h"

class File
{
	friend class Dictionary;
private:
	fstream file;
	string name;
	vector<string> vectorstring; // 字典的读入方式采用string进行存储

public:
	bool open_file(string filename, std::ios::openmode mode); // 打开成功就返回true，反之亦然

	void readfile_to_vectorstring(); // 将数据读入vector<string>中




	void print_vectorstring();
};