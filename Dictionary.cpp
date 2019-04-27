#include "Dictionary.h"


Dictionary::Dictionary(string dic_name)
{
	if (dic_file.open_file(dic_name, std::ios::in) == 0)
	{
		cout << "<WRONG> [�ʵ��ļ���ʧ��]" << endl;
		exit(-1);
	}
	name = dic_name;

	// ֮�����ļ��򿪳ɹ�������

	dic_file.readfile_to_vectorstring(); // ���ݶ���file�ı�����

	//֮����Ҫ��vector�е����ݶ�Ӧ��hash��
	// transform(dic_file.vectorstring.begin(), dic_file.vectorstring.end(), hash_dic);
	for (const auto &word : dic_file.vectorstring)
	{
		hash_dic.insert(word);
	}

	dic_size = hash_dic.size();
	// cout << (hash_dic.find("������") != hash_dic.end())<< endl;
	// ͨ������ע�͵��������������ɵ�hash����ʹ��
#ifdef GRPPRINT
	cout << "[�ʵ� " << name << " �����ɹ������� "<< dic_size << " ����]" << endl;
#endif
	return;
}
