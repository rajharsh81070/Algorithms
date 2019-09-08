#include <bits/stdc++.h>
using namespace std;

// It is a comparison based sorting algo. 
// Time Complexity - O(n2).
// Space Complexity - O(1).

void insertionSort(vector <int> &A) {
	int N = A.size();
	for(int i=1; i<N; i++) {
		int tmp = A[i];
		int j = i; 
		while(j>=1 && A[j-1]>tmp) {
			A[j] = A[j-1];
			j--;
		}
		A[j] = tmp;
	}
}

int main()
{
	// Enter the size of the array.
	int N;
	cin >> N;
	vector <int> A(N);
	// Enter array elements.
	for(int i=0; i<N; i++) 
		cin >> A[i] ;
	insertionSort(A);
	for(int i=0; i<N; i++)
		cout << A[i] << " ";
	return 0;
}