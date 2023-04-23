#ifndef FF_QUEUE_H
#define FF_QUEUE_H

#include <stdint.h>


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
	T rotate(T item);
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
T CircleQueue<T>::rotate(T item) {
	T element = 0;
	if (curr_sz == max_sz) {
		element = pop();
	}
	push(item);
	return element;
}

template <typename T>
void CircleQueue<T>::shiftForward() {
	for (int i = 0; i < curr_sz - 1; ++i) {
		elements[i] = elements[i+1];
	}
	elements[curr_sz - 1] = T();
}

template<typename T> inline const T& 
CircleQueue<T>::front() const { return curr_sz ? elements[0] : T(); }
template<typename T> inline const T& 
CircleQueue<T>::back()  const { return curr_sz ? elements[curr_sz-1] : T(); }


#endif // FF_QUEUE_H
