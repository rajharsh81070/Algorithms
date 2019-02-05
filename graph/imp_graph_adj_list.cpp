#include<bits/stdc++.h>
using namespace std;

template <typename T>

// Implementation of graph using adjacency list.		
// Adjacency list implementaion using array of linked list.
class Graph{
	int V;

	// Array of linked list of size V. V linked list are there.
	list <int> *adjList;
public:	
	Graph(int v){
		V = v;
		adjList = new list <int> [V];
	}
	void addEdge(int u, int v, bool bidirec=true){
		adjList[u].push_back(v);
		if(bidirec==true)
			adjList[v].push_back(u);
	}
	void printAdjList(){
		for(int i=0; i<V; i++){
			cout << i << "->";
			for(int node: adjList[i])
				cout << node << ',';
			cout << '\n';
		}
	}
};

/*----------------------------------------------------------------------------------------------*/

// Adjacency list implementaion using hashmap.

class Graph_2{

	map <T, list <T> > adjList;
public:
	void addEdge(T u, T v, bool bidirec=true){
		adjList[u].push_back(v);
		if(bidirec==true)
			adjList[v].push_back(u);
	}
	void printAdjList(){
		for(auto row: adjList){
			T key = row.first;
			cout << key << "->";
			for(T values: row.second)
				cout << values << ',';
			cout << '\n';
		}
	}
};

int main()
{
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 3);
	g.addEdge(3, 2);

	g.printAdjList();
	/*----------------------------------------------------------------------------------------------*/
	Graph_2 <string> g2;
	g2.addEdge("Amritsar", "Delhi");
	g2.addEdge("Amritsar", "Jaipur");
	g2.addEdge("Delhi", "Siachen");
	g2.addEdge("Delhi", "Bangalore");
	g2.addEdge("Delhi", "Agra");
	g2.addEdge("Amritsar", "Siachen");

	g2.printAdjList();

	return 0;
}