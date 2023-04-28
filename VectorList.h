#ifndef FF_VECTORLIST_H
#define FF_VECTORLIST_H

#include <stdint.h>

/*************************
 * Exception Declaration
**************************/

class vl_null_reference {
public:
	vl_null_reference(const char* message) : _message(message) {}
	const char* what() const { return _message; }
private:
	const char* _message;
};

template<typename T>
class VectorList 
{
public:
	/* List constructor/destructor */
	VectorList(int size);
	~VectorList();

	/* Fundamental List implementation */
	void push(T item);
	T pop();

    void insert(T);
    bool delete(int);
    void clear();

    void resize(int);
    void shrink();

    inline int size() { return sz; }
    inline bool isEmpty() { return sz == 0; }

	/* Reference returning operators */
	inline const T& first() const;
	inline const T& last()  const;

	inline const T& operator[](int) const;

private:
    inline bool full() { return sz == capacity; }
	int capacity;
	int sz;
    T* elements;

};
    template <typename T>
    void VectorList<T>::insert();
    bool delete(int);
    void clear();

    void resize(int);
    void shrink();


#endif // FF_VECTORLIST_H