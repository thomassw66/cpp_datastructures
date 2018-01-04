#include <iostream>
// #include "alist.h"
#include "llist.h"

using namespace std;

bool find(List<int>& L, int K) 
{
	int it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it) return true; // cuz we found K
	}
	return false; // K was not found
}

int main() 
{	
	LList<int> list(100);
	for (int i = 0; i < 100; i++) {
		list.append(i);
	}

	for (list.moveToStart(); list.currPos() < list.length(); list.next()) {
		cout << list.getValue() << endl;
	}
	return 1;
}

