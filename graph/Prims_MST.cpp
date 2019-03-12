#include <bits/stdc++.h>
using namespace std;

bool marked[MAXN];
vector < pair< int, int > > adjlist[MAXN];

int prims_MST(int src){
	priority_queue< pair< int, int >, vector < pair< int, int > >, greater < pair< int, int > > > Q;
	int y;
	int minCost = 0;
	pair < int, int > p;
	Q.push(make_pair(0, src));
	while(!Q.empty()){
		//  Select edge with minimum weight.
		p = Q.top();
		Q.pop();
		src = p.second;
		// Checking for Cycle.
		if(marked[src] == true)
			continue;
		minCost += p.first;
		marked[src] = true;
		for(int i=0; i<adjList[src].size()){
			y = adjList[src][i].second;
			if(marked[y] == true)
				Q.push(adjList[src][i]);
		}
	}
	return minCost;
}

int main(){
	cin >> nodes >> edges;
	for(int i=0; i<edges; i++){
		cin >> x >> y >> weight;
		adjList[x].push_back(make_pair(weight, y));
		adjList[y].push_back(make_pair(weight, x));
	}
	// Selecting 1 as the starting node.
	minCost = prims_MST(1);
	return 0;
}