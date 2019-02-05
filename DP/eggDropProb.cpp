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

void tick(){
	static clock_t oldt;
	clock_t newt=clock();
	double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;
	oldt = newt;
	cout << '\n' << "The execution time is : " << diff << '\n';
}

const ll egg = 1001, totFloors = 1001;

ll dp[totFloors+1][egg+1];

// Top Down DP
ll minimumNoOfSteps(ll floors, ll eggs)
{
	if(((floors<=totFloors&&(eggs==0||floors==0)&&eggs<=egg)))
		return dp[floors][eggs] = 0;
	else if(eggs==0||floors==0)
		return 0;
	
	if(floors<=totFloors && eggs==1)
		return dp[floors][eggs] = floors;
	else if(eggs==1)
		return floors;

	if((floors<=totFloors && eggs<=egg) && dp[floors][eggs]!=0)
		return dp[floors][eggs];

	ll tmpAns, ans = INT_MAX;

	for(int floor = 1; floor<= floors; floor++){
		// There are twp cases : 1. When the egg breaks then the function would be f(floor-1, eggs-1). 2. When it doesn't break then the function would be f(floors-floor, eggs).
		tmpAns = max(minimumNoOfSteps(floor-1, eggs-1), minimumNoOfSteps(floors-floor, eggs));
		ans = min(ans, tmpAns+1);
	}
	// watch(ans);
	if(floors<=totFloors && eggs<=egg)
		dp[floors][eggs] = ans;

	return ans;
}

// Bottom UP

/*void minimumNoOfStepsB_Up()
{
	for(int i=0; i<=floors; i++)
		dp[0][i] = 0;

	for(int i=0; i<=eggs; i++)
		dp[i][0] = 0;

	for(int i=1; i<=floors; i++)
		dp[1][i] = i;

	for(int i=1; i<=eggs; i++)
		dp[i][1] = 1;

	for(int i=1; i<=eggs; i++){
		for(int j=1; j<=floors; j++){
			if(i==1||j==1)
				continue;
			int ans = INT_MAX, tmpAns;
			for(int k=1; k<=j; k++){
				tmpAns = max(dp[i-1][k-1], dp[i][j-k]);
				ans = min(tmpAns+1, ans);
			}
			dp[i][j] = ans;
		}
	}
}*/

int main(void)
{
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	get1(t);
	memset(dp, 0, sizeof(dp));
	// minimumNoOfStepsB_Up();
	// int ans = minimumNoOfSteps(MAX_FLOORS-1, 2);
	w(t){
		ll b, m;
		get2(m, b);
		pln(minimumNoOfSteps(m, b));
	}
	// tick();
}