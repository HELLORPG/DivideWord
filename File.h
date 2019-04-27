#pragma once
#include "Define.h"

class File
{
	friend class Dictionary;
	friend class Article;
private:
	fstream file;
	string name;
	vector<string> vectorstring; // 字典的读入方式采用string进行存储
	vector<char> vectorchar; // 这里拟采用char的方式存储文章
public:
	~File();
	File() {}
	File(const File &f);
	File& operator=(const File &f);
	bool open_file(string filename, std::ios::openmode mode); // 打开成功就返回true，反之亦然

	void readfile_to_vectorstring(); // 将数据读入vector<string>中
	void readfile_to_vectorchar();


	void writefile_vectorstring();

	void print_vectorstring();
	void print_vectorchar();
};