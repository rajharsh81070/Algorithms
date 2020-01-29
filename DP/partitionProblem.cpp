#include <bits/stdc++.h>
using namespace std;

// Recursive Approach. Time Complexity:- O(2^n).
bool isSubsetSum(int arr[], int n, int sum) {
	if(sum==0)
		return true;
	if(n==0&&sum!=0)
		return false;
	if(arr[n-1]>sum)
		return isSubsetSum(arr, n-1, sum);

	return isSubsetSum(arr, n-1, sum-arr[n-1]) || isSubsetSum(arr, n-1, sum);
}

// Bottom-Up approach. Time Complexity:- O(n*sum).
bool isSubsetSum(int arr[], int n, int sum) {
	bool dp[sum/2 + 1][n+1];
	for(int i=0; i<=sum/2; i++)
		dp[i][0] = true;
	for(int i=1; i<=n; i++)
		dp[0][i] = false;
	for(int i=1; i<=sum/2; i++) {
		for(int j=1; j<=n; j++) {
			dp[i][j] = dp[i][j-1];
			if(i>=arr[j-1])
				dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
		}
	}
	return dp[sum/2][n];
}

int main() {

}