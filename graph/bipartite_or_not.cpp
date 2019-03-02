#include <bits/stdc++.h>
using namespace std;

vector <int> adjList[101];
int V;

bool is_bipartite(){
	vector <int> side(V+1, -1);
	bool visited[V+1] = {false};
	queue <int> q;
	bool check_bipartite = true;
	for(int node=1; node<=V; node++){
		if(side[node]==-1){
			q.push(node);
			side[node] = 0;
			while(!q.empty()){
				int neighbour = q.front();
				q.pop();
				for(int v:adjList[neighbour]){
					if(side[v]==-1){
						side[v] = side[neighbour] ^ 1;
						q.push(v);
					}
					else{
						check_bipartite &= (side[neighbour]!=side[v]);
					}
				}
			}
		}
	}
	return check_bipartite;
}

int main(){
	cin >> V;
	cout << is_bipartite() ? "YES" : "NO" << '\n';
}