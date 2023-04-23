#ifndef FF_QUEUE_H
#define FF_QUEUE_H

#include <stdint.h>

/*************************
 * Exception Declaration
**************************/

class cq_null_reference {
public:
	cq_null_reference(const char* message) : _message(message) {}
	const char* what() const { return _message; }
private:
	const char* _message;
};

/*************************
 * Class Declaration
**************************/

template<typename T>
class CircleQueue 
{
public:
	/* Queue constructor/destructor */
	CircleQueue(int size);
	~CircleQueue();

	/* Fundamental Queue implementation */
	void push(T item);
	T pop();
	bool rotate(T item);
	bool rotate(T item, T& drop);
	inline bool full() { return curr_sz == max_sz; }
	int max_sz;
	int curr_sz;

	/* Reference returning operators */
	inline const T& front() const;
	inline const T& back()  const;
	inline const T& operator[](int) const;

private:
	void shiftForward();
	T* elements;
};

/*************************
 * Method Implementations
**************************/

template<typename T>
CircleQueue<T>::CircleQueue(int size) {
	max_sz = size;
	curr_sz = 0;
	elements = new T[size];
}

template<typename T>
CircleQueue<T>::~CircleQueue() {
    delete[] elements;
}

template<typename T>
T CircleQueue<T>::pop() {
	if (curr_sz == 0) return 0;
    T element = elements[0];
	shiftForward();
	--curr_sz;
	return element;
}

template<typename T>
void CircleQueue<T>::push(T item) {
	if (curr_sz < max_sz) {
		elements[curr_sz++] = item;
		return;
	}
	shiftForward();
}

template <typename T>
bool CircleQueue<T>::rotate(T item) {
	return rotate(item, T());
}

template <typename T>
bool CircleQueue<T>::rotate(T item, T& drop) {
	bool dropped = false;
	if (curr_sz == max_sz) {
		drop = pop();
		dropped = true;
	}
	push(item);
	return dropped;
}


template <typename T>
void CircleQueue<T>::shiftForward() {
	for (int i = 0; i < curr_sz - 1; ++i) {
		elements[i] = elements[i+1];
	}
	elements[curr_sz - 1] = T();
}

template<typename T> inline const T& CircleQueue<T>::front() const { 
	if (curr_sz == 0) 
		throw cq_null_reference("CircleQueue empty; call to front() failed.");
	else if (curr_sz < 0) 
		throw cq_null_reference("Current size is less than zero. That should never happen.");
	return elements[0];
}

template<typename T> inline const T& CircleQueue<T>::back() const { 
	if (curr_sz == 0) 
		throw cq_null_reference("CircleQueue empty; call to back() failed.");
	else if (curr_sz < 0) 
		throw cq_null_reference("Current size is less than zero. That should never happen.");
	return elements[curr_sz - 1];
}

template<typename T> inline const T& CircleQueue<T>::operator[](int i) const {
	if (i > curr_sz || i < 0) 
		throw cq_null_reference("Index out of bounds."); 
	return elements[i]; 
}


#endif // FF_QUEUE_H
