#pragma once
#include "Define.h"
#include "File.h"
#include <unordered_set>


class Dictionary
{
private:
	File dic_file;
	string name;

	set<string> set_dic; // ֮ǰ�����setʵ��
	// hash<string> hash_dic;
	std::unordered_set<string> hash_dic;

	int max_len; // �ʵ�����Ĵʳ�
	int dic_size;
	
public:
	// Dictionary(vector<string> read_data);
	Dictionary() : max_len(0) {}
	Dictionary(string dic_name);

};
