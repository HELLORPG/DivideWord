#include "Define.h"
#include "File.h"
#include "Dictionary.h"
#include "Article.h"
#include "ArticleSet.h"


int main()
{
	/*File test_file;
	test_file.open_file("´Êµä.txt", std::ios::in);
	test_file.readfile_to_vectorstring();
	test_file.print_vectorstring();*/

	Dictionary test_dic("´Êµä.txt");
	/*Article test_art("2002020500435.txt");
	test_art.divide(test_dic);
	test_art.print_divide();*/
	ArticleSet test_set;
	test_set.insert_article("2002020500435.txt");
	test_set.insert_article("2002020500437.txt");
	test_set.divide_all_article(test_dic);

	return 0;
}
