#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int countNoOfSteps(int n, int arr[], int m)
{
	if(m<0)
		return 0;
	if(!m)
		return 1;

	int ans = 0;

	for(int i=0; i<n; i++)
		ans += countNoOfSteps(n, arr, m-arr[i]);

	return ans;
}

// Top Down Approach
int countNoOfStepsTd(int n, int arr[], int m, int dp[])
{
	for(int i=0; i<100; i++)
		dp[i] = 0;

	if(m<0)
		return 0;
	if(!m){
		dp[m] = 1;
		return 1;
	}
	int ans = 0;
	if(dp[m]!=0)
		return dp[m];
	else{
		for(int i=0; i<n; i++){
			dp[m] = countNoOfStepsTd(n, arr, m-arr[i], dp);
			ans += dp[m];
		}
	}
	return ans;
}

// Bottom Up for arr[i] is 1, 2, 3
int countNoOfStepsBup(int n, int arr[], int m)
{
	int dp[100];
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i=4; i<100; i++)
		dp[i] += (dp[i-1]+dp[i-2]+dp[i-3]);

	return dp[m];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	// int res = countNoOfSteps(n, arr, m);
	int dp[100];
	int res = countNoOfStepsTd(n, arr, m, dp);
	cout << res;
}