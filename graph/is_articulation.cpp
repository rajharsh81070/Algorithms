#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[10001];
vector<bool> visited(10001);
vector<int> t_in, low;
int timer;

void dfs(int u, int p = -1) {
	visited[u] = true;
	int children = 0;
	t_in[u]=low[u]=timer++;
	for(int v:adjList[u]){
		if(v==p) continue;
		if(visited[v]){
			low[u] = min(low[u], t_in[v]);
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], t_in[v]);
			if(low[v] > t_in[u] && p!=-1)
				cout << "This is an articulation point" << u << '\n';
			children++;	
		}
	}
	if(p==-1 && children>1)
		cout << "This is an articulation point" << u << '\n';
}

void find_points(){
	timer = 0;
	t_in.assign(n, -1);
	low.assign(n, -1);
	visited.assign(n, false);
	for(int node=0; node<n; node++){
		if(!visited[node])
			dfs(node);
	}
}