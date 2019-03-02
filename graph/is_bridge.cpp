#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[10001];
vecotr<bool> visited(10001);
vector<int> low, t_in;
int timer;

void dfs(int u, int p = -1){
	visited[u] = true;
	low[u]=t_in[u]=timer++;
	for(int v:adjList[u]){
		if(v==p) continue;
		if(visited[v]){
			low[u] = min(t_in[v], low[u]);
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], t_in[v]);
			if (low[v] > t_in[u])
				cout << "There is a bridge between between" << u << "and" << v << '\n' ;
		}
	}
}

void find_bridges(int n){
	timer = 0;
	visited.assign(n, false);
	t_in.assign(n, -1);
	low.assign(n, -1);
	for(int node=0; node<n; node++){
		if(!visited[node])
			dfs(node);
	}
}

int main(void){
	find_bridges(n);
}