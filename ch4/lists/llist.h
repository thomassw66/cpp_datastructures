#include "link.h"
#include "list.h"

template <typename E> class LList : public List<E> {
private:
	Link<E> * head; 	// Pointer to list header
	Link<E> * tail;		// Pointer to last element
	Link<E> * curr;		// Access to current element
	int cnt; 		// Size of list

	// Constructor helper method
	void init() {
		curr = tail = head = new Link<E>;
		cnt = 0;
	}

	void removeAll() { // Return link nodes to free store
		while (head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public: 
	LList(int size=10) { init(); } // Constructor 
	~LList() { removeAll(); } 	// Destructor 
	void print() const;		// Print list contents
	void clear () {			// Clear list
		removeAll();
		init();
	}

	// Insert "it" at the current position
	void insert(const E& it) {
		curr->next = new Link<E>(it, curr->next->next);
		if (tail == curr) tail = curr->next; 
		cnt++;
	}

	// Append "it" to list
	void append(const E& it) {
		tail = tail->next = new Link<E>(it, NULL);
		cnt++;
	}

	// Remove and return the current element 
	E remove() {	
		// if (curr->next == NULL) return; // no element
		E it = curr->next->element; 	// remember value
		Link<E>* ltemp = curr->next;	// remember link node
		if (tail == curr->next) tail = curr; // reset tail
		curr->next = curr->next->next;	// remove from list
		delete ltemp; 			// reclaim memory
		cnt--;				// decrement count
		return it;
	}

	void moveToStart() {
		curr = head;
	}

	void moveToEnd() {
		curr = tail;
	}

	// Move curr one step left; no change if already at end
	void prev() {
		// if (curr == head) return;
		Link<E>* temp = head; 
		// scan the list until we find the previous element
		while (temp->next != curr) temp = temp->next;
		curr = temp;
	}
	
	// Move curr one step right; no change if already at end
	void next () { if (curr != tail) curr = curr->next; }

	// Return length
	int length() const { return cnt; } 

	// Return position of current element
	int currPos() const {
		Link<E> * temp = head;
		int i;
		for (i = 0; curr != temp; i++) 
			temp = temp->next;
		return i;
	}

	void moveToPos(int pos) {
		// if ( pos < 0 || pos > count ) {  return; }
		curr = head;
		for (int i = 0; i<pos; i++) 
			curr = curr->next;
	}

	const E& getValue() const { // Return current element
		//if (curr->next == NULL) { return; }
		return curr->next->element;
	}

};

