#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl

// This code helps to find the minimum value to travel from (0, 0) to (x, y) by travelling one step right or one step down.

int dp[1001][1001];
int row, col;
int cost[1001][1001];

// Bottom Up DP
void minCost()
{
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i==0&&j==0)
				dp[i][j] = cost[0][0];
			else if(i==0)
				dp[i][j] = cost[0][j] + dp[0][j-1];
			else if(j==0)
				dp[i][j] = cost[i][0] + dp[i-1][0];
			else
				dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);
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
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cin >> cost[i][j];
	}
	minCost();
	/*for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << dp[i][j] << " ";
		cout << '\n';
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << cost[i][j] << " ";
		cout << '\n';
	}*/
	int x, y;
	cin >> x >> y;
	cout << dp[x-1][y-1];
}