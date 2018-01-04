#include <iostream>
#include "linked_stack.h"
#include "array_stack.h"

int main() {

	ArrayStack<int> astack(200);
	LinkedStack<int> lstack;

	for (int i=0; i < 200; i++) {
		astack.push(i);
		lstack.push(i);
	}
	while(astack.length() != 0) {
		std::cout << astack.pop() << std::endl;
	}
	while(lstack.length() != 0) {
		std::cout << lstack.pop() << std::endl;
	}
	return 0;
}
