/*
* ����������ת����
* ���ߣ�xp
* ���ڣ�2016-2-6
*/
#ifndef __TYPE_CONVERSION__
#define __TYPE_CONVERSION__

#include <iostream>

#include "../Tools.h"


namespace XpLib
{
	/*
	* ���ܣ�����ת���࣬�������͵�ת��
	* ��������ȫ˽�У����Թ��߼�����п���
	*/
	class TypeConversion
	{
		// ����Toolsets�����߼����࿪��
		friend class Toolsets;
	public:
	private:
		/*
		* ���ܣ���intת��Ϊstring
		* ������Ҫת��������
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
		static std::string intToStr(int value);

		/*
		* ���ܣ���stringת��Ϊint
		* ������Ҫת�����ַ���
		* ���أ�ת��������
		* ��������̬����
		*/
		static int strToInt(std::string value);

		/*
		* ���ܣ���doubleת��Ϊstring
		* ������Ҫת���ĸ�����
		* ���أ�ת�����ַ���
		* ��������̬����
		*/
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
