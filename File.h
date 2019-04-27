#pragma once
#include "Define.h"

class File
{
	friend class Dictionary;
private:
	fstream file;
	string name;
	vector<string> vectorstring; // �ֵ�Ķ��뷽ʽ����string���д洢

public:
	bool open_file(string filename, std::ios::openmode mode); // �򿪳ɹ��ͷ���true����֮��Ȼ

	void readfile_to_vectorstring(); // �����ݶ���vector<string>��




	void print_vectorstring();
};