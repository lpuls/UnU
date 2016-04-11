/*
* ������AST��ֵ���
* ���ߣ�xp
* ���ڣ�---
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
		* ���ܣ���������
		* ��������
		* ���أ���
		* ��������
		*/
		~ASTValueNode();

	protected:
		/*
		* ���ܣ�������¼��ֵ
		* ���ͣ�T
		* ��������
		*/
		T _value;

		/*
		* ���ܣ���¼����ֵ������
		* ���ͣ�std::string
		* ��������
		*/
		std::string _type;

		/*
		* ���ܣ����캯��
		* ��������
		* ���أ���
		* ��������
		*/
		ASTValueNode();

	public:
		/*
		* ���ܣ���ȡ��ֵ
		* ��������
		* ���أ�T
		* ��������
		*/
		T getValue();

		/*
		* ���ܣ�������ֵ
		* ������T, Ҫ���õ���ֵ
		* ���أ���
		* ��������
		*/
		void setValue(T value);

		/*
		* ���ܣ���ȡ��ֵ
		* ��������
		* ���أ�T
		* ��������
		*/
		std::string getType();

		/*
		* ���ܣ�������ֵ
		* ������T, Ҫ���õ���ֵ
		* ���أ���
		* ��������
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
