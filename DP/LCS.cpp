#include <bits/stdc++.h>
using namespace std;

// Recursive Approach - Exponential complexity
int LCS_length(string X, string Y, int N, int M) {
	if(M==0 || N==0)
		return 0;
	if(X[N-1]==Y[M-1])
		return 1+LCS_length(X, Y, N-1, M-1);
	return max(LCS_length(X, Y, N-1, M), LCS_length(X, Y, N, M-1));
}

// Bottom-Up Approach - O(N*M) complexity
int LCS_length(string X, string Y, int N, int M) {
	int LCS[N+1][M+1];
	for(int i=0; i<=N; i++) {
		for(int j=0; j<=M; j++) {
			if(i==0||j==0)
				LCS[i][j] = 0;
			else {
				if(X[i-1]==Y[j-1])
					LCS[i][j] = 1+LCS[i-1][j-1];
				else 
					LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
			}
		}
	}

	/*----------------------------------------------*/
	// For Printing LCS string.
	int i = N, j = M;
	string LCS_string = "";

	while(i>0 && j>0) {
		if(X[i-1]==Y[j-1]) {
			i--;
			j--;
			LCS_string += X[i];
		}
		else if(LCS[i-1][j] > LCS[i][j-1])
			i--;
		else
			j--;
	}

	reverse(LCS_string.begin(), LCS_string.end());
	/*----------------------------------------------*/

	return LCS[N][M];
}

int main() {

}