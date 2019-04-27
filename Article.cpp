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

void Article::divide(const Dictionary& dic)
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

			// 据说中文的所有的字都是负值，所以可以根据这种方法来进行划分
			if (m == 2)
			{
				if (data[i] < 0/* || (ispunct(data[i]) == 1 && ispunct(data[i + 1] == 1))*/)
				{
					word.clear();
					word.push_back(data[i]);
					word.push_back(data[i + 1]);// [i] + data[i + 1];
					divide_result.push_back(word);
					++i;
					break;
				}			
			}

			else if (m == 1)
			{
				bool flag(false);
				// cout << "?" << endl;
				word.clear();
				for (; i < data.size(); ++i)
				{
					// word.push_back(data[i]);
					if ((data[i] <= '9' && data[i] >= '0')
						|| (data[i] >= 'a' && data[i] <= 'z')
						|| (data[i] >= 'A' && data[i] <= 'Z'))
					{
						word.push_back(data[i]);
						flag = true;
					}
					else
					{
						if (flag)
							--i;
						// cout << "?" << endl;
						break;
					}
				}
				if (!flag)
					word.push_back(data[i]);

				divide_result.push_back(word);
				break;
			}
		}
	}
	/*
	 * v1.0
	 * 上面的分词算法最后只能得到所有在词典中的词语
	 * 而根据对于正向匹配的分析可以得到，需要的是所有的词，如果词典中没有，就作为单字输出
	 * 
	 * v2.0
	 * 更改了1.0中遇见的问题，同时将分词结果中的中英文合并成为一个词，有利于观感
	 */




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

Article::Article(const Article& art)
{
	art_file = art.art_file;
	divide_file = art.divide_file;
	artfile_name = art.artfile_name;
	dividefile_name = art.dividefile_name;

	data = art.data;
	divide_result = art.divide_result;

	art_len = art.art_len;
}



