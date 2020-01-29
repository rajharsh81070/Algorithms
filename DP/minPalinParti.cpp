#include <bits/stdc++.h>
using namespace std;

// Recursive Approach. Time Complexity:- Exponential.
int minPalinParti(string S, int i, int j) {
	if(i==j)
		return 0;
	if(isPalindrome(S, i, j))
		return 0;
	int Ans = INT_MAX;
	for(int k=i; k<j; k++) {
		int cnt = minPalinParti(S, i, k) + 1 + minPalinParti(S, k+1, j);
		Ans = min(Ans, cnt);
	}
	return Ans;
}

// Bottom-Up Approach. Time Complexity:- O(n^3).
int minPalinParti(string S) {
	int N = S.length();
	int dp[N][N];
	bool P[N][N];
	for(int i=0; i<N; i++) {
		dp[i][i] = 0;
		P[i][i] = true;
	}
	for(int L=2; L<=N; L++) {
		for(int i=0; i<N-L+1; i++) {
			int j = i+L-1;
			if(L==2)
				P[i][j] = (S[i]==S[j]);
			else
				P[i][j] = (S[i]==S[j]) && P[i+1][j-1];
			if(P[i][j])
				dp[i][j] = 0;
			else {
				dp[i][j] = INT_MAX;
				for(int k=i; k<j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k]+1+dp[k+1][j]);
				}
			}
		}
	}
	return dp[0][N-1];
}

int main() {

}