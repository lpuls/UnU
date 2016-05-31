/*
* ����������ת����
* ���ߣ�xp
* ���ڣ�2016-2-6
*/
#ifndef __TYPE_CONVERSION__
#define __TYPE_CONVERSION__

#include <iostream>

#include "../Tools.hpp"


namespace XpLib
{
	class TypeConversion
	{
		friend class Toolsets;
	public:
	private:
		static std::string intToStr(int value);


		static int strToInt(std::string value);

		static std::string doubleToStr(double value);

		/*
		* ���ܣ���stringת��Ϊdouble
		* ������Ҫת�����ַ���
		* ���أ�ת���ĸ�����
		* ��������̬����
		*/
		static double strToDouble(std::string value);

		/*
		* ���ܣ�������ֵת��Ϊ�ַ���
		* ������Ҫת���Ĳ���ֵ
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
		static std::string boolToStr(bool value);

		/*
		* ���ܣ���charתΪstring
		* ������Ҫת�����ַ�
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
		static std::string charToStr(char value);

	};
}


#endif
