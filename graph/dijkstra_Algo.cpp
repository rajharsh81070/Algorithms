#include <bits/stdc++.h>
using namespace std;

// Overall time complexity is O(E+V)*O(LogV). 

template<typename T>

class Graph{
	unordered_map<T, list< pair <T, int>>> adjList;
public:
	void addEdge(T u, T v, int dist, bool bidirec=true){
		adjList[u].push_back(make_pair(v, dist));
		if(bidirec)
			adjList[v].push_back(make_pair(u, dist));
	}
	void dijkstra_SSSP(T src){
		unordered_map<T, int>dist;
		// Initialize the distance of all node to infinity.
		for(auto node:adjList){
			dist[node.first] = INT_MAX;
		}
		// Set maked to find the minimum distance from the node.
		set<pair<int, T>>st_min_dist;
		dist[src] = 0;
		st_min_dist.insert(make_pair(0, src));
		while(!st_min_dist.empty()){
			// To get the pair at the front.
			auto p = *(st_min_dist.begin());
			T parent = p.second;
			int dist_parent = p.first;
			st_min_dist.erase(st_min_dist.begin());
			for(auto child: adjList[parent]){
				if(dist[child.first] > child.second + dist_parent){
					// In the set the updation of a particular is not possible.
					// So, we have to find the old pair and remove it, and the insert the new pair.
					T des = child.first;
					auto f = st_min_dist.find(make_pair(dist[des], des));
					if(f!=st_min_dist.end())
						st_min_dist.erase(f);
					dist[des] = dist_parent + child.second;
					st_min_dist.insert(make_pair(dist[des], des));
				}
			}
		}
		for(auto d: dist){
			cout << d.first << " is located at distance of " << d.second << "\n";
		}
	}
};

int main(void){
	Graph <int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	g.dijkstra_SSSP(1);
}