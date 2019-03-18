#include <bits/stdc++.h>
using namespace std;

// Range sum Query Code.

int arr[MAXN];
int BIT[MAXN] = {0};

void update(int i, int inc, int N){
	while(i <= N){
		BIT[i]+=inc;
		i+=(i&(-i));
	}
}

// Sum till the ith index - log(n).
int query(int i){
	int sum = 0;
	while(i > 0){
		sum+=BIT[i];
		i-=(i&(-i));
	}
	return sum;
}

int main(void){
	int N;
	cin >> N;
	for(int i=1; i<N; i++){
		cin >> arr[i];
		// Builds the BIT.
		update(i, arr[i], N);
	}
	// Query.
	int q;
	cin >> q;
	for(int i=1; i<=q; i++){
		int l, r;
		cin >> l >> r;
		cout << query(r)-query(l-1) << endl;
	}
}