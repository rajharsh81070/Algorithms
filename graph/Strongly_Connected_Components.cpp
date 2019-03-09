#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> visited, int src, map<int, int>adjList){
	visited[src] = 1;
	for(int node: adjList[src]){
		if(!visited[node])
			dfs(&visited, node, adjList);
	}
}

bool check_SCC(int src){
	vector <int> visited(V, 0);
	dfs(&visited, node, adjList);
	if(V!=accumulate(visited.begin(), visited.end(), 0))
		return false;
	memset(visited, 0, sizeof(visited));
	dfs(&visited, node, adjList);
	if(V!=accumulate(visited.begin(), visited.end(), 0))
		return false;

	return true;
}

int main(){

}