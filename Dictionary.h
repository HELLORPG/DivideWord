#pragma once
#include "Define.h"
#include "File.h"
#include <unordered_set>


class Dictionary
{
private:
	File dic_file;
	string name;

	set<string> set_dic; // 之前想过用set实现
	// hash<string> hash_dic;
	std::unordered_set<string> hash_dic;

	int word_max_len; // 词典中最长的词长
	int dic_size;
	
public:
	// Dictionary(vector<string> read_data);
	Dictionary() : word_max_len(0) {}
	Dictionary(string dic_name);
	~Dictionary();

	bool find(string word) const;
	int get_word_max() const;
};
