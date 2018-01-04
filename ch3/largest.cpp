
#include<iostream>

// Return the largest value in an array of size n
int largest(int A[], int n) {
	int currLarge = 0;
	for (int i = 1; i < n; i++) {
		if (A[currLarge] < A[i])
			currLarge = i;
	}
	return currLarge;
}

void loops(int n) {
	int sum = 0;
	for (int k = 1; k <= n; k *= 2) { // happens log n times 
		for (int i = 0; i < k; i++) { // happens k times 
			sum ++;
		}
	}
	std::cout << sum << std::endl;
}

int main()
{
	int A[] = {1, 2, 3, 4, 5, 9};
	std::cout << largest(A, 6) << std::endl;
	
	std::cout << "Testing loops" << std::endl;
	std::cout << 8 << " ";
	loops(8);
	std::cout << 16 << " ";
	loops(16);
	std::cout << 32 << " ";
	loops(32);
	std::cout << 128 << " ";
	loops(128);
	return 1;
}
