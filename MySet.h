#pragma once

#include "ISet.h"

#include <iostream>

template <class T>
class SET
{
public:
	T data;
	SET *next;
};

template <class T> 
class MySet :public ISet<T>
{
private:
	int siz;
	SET<T> *start;
	SET<T> *find(T n);
public:
	MySet();
	MySet<T>(const MySet &b);
	MySet<T> &operator =(const MySet &b);
	~MySet();
	void clear();
	inline void del_begin();
	bool search(T n);
	void print();
	
	void add(const T& elem);
	void remove(const T& elem);
	bool contains(const T& elem) const;
	int size() const;
};

template <class T>
MySet<T>::MySet()
{
	start = NULL;
	siz = NULL;
}

template <class T>
MySet<T>::MySet(const MySet &b)
{
	this->start = NULL;
	this->siz = NULL;
	SET<T> *newel = b.start;
	for (int i = 0; i < b.size(); ++i)
	{
		add(newel->data);
		newel = newel->next;
	}
}

template <class T>
MySet<T> &MySet<T>::operator =(const MySet &b)
{
	if (this == &b)
		return *this;
	bool flag = true;
	if (this->siz != b.siz)
	{
		flag = false;
		clear();
		start = 0;
	}
	siz = b.siz;
	SET<T> *end = 0, *newel;
	SET<T> *br = start;
	SET<T> *br2 = b.start;
	if (flag)		// ðàçìåðíîñòè ðàâíû, ïðîñòî êîïèðóåì äàííûå.
	{
		while (br)
		{
			br->data = br2->data;
			br = br->next;
			br2 = br2->next;
		}
		return *this;
	}
	while (br2)		// ðàçìåðíîñòè íå ðàâíû
	{
		newel = new SET<T>;
		newel->next = 0;
		if (!start)
			start = newel;
		else
			end->next = newel;
		end = newel;
		newel->data = br2->data;
		br = br->next;
		br2 = br2->next;
	}
	return *this;
}

template <class T>
void MySet<T>::del_begin()
{
	if (!start)
		return;
	SET<T> *tmp = start;
	start = start->next;
	delete tmp;
	siz--;
}

template <class T>
void MySet<T>::clear()
{
	while (start)
		del_begin();
}

template <class T>
MySet<T>::~MySet()
{
	clear();
}

template <class T>
SET<T> *MySet<T>::find(T n)
{
	SET<T> *before_find;
	before_find = 0;
	SET<T> *after_find = start;
	while (after_find != 0)
	{
		if (n <= after_find->data)
			return before_find;
		else
		{
			before_find = after_find;
			after_find = after_find->next;
		}
	}
	return before_find;
}

template <class T>
void MySet<T>::print()
{
	SET<T> *prn = start;
	while (prn)
	{
		cout << prn->data << " ";
		prn = prn->next;
	}
	cout << "\n";
}

template <class T>
bool MySet<T>::search(T n)
{
	SET<T> *s = start;
	while (s)
	{
		if (s->data == n)
			return 1;
		s = s->next;
	}
	return 0;
}

template <class T>
void MySet<T>::add(const T& elem)
{
	if (!search(elem))
	{
		SET<T> *add = new SET<T>;
		add->data = elem;
		SET<T> *before_find = find(elem);
		if (before_find == 0)
		{
			add->next = start;
			start = add;
		}
		else
		{
			add->next = before_find->next;
			before_find->next = add;
		}
		++siz;
	}
}

template <class T>
void MySet<T>::remove(const T& elem)
{
	if (start == 0)
		return;
	if (search(elem) == 0)
		return;
	if (start->next == 0 && start->data == elem)
	{
		delete start;
		start = 0;
		siz--;
		return;
	}
	SET<T> *del;
	SET<T> *before_find = find(elem);
	if (before_find == 0)
	{
		if (start->data == elem)
			del_begin();
		return;
	}
	if (before_find->next->data == elem)
	{
		del = before_find->next;
		before_find->next = del->next;
		delete del;
		siz--;
	}
}

template <class T>
bool MySet<T>::contains(const T& elem) const
{
	SET<T> *con = start;
	while (con)
	{
		if (elem == con->data)
		return true;
		con=con->next;
	}
	return false;
}

template <class T>
int MySet<T>::size(void) const
{
	return siz;
}
