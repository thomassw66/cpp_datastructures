#include<iostream>

using namespace std;

// Return the value of the position of an element in the sortet array "A" 
// of size "n" with the value "K" . if "K" is not in "A" then return the value 
// "n"
int binary(int A[], int n, int K) {
	int l = -1;
	int r = n; // l and r are beyond array bounds
	while (l+1 != r) { // Stop when l and r have met 
		int i = (l+r)/2; // Check middle of remaining array
		if (K < A[i]) r = i; // its in the left half 
		if (K == A[i]) return i; // found it !
		if (K > A[i]) l = i; // in the right half
	}
	return n; // because the search value is not in "A"
}

int main() 
{
	int n = 1000;
	int * A = new int [n];
	for (int i = 0; i < n; i++) A[i] = i;
	cout << binary(A, n, 69) << endl;
	return 1;
}

