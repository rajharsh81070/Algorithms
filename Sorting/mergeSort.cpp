#include <bits/stdc++.h>
using namespace std;

// Merge Sort is an example of divide and conquer strategy. 
// Time Complexity - O(nlogn)
// Space Complexity - O(n).

void merge(vector<int>&A, int s, int mid, int e) {
	int n1 = mid-s+1;
	int n2 = e-mid;
	vector <int> left(n1), right(n2);
	for(int i=0; i<n1; i++) 
		left[i] = A[s+i];
	for(int i=0; i<n2; i++) 
		right[i] = A[mid+i+1];
	int i = 0, j = 0, k = s;
	while(i<n1&&j<n2) {
		if(left[i] > right[j]) {
			A[k++] = right[j++];
		}
		else {
			A[k++] = left[i++];
		}
	}
	while(i<n1) {
		A[k++] = left[i++];
	}
	while(j<n2) {
		A[k++] = right[j++];
	}
}

void mergeSort(vector<int>&A, int s, int e) {
	if(s < e) {
		int mid = s + (e - s) / 2;
		mergeSort(A, s, mid);
		mergeSort(A, mid+1, e);
		merge(A, s, mid, e);
	}
}

void mergeSortWithTheHelpOfSTL(vector<int>&A, int s, int e) {
	if(s < e) {
		int mid = s + (e - s) / 2;
		mergeSort(A, s, mid);
		mergeSort(A, mid+1, e);
		// Inplace_merge - Merges two consecutive sorted ranges [first, middle) and [middle, last) into one sorted range [first, last).
		inplace_merge(A, s, mid, e);
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
	mergeSort(A, 0, N-1);
	mergeSortWithTheHelpOfSTL(A, 0, N-1);
	for(int i=0; i<N; i++)
		cout << A[i] << " ";
	return 0;
}