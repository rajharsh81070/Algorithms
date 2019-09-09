#include <bits/stdc++.h>
using namespace std;

// Merge Sort is an example of in-place sorting algorithm. 
// Time Complexity - O(nlogn)
// Space Complexity - O(1).

void heapify(vector <int> &A, int N, int i) {
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<N && A[l]>A[largest])
		largest = l;
	if(r<N && A[r]>A[largest])
		largest = r;
	if(largest!=i) {
		swap(A[i], A[largest]);
		heapify(A, N, largest);
	} 
}

void heapSort(vector <int> &A, int N) {
	for(int i=N/2 - 1; i>=0; i--)
		heapify(A, N, i);
	for(int i=N-1; i>=0; i--) {
		swap(A[0], A[i]);
		heapify(A, i, 0);
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
	heapSort(A, N);
	for(int i=0; i<N; i++)
		cout << A[i] << " ";
	return 0;
}