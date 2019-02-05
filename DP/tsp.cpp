#include <bits/stdc++.h> 
using namespace std;

void tick(){
	static clock_t oldt;
	clock_t newt=clock();
	double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;
	oldt = newt;
	cout << '\n' << "The execution time is : " << diff << '\n';
}

const int n=4;

int dist[10][10] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};

int visited_all = (1<<n)-1;

int dp[1<<n][n];

int tsp(int mask, int pos)
{
	if(mask==visited_all){
		return dp[mask][pos] = dist[pos][0];
	}
	
	if(dp[mask][n] != -1)
		return dp[mask][pos];
	
	int ans = INT_MAX;
	for(int city=0; city<n; city++){
		if(!(mask&(1<<city))){
			// cout << city << endl;
			int tmpAns = dist[pos][city] + tsp(mask|(1<<city), city);
			ans = min(ans, tmpAns);
		} 
		// cout << city << endl;
	}
	
	return dp[mask][pos] = ans;
}

int main(){
	// your code goes here
	memset(dp, -1, sizeof(dp));
	cout << tsp(1, 0) << endl;
	tick();
	return 0;
}