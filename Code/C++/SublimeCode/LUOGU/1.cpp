#include <iostream>
#include <exception>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

template<class T> 
class linearList
{
public:
	virtual ~linearList(){};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& get(int theIndex) const = 0;
	virtual int indexOf(const T& Element) const = 0;
	virtual void erase(int theIndex) const = 0;
	virtual void insert(int theIndex, const T& Element) const = 0;
	virtual void outPut(ostream& out) const = 0;
};


template<class T>
class arrayList : public linearList<T>
{
public:
	
	arrayList(int initalcapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() {delete [] element;}

	bool empty() const {return listSize == 0;}
	int size() const {return listSize;}
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void outPut(ostream& out) const;
	int capacity() const {return arrayLength;}
	void changeLength1D(T*&, int, int);
protected:
	void checkIndex(int theIndex) const;
	T* element;
	int arrayLength;
	int listSize;
};

template<class T>
arrayList<T>::arrayList(int initalcapacity)
{
	if(initalcapacity < 1)
	{
		ostringstream s;
		s << "Inital capacity = " << initalcapacity << " Must be > 0";
		//throw illegalArgumentException(s.str());
		throw 0;
	}
	arrayLength = initalcapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
	if(theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw 0;
	}
}


template<class T>
void arrayList<T>::changeLength1D(T*& a, int oldLength, int newLength)
{
	if(newLength < 0)
	{
		cout << "new length must be > 0";
		throw 0;
	}
	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete [] a;
	a = temp;
}



template<class T>
T& arrayList<T>:: get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
	//find路碌禄脴碌眉麓煤脝梅露脭脧贸
	int theIndex = (int)(find(element, element+listSize, theElement) - element);
	if(theIndex == listSize) return -1; //录麓脦麓脮脪碌陆
	else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if(theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw 0;
	}
	if(listSize == arrayLength) 
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	copy_backward(element + theIndex, element + listSize,
										 element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}


// template<class T>
// void arrayList<T>::outPut(cout -> out) const
// {
// 	//把线性表插入输出流
// 	copy(element, element + listSize, ostream_iterator<T>(cout, " "));
// }
//重载 <<
template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
	x.outPut(out);
	return out;
}

int main(){    
	arrayList<int> arr;
	
	
	
	return 0;
}
