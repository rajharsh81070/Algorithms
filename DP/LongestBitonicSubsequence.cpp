#include <bits/stdc++.h>
using namespace std;

// Bottom-Up approach. Time Complexity : O(n^2).
int LongestBitonicSubsequence(vector<int> A) {
	int N = A.size();
	vector<int> LIS(N, 1), LDS(N, 1);
	for(int i=1; i<N; i++) {
		for(int j=0; j<i; j++) {
			if(A[i] > A[j])
				LIS[i] = max(LIS[i], 1+LIS[j]);
		}
	}

	for(int i=N-2; i>=0; i--) {
		for(int j=N-1; j>i; j--) {
			if(A[i] > A[j])
				LDS[i] = max(LDS[i], LDS[j]+1);
		}
	}
	int Ans = 0;
	for(int i=0; i<N; i++) {
		Ans = max(Ans, LDS[i]+LIS[i]-1);
	}
	return Ans;
}

int main() {
	vector<int> arr{1, 11, 2, 10, 4, 5, 2, 1};
	cout << LongestBitonicSubsequence(arr);
	return 0;
}