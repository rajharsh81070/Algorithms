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

ll dp[100005];

// Bottom Up
ll countNoOfSteps(ll no, ll l, ll m, ll n)
{
	if(no==1){
		dp[no] = 0;
		return dp[no];
	}
	if(dp[no])
		return dp[no];
	if(no&1){
		dp[no] = min(countNoOfSteps(no-1, l, m, n)+m, countNoOfSteps((no+1)/2, l, m, n)+l+n);
		return dp[no];
	}
	else{
		dp[no] = min(countNoOfSteps(no-1, l, m, n)+m, countNoOfSteps(no/2, l, m, n)+l);
		return dp[no];
	}
}

// Top Down
ll countNoOfSteps(ll no, ll l, ll m, ll n)
{
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2; i<=no; i++){
		if(i&1){
			dp[i] = min(dp[(i+1)/2]+l+n, dp[i-1]+m);
		}
		else{
			dp[i] = min(dp[i/2]+l, dp[i-1]+m);
		}
	}
	return dp[no];
}

int main(void)
{
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll no;
	get1(no);
	memset(dp, 0, sizeof(dp));
	ll l, m, n;
	get3(l, m, n);
	ll res = countNoOfSteps(no, l, m, n);
	pln(res);
}