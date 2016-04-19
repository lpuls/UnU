#include "UnU.h"
#include "UnUWhile.h"
#include "UnUInteger.h"
#include "../UnUCompiler/Translation.h"

UnU::UnUWhile::UnUWhile()
{
}

UnU::UnUWhile::~UnUWhile()
{
}

int UnU::UnUWhile::run()
{
	// ��������
	auto condition = UnUCompiler::Translation::translation__(this->_condition);
	if (condition)
	{
		// �������
		bool result = ((UnUInteger*)condition)->getValue();
		condition->releaseSelf();
		while (result)
		{
			// ���д���
			auto temp = UnUCompiler::Translation::translation(this->_body);
			if (TRANSLATION_SUCCESS != temp)
				return temp;
			// ���»�ȡ����
			condition = UnUCompiler::Translation::translation__(this->_condition);
			if (condition)
			{
				result = ((UnUInteger*)condition)->getValue();
				condition->releaseSelf();
			}
			else
			{
				result = false;
				condition->releaseSelf();
				return INVALID_CONDITIONS;
			}
		}
		return TRANSLATION_SUCCESS;
	}
	return INVALID_CONDITIONS;
}
