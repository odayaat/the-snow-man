#pragma once
#pragma once
#include "Const.h"
#include "GameObject.h"
template<class Type>
class MyFactory 
{
public:

	using pFnc = std::unique_ptr<Type>(*)();


	static std::unique_ptr<Type> createObject(const char& name);
	static bool registerit(const char name, pFnc f);

private:

	static auto& getHashMap();

};
template<class Type>
auto& MyFactory<Type>::getHashMap() 
//=================getHashMap============
//The function returns hash map like Singelton(only one instance to map)
{
	static std::map<char, pFnc> map;
	return map;
}

template<class Type>
std::unique_ptr<Type> MyFactory<Type>::createObject(const char& name) 
//=================createObject============
//The function gets chat(name) and return the correct Object
{
	auto it = MyFactory::getHashMap().find(name);
	if (it != MyFactory::getHashMap().end())
		return it->second();
	return nullptr;
}

template<class Type>
bool MyFactory<Type>::registerit(const char name, pFnc f) 
//========registerit=============
{
	MyFactory::getHashMap().emplace(name, f);
	return true;
}