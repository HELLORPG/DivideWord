#include "File.h"


bool File::open_file(string filename, std::ios::openmode mode)
{
	name = filename;
	file.open(filename, mode);
	/*if(file.is_open())
		return true;
	else
		return false;*/
	return file.is_open();
}


void File::readfile_to_vectorstring()
{
#ifdef GRPPRINT
	cout << "[���ļ� " << name << " �ж�ȡ���ݣ�����vector<string>]" << endl;
#endif
	string read_data;
	do
	{
		file >> read_data;
		vectorstring.push_back(read_data);
	} while (!file.eof());

	return;
}

void File::readfile_to_vectorchar()
{
#ifdef GRPPRINT
	cout << "[���ļ� " << name << " �ж�ȡ���ݣ�����vector<char>]" << endl;
#endif
	char read_data;

	do
	{
		file >> read_data;
		vectorchar.push_back(read_data);
	} while (!file.eof());

	return;
}

void File::writefile_vectorstring()
{
#ifdef GRPPRINT
	cout << "[��vector<string>д���ļ� " << name << " ]" << endl;
#endif
	for (const auto &word : vectorstring)
		file << word << " ";

	return;
}


void File::print_vectorstring()
{
	cout << "<DEBUG> [PRINT vector<string>]" << endl;
	for (const auto &x : vectorstring)
		cout << x << endl;

	return;
}

void File::print_vectorchar()
{
	cout << "<DEBUG> [PRINT vector<char>]" << endl;
	for (const auto &x : vectorchar)
		cout << x ;
	cout << endl;

	return;
}

File::~File()
{
	file.close();
}



