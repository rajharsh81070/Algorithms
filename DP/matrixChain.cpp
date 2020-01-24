#include <bits/stdc++.h>
using namespace std;

// Recursive approach. Complexity : Exponential.
// A simple solution is to place parenthesis at all possible places, calculate 
// the cost for each placement and return the minimum value. In a chain of matrices 
// of size n, we can place the first set of parenthesis in n-1 ways.
int matrixChainOrder(int p[], int i, int j) {
	if(i==j)
		return 0;
	int Ans = INT_MAX;
	int cnt;
	for(int k=i; k<j; k++) {
		cnt = matrixChainOrder(p, i, k) + matrixChainOrder(p, k+1, j) + p[i-1]*p[k]*p[j];
		if(cnt < Ans)
			Ans = cnt;
	}
	return Ans;
} 

// Top Down approach.
// lookup table to store the solution to already computed
// sub-problems
int lookup[MAX][MAX];
int matrixChainOrder(int p[], int i, int j) {
	if(i==j)
		return 0;
	int Ans = INT_MAX;
	int cnt;
	if(lookup[i][j]==0) {
		for(int k=i; k<j; k++) {
			cnt = matrixChainOrder(p, i, k) + matrixChainOrder(p, k+1, j) + p[i-1]*p[k]*p[j];
			if(cnt < Ans)
				Ans = cnt;
		}
		lookup[i][j] = Ans;
	}
	return lookup[i][j];
} 

// Bottom-Up approach.
int matrixChainOrder(int p[], int N) {
	int dp[N][N];
	for(int i=0; i<N; i++)
		dp[i][i] = 0;

	for(int L=2; L<N; L++) {
		for(int i=1; i<N-L+1; i++) {
			int j = i+L-1;
			dp[i][j] = INT_MAX;
			for(int k=i; k<j; k++) {
				int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < dp[i][j])
					dp[i][j] = q;
			}
		}
	}
	return dp[1][N-1];
}

int main() {
	matrixChainOrder(p, 1, n - 1); 
}