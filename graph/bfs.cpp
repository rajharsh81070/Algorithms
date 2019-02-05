#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list <int> *adjList;

public:
	Graph(int v){
		V = v;
		adjList = new list <int> [V];
	}

	void addEdge(int u, int v, bool bidirec=true){
		adjList[u].push_back(v);
		if(bidirec)
			adjList[v].push_back(u);
	}

	void bfs(int src, int des){
		queue <int> q;

		bool *visited;
		int *dist = new int [V];
		int *parent = new int [V]{-1};
		visited = new bool [V]{0};

		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			int node = q.front();
			cout << node << " ";
			q.pop();
			for(int neighbours: adjList[node]){
				if(!visited[neighbours]){
					q.push(neighbours);
					visited[neighbours] = true;
					// Calculating the Distance of neighbours of unweighted graph.
					dist[neighbours] = dist[node] + 1;
					parent[neighbours] = node;
				}
			}
		}

		cout << "The shortest Distance from src to des is : " << dist[des] << endl;
		cout << "The shortest path is : " ;

		int temp = des;

		while(temp!=-1){
			cout << temp << "<--";
			temp = parent[temp];
		}
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

	g.bfs(0, 5);

	return 0;
}