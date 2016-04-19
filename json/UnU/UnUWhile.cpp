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
	// 运算条件
	auto condition = UnUCompiler::Translation::translation__(this->_condition);
	if (condition)
	{
		// 检测条件
		bool result = ((UnUInteger*)condition)->getValue();
		condition->releaseSelf();
		while (result)
		{
			// 运行代码
			auto temp = UnUCompiler::Translation::translation(this->_body);
			if (TRANSLATION_SUCCESS != temp)
				return temp;
			// 重新获取条件
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
