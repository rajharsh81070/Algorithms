#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	map <T, list<T> > adjList;
public:
	// Cycle Detection using bfs.
	bool isCyclic_bfs(int src){
		queue <T> q;
		map <T, bool> visited;
		map <T, int> parent;

		q.push(src);
		visited[src] = true;
		parent[src] = src; 
		while(!q.empty()){
			T node = q.front();
			q.pop();

			for(auto neighbour:adjList[node]){
				if(visited[neighbour] && parent[node]!=neighbour)
					return true;
				else if(!visited[neighbour]){
					parent[neighbour] = node;
					visited[neighbour] = true;
					q.push(neighbour);
				}
			}
		}
		return false;
	}
	// Cycle Detection using dfs.
	bool isCyclicHelper(T node, map <T, bool> &visited, T parent){
		visited[node] = true;
		for(T neighbour:adjList[node]){
			if(!visited[neighbour]){
				bool ans = isCyclicHelper(neighbour, visited, node);
				if(ans)
					return true;
			}
			else if(parent!=neighbour)
				return true;
		}
		return false;
	}
	bool isCyclic_dfs(){
		map <T, bool> visited;

		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				bool ans = isCyclicHelper(node, visited, node);
				if(ans)
					return true;
			}
		}
		return false;
	}
};

int main()
{

}