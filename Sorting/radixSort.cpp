#include <bits/stdc++.h>
using namespace std;

// Radix Sort is an example of linear sorting algorithm. We use counting sort as the stable sort.  
// Time Complexity - O(d*(n+b)) where b is the base of the input elements which is to be sorted and d is the maximum number of digits.   
// Space Complexity - O(n+b).

void radixSort(vector<int>&A, int exp) {
	vector <int> freq(10, 0);
	int N = A.size();
	for(int i=0; i<N; i++)
		freq[(A[i]/exp)%10]++;
	for(int i=1; i<10; i++) {
		freq[i] += freq[i-1];
	}
	vector <int> sorted(N);
	for(int i=N-1; i>=0; i--) {
		sorted[freq[(A[i]/exp)%10]-1] = A[i];
		freq[(A[i]/exp)%10]--;
	}
	A = sorted;
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
	int mx = *max_element(A.begin(), A.end());
	for(int exp = 1; mx/exp > 0; exp*=10)
		radixSort(A, exp);
	for(int i=0; i<N; i++)
		cout << A[i] << " ";
	return 0;
}