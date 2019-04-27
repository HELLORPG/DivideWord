#include "Article.h"


Article::Article(string filename)
{
	artfile_name = filename;
	art_file.open_file(artfile_name, std::ios::in); 
	dividefile_name = ""; // ����ǿ�Ƴ�ʼ��
	for (const auto &c : artfile_name)
	{
		if (c == '.')
			break;
		else
			dividefile_name.push_back(c);
	}
	dividefile_name = dividefile_name + "_divide.txt"; // �涨�˷ִ�֮�������ļ�



	art_file.readfile_to_vectorchar();
	data = art_file.vectorchar;
	art_len = data.size();
#ifdef GRPPRINT
	cout << "[���� " << artfile_name << " ��ȡ�ɹ������� " << art_len << " ��]" << endl;
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

	string word; // �����ÿ�ηִ�֮��õ��Ĵ���
	int dic_word_max(dic.get_word_max());
	for (int i(0); i < art_len; ++i)
	{
		int m(0);
		i + dic_word_max < art_len ? m = dic_word_max : m = art_len - i; // ��û���Խ�����

		for (; m > 0; --m)
		{
			word.clear(); // ����word�ĳ�ʼ��
			for (int j(0); j < m; ++j)
			{
				word.push_back(data[i + j]);
			} // ������Ϊm�Ĵ�ѹ��word�д���

			if (dic.find(word)) // ����ҵ�������ʣ�˵���ִʳɹ�
			{
				divide_result.push_back(word);
				i += m - 1;
				break;
			}
		}
	}

	// �ִʽ�����������Ҫд���ļ�
	divide_file.vectorstring = divide_result; // �������ͨ������copy���ﵽ����ʱ��Ч�ʵ�Ŀ��
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


