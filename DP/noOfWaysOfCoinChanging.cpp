#include <bits/stdc++.h>
using namespace std;

// Recursive Approach - O(2^N) complexity.
int noOfWaysOfCoinChanging(int coins[], int N, int tot) {
	if(tot==0)
		return 1;
	if(tot<0)
		return 0;
	if(N==0 && tot>0)
		return 0;
	return noOfWaysOfCoinChanging(coins, N-1, tot) + noOfWaysOfCoinChanging(coins, N, tot-coins[N-1]);
}

// Bottom-Up Approach - O(N*M) complexity.
int noOfWaysOfCoinChanging(int coins[], int N, int tot) {
	int dp[N][tot+1];
	for(int i=0; i<N; i++)
		dp[i][0] = 1;
	for(int i=0; i<N; i++) {
		for(int j=1; j<=tot; j++) {
			// Count of solutions including coins[i]. 
			int x = (j-coins[i] >= 0) ? dp[i][j-coins[i]] : 0;
			// Count of solutions excluding coins[i].
			int y = (i >= 1) ? dp[i-1][j] : 0;
			dp[i][j] = x+y;
		}
	}
	return dp[N-1][tot];
}

// Bottom-Up Approach - O(N*M) time complexity & O(tot) space complexity.
int noOfWaysOfCoinChanging(int coins[], int N, int tot) {
	int dp[tot+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0; i<N; i++) {
		for(int j=1; j<=tot; j++) {
			if(j>=coins[i])
				dp[j] += dp[j-coins[i]];
		}
	}
	return dp[N];
}

int main() {

}