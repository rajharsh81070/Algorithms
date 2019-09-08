#include <bits/stdc++.h>
using namespace std;

// It is a in-place sorting algo. 
// Time Complexity - O(n2).
// Space Complexity - O(1).

void selectionSort(vector <int> &A) {
	int N = A.size();
	for(int i=0; i<N; i++) {
		int tmp = i;
		for(int j=i+1; j<N; j++) {
			if(A[j] < A[tmp])
				tmp = j;
		}
		swap(A[tmp], A[i]);
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
	selectionSort(A);
	for(int i=0; i<N; i++)
		cout << A[i] << " ";
	return 0;
}