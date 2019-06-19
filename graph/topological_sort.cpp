#include <bits/stdc++.h>
using namespace std;

/*To check cycle detection in directed graph the condition is that ("If count of visited nodes 
is not equal to the number of nodes in the graph then the graph has cycle, otherwise not.")*/  

class Graph{
	map <T, list<T> > adjList;
public:
	// Topological Sort using dfs 
	void dfshelper(T node, map<T, bool> &visited, list <T> &ordering){
		visited[node] = true;
		for(auto city: adjList[node]){
			if(!visited[city])
				dfshelper(city, visited, ordering);
		}
		ordering.push_front(node);
	}
	void dfs_topological_sort(){
		map<T, bool> visited;
		list <T> ordering;
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node])
				dfshelper(node, visited, ordering);
		}
	}
	/*----------------------------------------------------------------------------*/
	// Topological Sort using bfs 
	void topological_Sort(){
		queue <T> q;
		map <T, bool> visited;
		map <T, int> indegree;

		for(auto i:adjList){
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		// Initialize the indegree of all nodes.

		for(auto u : adjList){
			T node = u.first;
			for(T v : adjList[node])
				indegree[v]++;
		}

		// Find out all the nodes with indegree with 0 indegree.

		for(T i : adjList){
			T node = i.first;
			if(!indegree[node])
				q.push(node);
		}

		while(!q.empty()){
			T node = q.front();
			cout << node;
			q.pop();
			for(auto v:adjList[node]){
				indegree[v]--;
				if(!indegree[v])
					q.push(v);
			}
		}
	}
};

int main(){

}