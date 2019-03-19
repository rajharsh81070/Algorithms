#include <bits/stdc++.h>
using namespace std;

// Range Max Query.
void update(int i, int val, int N){
	while(i<=N){
		BIT[i]=max(BIT[i], val);
		i+=(i&(-i));
	}
}

int query(int i){
	int ans = 0;
	while(i>0){
		ans=max(ans, BIT[i]);
		i-=(i&(-i));
	}
	return ans;
}

int main(){
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
		int idx;
		cin >> idx;
		cout << query(idx) << endl;
	}
}