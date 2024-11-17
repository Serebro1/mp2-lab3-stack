#pragma once
#include <iostream>
#define MAX_STACK_SIZE 1000

using namespace std;
template <class T>
class TStack {

	int MaxSize, TopNum;
	T* pStack;
public:
	TStack(int s = MAX_STACK_SIZE);
	TStack(const TStack& st);
	~TStack();
	int GetSize() { return MaxSize; }
	int GetTopNum() { return TopNum; }
	TStack& operator=(const TStack& st);

	bool isEmpty() const { return TopNum == -1; }
	bool isFull() const { return TopNum == MaxSize - 1; }

	bool operator==(const TStack& st) const;
	bool operator!=(const TStack& st) const;

	T Pop();
	void Push(const T& val);
	T Top() const { return pStack[TopNum]; }

	void Clear() { TopNum = -1; }
	friend istream& operator>>(istream& in, TStack& st)
	{
		for (int i = 0; i < st.TopNum + 1; i++)
			in >> st.pStack[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TStack& st)
	{
		for (int i = 0; i < st.TopNum + 1; i++)
			out << st.pStack[i] << ' ';
		return out;   
	}
};

template<class T>
TStack<T>::TStack(int _MaxSize)
{
	if (_MaxSize < 0)
		throw out_of_range("Invalid stack size");
	MaxSize = _MaxSize;
	TopNum = -1;
	pStack = new T[MaxSize];

}

template<class T>
TStack<T>::TStack(const TStack& st)
{
	MaxSize = st.MaxSize;
	TopNum = st.TopNum;
	pStack = new T[MaxSize];
	for (int i = 0; i < TopNum + 1; i++)
		pStack[i] = st.pStack[i];
}

template<class T>
TStack<T>::~TStack()
{
	delete[]pStack;
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack& st)
{
	if (this == &st) return *this;
	if (MaxSize != st.MaxSize) {
		delete[]pStack;
		pStack = new T[st.MaxSize];
		MaxSize = st.MaxSize;
		
	}
	TopNum = st.TopNum;
	for (int i = 0; i < TopNum + 1; i++)
		pStack[i] = st.pStack[i];
	return *this;
}

template<class T>
bool TStack<T>::operator==(const TStack& st) const
{
	if (TopNum != st.TopNum || MaxSize != st.MaxSize) return false;
	for (int i = 0; i < TopNum + 1; i++)
	{
		if (pStack[i] != st.pStack[i])
			return false;
	}

	return true;
}

template<class T>
bool TStack<T>::operator!=(const TStack& st) const
{
	return !(*this == st);
}

template<class T>
T TStack<T>::Pop()
{
	if (this->isEmpty()) throw - 1;
	T tmp = pStack[TopNum];
	TopNum--;
	return tmp;
}

template<class T>
void TStack<T>::Push(const T& val)
{
	if (this->isFull()) throw - 1;
	pStack[++TopNum] = val;
}

