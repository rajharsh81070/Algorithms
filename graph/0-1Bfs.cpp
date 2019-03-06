#include <bits/stdc++.h>
using namepace std;

const int INF = 100000000;

void 0-1Bfs(){
	vector <int> d(n, INF);
	dequeue<int> q;
	d[src] = 0;
	q.push_front(src);
	while(!q.empty()){
		int node = q.front();
		q.pop_front();
		for(int child: adj[node]){
			int u = child.first;
			int cost = child.second;
			if(d[node]+cost < d[u]){
				d[u] = d[node]+cost;
				if(w==1)
					q.push_back(u);
				else
					q.push_front(u);
			}
		}
	}
}

int main(){

}