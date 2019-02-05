#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	map <T, list<T> > adjList;
public:
	void dfshelper(T src, bool visited[]){
		visited[src] = true;
		for(auto node: adjList[src]){
			if(!visited[node])
				dfshelper(node, visited);
		}
	}
	void dfs(int src){
		int connected_components = 1;
		dfshelper(src, visited);
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				dfshelper(node, visited);
				connected_components++;
			}
		}
	}
};

int main()
{

}