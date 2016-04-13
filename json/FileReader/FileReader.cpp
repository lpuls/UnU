#include <string>
#include <fstream>
#include <iostream>

#include "FileReader.h"

std::vector<std::string> XpLib::FileReader::reader(std::string file)
{
	const int length = 500000;
	std::vector<std::string> lines;
	std::ifstream fin(file);
	// ����ļ��Ƿ�ɹ���
	if (!fin)
	{
		std::cout << file << " cann't open" << std::endl;
	}
	else  // �ļ��򿪳ɹ��󣬶�ȡÿһ��
	{
		char line[length];
		while (!fin.eof())
		{
			fin.getline(line, length);
			lines.push_back(line);
		}
	}
	fin.close();
	return lines;
}
