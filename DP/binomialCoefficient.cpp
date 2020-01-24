#include <bits/stdc++.h>
using namespace std;

// Recursive approach.
int nCr(int n, int r) {
	if(r==0 || n==r)
		return 1;

	return nCr(n-1, r-1) + nCr(n-1, r);
}

// Top-Down approach.
// Time & Space Complexity :- O(n*r)
int nCr(int n, int r) {
	int dp[n+1][r+1];
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=min(i, r); j++) {
			if(j==0 || i==j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	return dp[n][r];
}

// Top-Down approach.
// Time Complexity :- O(n*r)
// Space Complexity :- O(r)
int nCr(int n, int r) {
	int dp[r+1];
	dp[0] = 1;
	for(int i=0; i<=n; i++) {
		for(int j=min(i, r); j>0; j--) {
			dp[j] += dp[j-1] 
		}
	}
	return dp[r];
}

int main() {

}