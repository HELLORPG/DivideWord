#pragma once
#include "Article.h"



class ArticleSet
{
private:
	vector<Article> art_set; // 存储了所有的文章结构

public:
	void insert_article(string article_name);
	void divide_all_article(const Dictionary& dic);
};