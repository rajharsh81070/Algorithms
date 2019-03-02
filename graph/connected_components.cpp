#include <bits/stdc++.h>
using namespace std;

/*Algorithm :- We will be doing a series of rounds of DFS: The first round will start from first 
node and all the nodes in the first connected component will be traversed (found). Then we find 
the first unvisited node of the remaining nodes, and run Depth First Search on it, thus finding 
a second connected component. And so on, until all the nodes are visited.*/

/*Time Complexity :- The total asymptotic running time of this algorithm is O(n+m).*/

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