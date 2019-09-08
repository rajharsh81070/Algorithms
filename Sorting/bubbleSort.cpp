#include <bits/stdc++.h>
using namespace std;

// It is a comparison based sorting algo. 
// Time Complexity - O(n2).
// Space Complexity - O(1).

void bubbleSort(vector <int> &A) {
	int N = A.size();
	for(int i=N-1; i>=0; i--) {
		for(int j=0; j<i; j++) {
			if(A[j]>A[j+1])
				swap(A[j], A[j+1]);
		}
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
	bubbleSort(A);
	for(int i=0; i<N; i++)
		cout << A[i] << " ";
	return 0;
}