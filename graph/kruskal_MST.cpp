#include <bits/stdc++.h>
using namespace std;

int parent[MAXN];
pair <int , pair < int , int > > p[MAXN];

int find(int x){
	while(parent[x] != x){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void union_set(int x, int y){
	x = find(x);
	y = find(y);
	parent[x] = parent[y];
}

int kruskal_Algo(pair <int , pair < int , int > > p[]){
	int minCost = 0;
	int x, y;
	for (int i=0; i<edges; i++){
		x = p[i].second.first;
		y = p[i].second.second;
		int cost = p[i].first;
		if(find(x) != find(y)){
			minCost += cost;
			union_set(x, y);
		}
	}
}

int main(){
	for (int i=0 ; i<MAXN ; i++)
		parent[i] = i;
	cin >> nodes >> edges;
	for(int i=0 ; i<edges; i++){
		cin >> x >> y >> weight;
		p[i] = make_pair(weight, make_pair(x, y));
	}
	sort(p, p + edges);
	minCost = kruskal_Algo(p);
	return 0;
}