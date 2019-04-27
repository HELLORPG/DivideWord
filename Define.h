#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include <set> // 引入集合，作为词典的存储方式，因为词典是不可能重复的，且要求一定的搜索效率，所以个人认为set是最好的组织方式
#include <functional>
// #include <hash_set>
#include <unordered_set>


#define GRPPRINT // 用于提示每个步骤的进行状况

using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::string;

using std::sort;
using std::max;
using std::min;

using std::fstream;

using std::set;
using std::hash;
using std::transform;
// using std::hash_set;
using std::unordered_set;