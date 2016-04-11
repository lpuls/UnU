/*
* 描述：AST数值结果
* 作者：xp
* 日期：---
*/
#ifndef __AST_VALUE_NODE__
#define __AST_VALUE_NODE__

#include "ASTExpNode.h"
#include "../../Tools.h"

namespace UnUCompiler
{
	template<class T>
	class ASTValueNode : public ASTExpNode 
	{
		friend class ASTNodeCreater;
	public:
		/*
		* 功能：析构函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		~ASTValueNode();

	protected:
		/*
		* 功能：用来记录数值
		* 类型：T
		* 描述：无
		*/
		T _value;

		/*
		* 功能：记录本数值的类型
		* 类型：std::string
		* 描述：无
		*/
		std::string _type;

		/*
		* 功能：构造函数
		* 参数：无
		* 返回：无
		* 描述：无
		*/
		ASTValueNode();

	public:
		/*
		* 功能：获取数值
		* 参数：无
		* 返回：T
		* 描述：无
		*/
		T getValue();

		/*
		* 功能：设置数值
		* 参数：T, 要设置的数值
		* 返回：无
		* 描述：无
		*/
		void setValue(T value);

		/*
		* 功能：获取数值
		* 参数：无
		* 返回：T
		* 描述：无
		*/
		std::string getType();

		/*
		* 功能：设置数值
		* 参数：T, 要设置的数值
		* 返回：无
		* 描述：无
		*/
		void setType(std::string type);
	};

	template<class T>
	inline ASTValueNode<T>::~ASTValueNode()
	{
	}

	template<class T>
	inline ASTValueNode<T>::ASTValueNode()
	{
		this->_type = "";
	}

	template<class T>
	inline T ASTValueNode<T>::getValue()
	{
		return this->_value;
	}

	template<class T>
	inline void ASTValueNode<T>::setValue(T value)
	{
		this->_value = value;
	}

	template<class T>
	inline std::string ASTValueNode<T>::getType()
	{
		return this->_type;
	}

	template<class T>
	inline void ASTValueNode<T>::setType(std::string type)
	{
		this->_type = type;
	}

}

#endif
