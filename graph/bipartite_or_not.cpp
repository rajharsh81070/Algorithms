#include <bits/stdc++.h>
using namespace std;

vector <int> adjList[101];
int V;

bool is_bipartite(){
	vector <int> color(V+1, -1);
	queue <int> q;
	for(int node=1; node<=V; node++){
		if(color[node]==-1){
			q.push(node);
			color[node] = 0;
			while(!q.empty()){
				int neighbour = q.front();
				q.pop();
				for(int v:adjList[neighbour]){
					if(color[v]==-1){
						color[v] = color[neighbour] ^ 1;
						q.push(v);
					}
					else if(color[neighbour]==color[v]){
						// cout << neighbour << " " << v << ' ' << node;
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main(){
	cin >> V;
	adjList[1].push_back(2);
	adjList[2].push_back(1);
	adjList[3].push_back(1);
	adjList[1].push_back(3);
	adjList[2].push_back(4);
	adjList[4].push_back(2);
	adjList[3].push_back(4);
	adjList[4].push_back(3);
	adjList[4].push_back(1);
	adjList[1].push_back(4);
	cout << (is_bipartite() ? "YES" : "NO") << "\n";
}