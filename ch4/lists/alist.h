
#include "list.h"

template <typename E> // Array based list implementation
class AList : public List<E> {
private:
	int maxSize; 	// Maximum size of the list
	int listSize; 	// Number of items now
	int curr; 	// Position of the current element
	E* listArray; 	// Array holding list elements

public:
	AList(int size=10) // Constructor 
	{
		maxSize = size;
		listSize = curr = 0;
		listArray = new E[maxSize];
	}

	~AList() { delete [] listArray; } // Destructor

	void clear () 
	{		// Reinitialize list
		delete [] listArray; // remove old array
		listSize = curr = 0; // reset the size and position
		listArray = new E[maxSize]; // Recreate the array
	}

	void append(const E& it) // Appends "it"
	{
		// Assert(listSize < maxSize, "List capacity exceeded");
	       	listArray[listSize++] = it;
	}
	
	void insert(const E& it) 
	{
		// Assert(listSize < maxSize, "list size exceeded");
		for (int i = listSize; i>curr; i--)  // shift all the elements up 
			listArray[i] = listArray[i-1];
		listArray[curr] = it;
		listSize++;
	}	

	// Remove and return the current element;
	E remove() 
	{
		// Assert((curr > 0) && (curr < listSize), "No element");
		E it = listArray[curr];
		for (int i = curr; i < listSize - 1; i++) { // shift elements in array down
			listArray[i] = listArray[i+1];
		}
		listSize--; //decrement size
		return it;
	}

	void moveToStart() { curr = 0; } // Reset position
	void moveToEnd() { curr = listSize; }  // set at end
	void prev() { if (curr != 0) curr--; } // Back up
	void next() { if (curr < listSize) curr++; } // Next

	// Return list size;
	int length() const { return listSize; }

	// Return current position 
	int currPos() const { return curr; } 

	// Set current list position to "pos"
	void moveToPos(int pos) 
	{
		// Assert ((pos >= 0) && (pos<=listSize), "Pos out of range");
		curr = pos;
	}

	E& getValue() const 
	{ // return current element 
		// Assert((curr>=0) && (curr<listSize), "No current element");
		return listArray[curr];
	}
};
