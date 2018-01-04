#include "link.h"
#include "stack.h"

template <typename E> class LinkedStack: public Stack<E>
{
private:
	Link<E> *top; // points to the top of the stack
	int size;

public:
	LinkedStack(int size =default_size)
	{
		top = NULL;
		size = 0;
	}

	~LinkedStack() 
	{
		clear();
	}

	void clear() 
	{
		while(top != NULL) {
			Link<E>* temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}

	void push(const E& el) 
	{
		top = new Link<E>(el, top);
		size++;
	}

	E pop() 
	{
		// Assert(top != NULL, "Stack is empty!");
		E el = top->element;
		Link<E>* temp = top;
		top = top->next;
		delete temp;
		size--;
		return el;
	}

	const E& peek() const
	{
		// Assert(top != NULL, "Stack is empty");
		return top->element;
	}

	int length() const 
	{ 
		return size;
	}
};
