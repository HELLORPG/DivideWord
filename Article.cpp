#include "Article.h"


Article::Article(string filename)
{
	artfile_name = filename;
	art_file.open_file(artfile_name, std::ios::in); 
	dividefile_name = ""; // 进行强制初始化
	for (const auto &c : artfile_name)
	{
		if (c == '.')
			break;
		else
			dividefile_name.push_back(c);
	}
	dividefile_name = dividefile_name + "_divide.txt"; // 规定了分词之后的输出文件



	art_file.readfile_to_vectorchar();
	data = art_file.vectorchar;
	art_len = data.size();
#ifdef GRPPRINT
	cout << "[文章 " << artfile_name << " 读取成功，共计 " << art_len << " 字]" << endl;
#endif

#ifdef GRPDEBUG
	art_file.print_vectorchar();
#endif

	return;
}

Article::~Article()
{
	
}

void Article::Divide(const Dictionary& dic)
{
	divide_file.open_file(dividefile_name, std::ios::out);

	string word; // 这个是每次分词之后得到的词语
	int dic_word_max(dic.get_word_max());
	for (int i(0); i < art_len; ++i)
	{
		int m(0);
		i + dic_word_max < art_len ? m = dic_word_max : m = art_len - i; // 并没有深究越界与否

		for (; m > 0; --m)
		{
			word.clear(); // 进行word的初始化
			for (int j(0); j < m; ++j)
			{
				word.push_back(data[i + j]);
			} // 将长度为m的词压入word中待命

			if (dic.find(word)) // 如果找到了这个词，说明分词成功
			{
				divide_result.push_back(word);
				i += m - 1;
				break;
			}
		}
	}

	// 分词结束，下面需要写入文件
	divide_file.vectorstring = divide_result; // 这里可以通过减少copy来达到增加时间效率的目的
	divide_file.writefile_vectorstring();

	return;

}

void Article::print_divide()
{
	cout << "<DEBUG> [PRINT divide result]" << endl;
	for (const auto &x : divide_result)
		cout << x << " ";
	cout << endl;

	return;
}


