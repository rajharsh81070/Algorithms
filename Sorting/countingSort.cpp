#include <bits/stdc++.h>
using namespace std;

// Counting Sort is an example of linear sorting algorithm. 
// Time Complexity - O(n+k) where k is the maximum element in the range. 
// Space Complexity - O(n).

void countingSort(vector<int>&A) {
	int mx = *max_element(A.begin(), A.end());
	vector <int> freq(mx+1, 0);
	int N = A.size();
	for(int i=0; i<N; i++)
		freq[A[i]]++;
	for(int i=1; i<=mx; i++) {
		freq[i] += freq[i-1];
	}
	vector <int> sorted(N);
	for(int i=0; i<N; i++) {
		sorted[freq[A[i]]-1] = A[i];
		freq[A[i]]--;
	}
	for(int i=0; i<N; i++)
		cout << sorted[i] << ' ';
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
	countingSort(A);
	// for(int i=0; i<N; i++)
	// 	cout << A[i] << " ";
	return 0;
}