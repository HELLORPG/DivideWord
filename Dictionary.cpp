#include "Dictionary.h"


Dictionary::Dictionary(string dic_name)
{
	if (dic_file.open_file(dic_name, std::ios::in) == 0)
	{
		cout << "<WRONG> [词典文件打开失败]" << endl;
		exit(-1);
	}
	name = dic_name;

	// 之后是文件打开成功的样子

	dic_file.readfile_to_vectorstring(); // 数据读入file的变量中

	//之后需要将vector中的数据对应到hash中
	// transform(dic_file.vectorstring.begin(), dic_file.vectorstring.end(), hash_dic);
	for (const auto &word : dic_file.vectorstring)
	{
		hash_dic.insert(word);
		word_max_len = max(word_max_len, (int)word.length());
	}

	dic_size = hash_dic.size();
	// cout << (hash_dic.find("高若朋") != hash_dic.end())<< endl;
	// 通过上面注释掉的语句测试了生成的hash可以使用
#ifdef GRPPRINT
	cout << "[词典 " << name << " 创建成功，共计 "<< dic_size << " 词条，最长词长为 "<< word_max_len << "]" << endl;
#endif
	return;
}

Dictionary::~Dictionary()
{
	
}

bool Dictionary::find(string word) const
{
	return hash_dic.find(word) != hash_dic.end();
}


int Dictionary::get_word_max() const
{
	return word_max_len;
}

