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
	cout << "[从文件 " << name << " 中读取数据，存入vector<string>]" << endl;
#endif
	string read_data;
	do
	{
		file >> read_data;
		vectorstring.push_back(read_data);
	} while (!file.eof());

	return;
}

void File::print_vectorstring()
{
	cout << "<DEBUG> [PRINT vector<string>]" << endl;
	for (const auto &x : vectorstring)
		cout << x << endl;

	return;
}
