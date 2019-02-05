#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl

// This code helps to find the minimum value to travel from (0, 0) to (x, y) by travelling one step right or one step down.

int dp[1001][1001];
int row, col;

// Bottom Up DP
void minCost()
{
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i==0||j==0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			// watch(dp[i][j]);
			// watch(cost[i][j]);
		}
	}
	// watch(row);
}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	memset(dp, 0, sizeof(dp));
	cin >> row >> col;
	numOfWays();
	/*for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << dp[i][j] << " ";
		cout << '\n';
	}*/
	int x, y;
	cin >> x >> y;
	cout << dp[x-1][y-1];
}