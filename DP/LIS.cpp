#include <bits/stdc++.h>
using namespace std;

// Simple recursive implementation of the LIS problem.
int _LIS(vector<int> &A, int N, int *Ans) {
	if(N==1)
		return 1;
	int res, max_end = 1;
	for(int i=1; i<N; i++) {
		res = _LIS(A, N, Ans);
		if(A[i-1]<A[N-1] && res+1 > max_end) 
			max_end = res + 1;
	}
	if(max_end > *Ans) 
		*Ans = max_end;

	return max_end;
}

int LIS_Sol(vector<int> &A, int N) {
	int Ans = 1;
	_LIS(A, N, &Ans);
	return Ans;
}

// O(N^2) complexity.
int LIS_Sol(vector<int> &A) {
	int N = A.size();
	vector<int> LIS(N, 1);
	for(int i=1; i<N; i++) {
		for(int j=0; j<i; j++) {
			if(A[i] > A[j])
				LIS[i] = max(LIS[i], LIS[j]+1);
		}
	}
	int Ans = *max_element(LIS.begin(), LIS.end());
	return Ans;
}

int main() {

}