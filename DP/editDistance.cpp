#include <bits/stdc++.h>
using namespace std;

// Recursive Approach- O(3^N) complexity.
int edit_string(string X, string Y, int N, int M) {
	if(N==0)
		return M;
	if(M==0)
		return N;
	if(X[N-1]==Y[M-1])	
		return edit_string(X, Y, N-1, M-1);
	return 1 + min(edit_string(X, Y, N-1, M-1), min(edit_string(X, Y, N-1, M), edit_string(X, Y, N, M-1)));
}

// Bottom-Up Dp - O(N*M) complexity.
int edit_string(string X, string Y, int N, int M) {
	int dp[N+1][M+1];
	for(int i=0; i<=N; i++) {
		for(int j=0; j<=M; j++) {
			if(i==0)
				dp[i][j] = j;
			else if(j==0)
				dp[i][j] = i;
			else if(X[i-1]==Y[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
		}
	}
	return dp[N][M];
}

int main() {

}