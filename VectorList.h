#ifndef FF_VECTORLIST_H
#define FF_VECTORLIST_H

#include <stdint.h>

/*************************
 * Exception Declaration
 **************************/

class vl_null_reference
{
public:
	vl_null_reference(const char *message) : _message(message) {}
	const char *what() const { return _message; }

private:
	const char *_message;
};

/*************************
 * Class Declaration
 **************************/

template <typename T>
class VectorList
{
public:
	/* List constructor/destructor */
	VectorList(int size = 10);
	~VectorList();

	/* Fundamental List implementation */
	void push(T item);
	T pop();

	void insert(int index, T item);
	bool erase(int index);
	void clear();

	void resize(int newSize);
	void shrink();

	inline int size() const { return sz; }
	inline bool isEmpty() const { return sz == 0; }

	/* Reference returning operators */
	inline const T &first() const;
	inline const T &last() const;

	inline const T &operator[](int index) const;
	inline T &operator[](int index);

private:
	inline bool full() const { return sz == capacity; }
	void expand();
	int capacity;
	int sz;
	T *elements;
};

/*************************
 * Method Implementations
 **************************/

template <typename T>
VectorList<T>::VectorList(int size)
{
	capacity = size;
	sz = 0;
	elements = new T[capacity];
}

template <typename T>
VectorList<T>::~VectorList()
{
	delete[] elements;
}

template <typename T>
void VectorList<T>::push(T item)
{
	if (full())
	{
		expand();
	}
	elements[sz++] = item;
}

template <typename T>
T VectorList<T>::pop()
{
	if (isEmpty())
	{
		throw vl_null_reference("VectorList empty; call to pop() failed.");
	}
	T item = elements[--sz];
	return item;
}

template <typename T>
void VectorList<T>::insert(int index, T item)
{
	if (index < 0 || index > sz)
	{
		throw vl_null_reference("Index out of bounds.");
	}
	if (full())
	{
		expand();
	}
	for (int i = sz; i > index; --i)
	{
		elements[i] = elements[i - 1];
	}
	elements[index] = item;
	++sz;
}

template <typename T>
bool VectorList<T>::erase(int index)
{
	if (index < 0 || index >= sz)
	{
		return false;
	}
	for (int i = index; i < sz - 1; ++i)
	{
		elements[i] = elements[i + 1];
	}
	--sz;
	return true;
}

template <typename T>
void VectorList<T>::clear()
{
	sz = 0;
}

template <typename T>
void VectorList<T>::resize(int newSize)
{
	if (newSize < sz)
	{
		throw vl_null_reference("New size is less than the current size.");
	}
	T *newElements = new T[newSize];
	for (int i = 0; i < sz; ++i)
	{
		newElements[i] = elements[i];
	}
	delete[] elements;
	elements = newElements;
	capacity = newSize;
}

template <typename T>
void VectorList<T>::shrink()
{
	resize(sz);
}

template <typename T>
inline const T &VectorList<T>::first() const
{
	if (isEmpty())
	{
		throw vl_null_reference("VectorList empty; call to first() failed.");
	}
	return elements[0];
}

template <typename T>
inline const T &VectorList<T>::last() const
{
	if (isEmpty())
	{
		throw vl_null_reference("VectorList empty; call to last() failed.");
	}
	return elements[sz - 1];
}

template <typename T>
inline const T &VectorList<T>::operator[](int index) const
{
	if (index < 0 || index >= sz)
	{
		throw vl_null_reference("Index out of bounds.");
	}
	return elements[index];
}

template <typename T>
inline T &VectorList<T>::operator[](int index)
{
	if (index < 0 || index >= sz)
	{
		throw vl_null_reference("Index out of bounds.");
	}
	return elements[index];
}

template <typename T>
void VectorList<T>::expand()
{
	int newCapacity = capacity * 2;
	T *newElements = new T[newCapacity];
	for (int i = 0; i < sz; ++i)
	{
		newElements[i] = elements[i];
	}
	delete[] elements;
	elements = newElements;
	capacity = newCapacity;
}

#endif // FF_VECTORLIST_H