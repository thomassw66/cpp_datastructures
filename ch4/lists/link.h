// Singly linked list node
template <typename E> class Link {
public:
	E element; 	// value for this node
	Link* next;  	// pointer to the next node in the list
	// Constructors
	Link(const E& elemval, Link* nextVal = NULL) 
		{ element = elemval; next = nextVal; }
	Link(Link* nextVal = NULL)
		{ next = nextVal; } 
};

