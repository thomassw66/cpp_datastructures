template <typename E> class Stack {
private:
	void operator =(const Stack&) {} // this protects assignment
	Stack(const Stack&) {} // protects copy constructor

public:
	Stack() {}
	virtual ~Stack() {}

	// reinitialize the stack. user is responsible for reclaiming the 
	// storage used by stack elements
	virtual void clear() = 0;

	// Push an element to the top of the stack
	// el: stack elements to be pushed
	virtual void push(const E& el) = 0;

	// Remove element from the top of stack
	// returns: the element removed from the top of the stack
	virtual E pop() = 0;

	// returns: a copy of the top element
	virtual const E& peek() const = 0;

	// returns: the number of elements
	virtual int length() const = 0;
};

