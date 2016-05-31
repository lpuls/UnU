/*
* 描述：工具类，一些相关的宏
* 作者：xp
* 日期：2016-2-6
*/
#ifndef __TOOLS__
#define __TOOLS__

namespace XpLib
{
#define __Debug__

#define DEFINE_PRIVATE(type, varName, funName) \
private: type varName; \
public: type get##funName () { return this->varName; } \
public: void set##funName (type value) { this->varName = value; }

#define DEFINE_PRIVATE_READ_ONLY(type, varName, funName) \
private: type varName; \
public: type get##funName () { return this->varName; } \

#define DEFINE_PROTECTED(type, varName, funName) \
protected: type varName; \
public: type get##funName () { return this->varName; } \
public: void set##funName (type value) { this->varName = value; }

#define DEFINE_PROTECTED_READ_ONLY(type, varName, funName) \
protected: type varName; \
public: type get##funName () { return this->varName; } \

#define SAFE_DELETE(var) \
if (nullptr != var) {delete(var);} var = nullptr;

}

#endif
