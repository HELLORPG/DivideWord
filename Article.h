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
	// string divide_result;
	// vector<string> other

	int art_len;
public:
	Article(string filename);
	Article(const Article &art);
	~Article();
	void divide(const Dictionary& dic);
	void print_divide();
};