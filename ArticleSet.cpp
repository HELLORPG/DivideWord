#include "ArticleSet.h"

void ArticleSet::insert_article(string article_name)
{
	Article new_art(article_name);
	art_set.push_back(new_art);
	return;
}


void ArticleSet::divide_all_article(const Dictionary& dic)
{
	for (int i(0); i < art_set.size(); ++i)
		art_set[i].divide(dic);

	return;
}
