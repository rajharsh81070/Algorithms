#include <bits/stdc++.h>
using namespace std;

// Recursive approach. Time Complexity : exponential
int MaximumSumIncreasingSubsequence(vector<int> arr, int prev, int pos) {
	if(arr.size()==pos)
		return 0;
	int inc = 0, exc = 0;
	if(arr[pos] > prev)
		inc = arr[pos] + MaximumSumIncreasingSubsequence(arr, arr[pos], pos+1);

	exc = MaximumSumIncreasingSubsequence(arr, prev, pos+1);
	return max(inc, exc);
}

// Bottom-Up approach. Time Complexity : O(n^2).
int MaximumSumIncreasingSubsequence(vector<int> A) {
	int N = A.size();
	vector<int> dp(N, 0);
	dp[0] = A[0];
	for(int i=1; i<N; i++) {
		for(int j=0; j<i; j++) {
			if(A[i] > A[j])
				dp[i] = max(dp[i], dp[j]+A[i]);
		}
	}
	for(int i=0; i<N; i++) 
		cout << dp[i] << " ";
	cout << '\n';
	int Ans = *max_element(dp.begin(), dp.end());
	return Ans;
}

int main() {
	vector<int> arr{1, 101, 2, 3, 100, 4, 5};
	cout << MaximumSumIncreasingSubsequence(arr);
	return 0;
}