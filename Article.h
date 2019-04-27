#pragma once
#include "Define.h"
#include "File.h"
#include "Dictionary.h"


class Article
{
private:
	File art_file;
	File divide_file;

	string artfile_name;
	string dividefile_name;

	vector<char> data;
	vector<string> divide_result;

	int art_len;
public:
	Article(string filename);
	~Article();
	void Divide(const Dictionary& dic);
	void print_divide();
};