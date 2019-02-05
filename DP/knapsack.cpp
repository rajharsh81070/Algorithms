#include <bits/stdc++.h> 
using namespace std;
 
#define mod 1000000007
#define inf 1e9
typedef long long ll;
typedef long double ld;
typedef unsigned long long int ul;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<float> vf;
typedef vector <ld> vd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
#define vec(x) vector<x >
#define z size()
#define get1(x) cin>>x
#define get2(x, y) cin>>x>>y
#define get3(x, y, z) cin>>x>>y>>z
#define put(x) cout<<x
#define pls(x) cout<<x<<' '
#define pln(x) cout<<x<<"\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=b-1;i>=a;i--)
#define vput(a) f(i,0,a.z) pls(a[i]); nl;
#define vget(v) f(i,0,v.z) get1(v[i]);
#define vsort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define vuni(v) v.erase(unique(all(v)),v.end())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define total(v) accumulate(all(v),ll(0))
#define watch(x) cout << (#x) << " is " << (x) << endl

#define bs(v,x) binary_search(all(v),x)
#define lb(v,x) lower_bound(all(v),x)-v.begin()
#define ub(v,x) upper_bound(all(v),x)-v.begin()
#define parray(a,n) f(i,0,n) pls(a[i]); nl;
#define ppair(x) cout<<x.first<<' '<<x.second<<"\n";
#define vp(x,y) vector<pair<x,y> >
#define p(x,y) pair<x,y >
#define endl '\n'
#define nl cout<<'\n';
#define w(a) while(a--)
#define wh(a) while(a)
 
ll maxi=LLONG_MAX;
ll mini=LLONG_MIN;
 
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
 
#define con continue
#define bk break
#define ret return
#define setpr fixed<<setprecision
#define gl(a) getline(cin,a)
#define ppb pop_back
#define pq priority_queue

int dp[100][100];

// Recursive Approach
int calTotalProfits(int noOfItems, int profits[], int weights[], int totalWeight)
{
	if(noOfItems==0||totalWeight==0)
		return 0;

	int inc = 0, exc = 0;

	if(weights[noOfItems-1]<=totalWeight)
		inc = profits[noOfItems-1] + calTotalProfits(noOfItems-1, profits, weights, totalWeight-weights[noOfItems-1]);

	exc = calTotalProfits(noOfItems-1, profits, weights, totalWeight);

	// pls(inc);pln(exc);

	return max(inc, exc);
}

// Top Down
int calTotalProfits_T_d(int noOfItems, int profits[], int weights[], int totalWeight)
{
	// memset(dp, 0, sizeof(dp));

	if(noOfItems==0||totalWeight==0){
		dp[noOfItems][totalWeight] = 0;
		return 0;
	}

	if(dp[noOfItems][totalWeight]!=0)
		return dp[noOfItems][totalWeight];

	int inc = 0, exc = 0;

	if(weights[noOfItems-1]<=totalWeight)
		inc = profits[noOfItems-1] + calTotalProfits_T_d(noOfItems-1, profits, weights, totalWeight-weights[noOfItems-1]);

	exc = calTotalProfits_T_d(noOfItems-1, profits, weights, totalWeight);

	// pls(inc);pln(exc);
	dp[noOfItems][totalWeight] = max(inc, exc);

	return max(inc, exc);
}

//Bottom Up Dp
int calTotalProfits_B_up(int noOfItems, int profits[], int weights[], int totalWeight)
{
	int bup[100][100] = {0};
	f(i, 0, noOfItems+1){
		f(j, 0, totalWeight+1){
			if(i==0 || j==0)
				bup[i][j] = 0;
			else{
				int inc = 0, exc = 0;
				if(weights[i-1]<=j)
					inc = profits[i-1] + bup[i-1][j-weights[i-1]];

				exc = bup[i-1][j];

				bup[i][j] = max(inc, exc);
			}
			// watch(bup[i][j]);
		}
	}
	/*f(i, 0, noOfItems+1){
		f(j, 0, totalWeight+1)
			pls(bup[i][j]);
		nl;
	}*/
	return bup[noOfItems][totalWeight];
}

int main(void)
{
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int noOfItems, totalWeight;

	cin >> noOfItems >> totalWeight;

	int profits[noOfItems];
	int weights[noOfItems];

	for(int i=0; i<noOfItems; i++) cin >> weights[i];

	for(int i=0; i<noOfItems; i++) cin >> profits[i];

	// int totalProfit = calTotalProfits(noOfItems, profits, weights, totalWeight);

	// cout << totalProfit << endl;

	int td[100][100] = {0};
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++)
			dp[i][j] = 0;
	}

	int topDown = calTotalProfits_T_d(noOfItems, profits, weights, totalWeight);

	f(i, 0, noOfItems+1){
		f(j, 0, totalWeight+1)
			pls(dp[i][j]);
		nl;
	}
	cout << topDown << endl;

	// cout << calTotalProfits_B_up(noOfItems, profits, weights, totalWeight) << endl;
}