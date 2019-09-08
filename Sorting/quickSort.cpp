#include <bits/stdc++.h>
using namespace std;

// Quick Sort is an example of divide and conquer strategy. 
// Time Complexity - O(nlogn) in average case and O(n2) in worst case.
// Space Complexity - O(1).

int partition(vector<int>&A, int s, int e) {
	int i = s-1, j = s;
	// Setting pivot value as the index value.
	int pivotValue = A[e];
	for(; j<e ; j++) {
		if(A[j]<=pivotValue) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[e]);
	return i+1;
}

void quickSort(vector<int>&A, int s, int e) {
	if(s < e) {
		int pivotIndex = partition(A, s, e);
		quickSort(A, s, pivotIndex-1);
		quickSort(A, pivotIndex+1, e);
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
	quickSort(A, 0, N-1);
	for(int i=0; i<N; i++)
		cout << A[i] << " ";
	return 0;
}