#pragma once
#include "Define.h"

class File
{
	friend class Dictionary;
	friend class Article;
private:
	fstream file;
	string name;
	vector<string> vectorstring; // �ֵ�Ķ��뷽ʽ����string���д洢
	vector<char> vectorchar; // ���������char�ķ�ʽ�洢����
public:
	~File();
	File() {}
	File(const File &f);
	File& operator=(const File &f);
	bool open_file(string filename, std::ios::openmode mode); // �򿪳ɹ��ͷ���true����֮��Ȼ

	void readfile_to_vectorstring(); // �����ݶ���vector<string>��
	void readfile_to_vectorchar();


	void writefile_vectorstring();

	void print_vectorstring();
	void print_vectorchar();
};