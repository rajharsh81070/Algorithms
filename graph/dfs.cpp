#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	map < int, list<int> > adjList;

public:
	Graph(int v){
		V = v;
	}
	void addEdge(int u, int v, bool bidirec=true){
		adjList[u].push_back(v);
		if(bidirec)
			adjList[v].push_back(u);
	}
	void dfshelper(int node, bool visited[]){
		visited[node] = true;
		cout << node << " ";
		for(auto neighbour: adjList[node]){
			if(!visited[neighbour])
				dfshelper(neighbour, visited);
		}
	}
	void dfs(int src){
		bool *visited = new bool [V]{false};
		dfshelper(src, visited);
	}
};

int main()
{
	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(3, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(3, 4);

	g.dfs(0);

	return 0;
}