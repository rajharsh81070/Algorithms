#include <bits/stdc++.h>
using namespace std;

// Recursive Approach.
int LPS(string S, int i, int j) {
	if(i==j)
		return 1;
	
	if(S[i]==S[j] && i+1==j)
		return 2;
	
	if(S[i]==S[j])
		return LPS(S, i+1, j-1)+2;
	
	return max(LPS(S, i+1, j), LPS(S, i, j-1));
}

// Bottom-Up Approach.
int LPS(string S, int n) {
	int dp[n][n];
	for(int i=0; i<n; i++)
		dp[i][i] = 1;

	for(int L=2; L<=n; L++) {
		for(int i=0; i<n-L+1; i++) {
			int j = i+L-1;
			if(S[i]==S[j] && i+1==j)
				dp[i][j] = 2;
			else if(S[i]==S[j])
				dp[i][j] = dp[i+1][j-1]+2;
			else 
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
		}
	}
	return dp[0][n-1];
}

int main() {

}