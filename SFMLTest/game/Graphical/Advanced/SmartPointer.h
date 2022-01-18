#pragma once
#include <algorithm>

template<class ClassType>
class SmartPtr {
	bool setted = false;
	ClassType* ptr;
	int arrayCount;
public:
	SmartPtr();
	~SmartPtr();
	SmartPtr(const SmartPtr<ClassType>& source);
	SmartPtr<ClassType> operator=(SmartPtr<ClassType>& source);

	void set(ClassType* heapPtr, int arrayCount);
	void replace();
	void deconstruct();

	ClassType* getPtr();
};



template<class ClassType>
inline SmartPtr<ClassType>::SmartPtr()
{
}

template<class ClassType>
inline SmartPtr<ClassType>::~SmartPtr()
{
	deconstruct();
}

//Copying a Smart Pointer will create another new heap allocation with the same data as the old one. This is to prevent having two smart pointers pointing to the same location and creating an double dellocation error.
template<class ClassType>
inline SmartPtr<ClassType>::SmartPtr(const SmartPtr<ClassType>& source)
{
	this->set(new ClassType[source.arrayCount], source.arrayCount);
	std::memcpy(this->ptr, source.ptr, sizeof(ClassType) * source.arrayCount);
}

template<class ClassType>
inline SmartPtr<ClassType> SmartPtr<ClassType>::operator=(SmartPtr<ClassType>& source)
{
	return SmartPtr<ClassType>(&this);
}

template<class ClassType>
inline void SmartPtr<ClassType>::set(ClassType* heapPtr, int arrayCount)
{
	deconstruct();
	this->arrayCount = arrayCount;
	this->ptr = heapPtr;
	setted = true;
}

template<class ClassType>
inline void SmartPtr<ClassType>::replace()
{
}

template<class ClassType>
inline void SmartPtr<ClassType>::deconstruct()
{
	if (setted) {
		if (ptr) delete[] ptr;
	}
}

template<class ClassType>
inline ClassType* SmartPtr<ClassType>::getPtr()
{
	return ptr;
}
