#include "stack.h"

// an array based stack implementation
template <typename E> class ArrayStack: public Stack<E> {
private:
	int max_size; // max size of the array
	int top; // index of the top element
	E *list_array; // array for holding stack elements

public:
	// constructor
	ArrayStack(int size =default_size) 
	{
		max_size = size;
		top = 0;
		list_array = new E[size];
	} 

	// destructor
	~ArrayStack() 
	{ 
		delete [] list_array; 
	} 

	void clear()
       	{
		// all we have to do to reinitialize is set the top of the
		// stack to 0
		top = 0; 	
	}

	void push(const E& el) 
	{
	//	Assert(top != max_size, "Stack is full");
		list_array[top++] = el;
	}

	E pop() 
	{
	///	Assert(top != 0, "Stack is empty");
		return list_array[--top];
	}

	const E& peek() const 
	{
	//	Assert(top != 0, "Stack is empty");
		return list_array[top - 1];
	}

	int length() const
	{
		return top;
	}
};
