#include <string>
#include <fstream>
#include <iostream>

#include "FileReader.h"

std::vector<std::string> XpLib::FileReader::reader(std::string file)
{
	const int length = 500000;
	std::vector<std::string> lines;
	std::ifstream fin(file);
	// 检测文件是否成功打开
	if (!fin)
	{
		std::cout << file << " cann't open" << std::endl;
	}
	else  // 文件打开成功后，读取每一行
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
