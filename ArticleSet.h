#pragma once
#include "Article.h"



class ArticleSet
{
private:
	vector<Article> art_set; // �洢�����е����½ṹ

public:
	void insert_article(string article_name);
	void divide_all_article(const Dictionary& dic);
};