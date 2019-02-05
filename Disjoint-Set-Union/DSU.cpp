#include<bits/stdc++.h>
using namespace std;

int parent[100];

/*****************************************************/

// Naive Implementation.

void make_set(int v){
	parent[v] = v;
}

int find_set(int v){
	if(v==parent[v])
		return v;
	return parent[v];
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b)
		parent[b] = a;
}

/********************************************************/


/********************************************************/

// Path compression optimization.

int find_set(int v){
	if(v==parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

/********************************************************/

/********************************************************/

// Union by Size

void make_set(int v){
	parent[v] = v;
	size[v] = 1;
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}

// Union by Size

void make_set(int v){
	parent[v] = v;
	rank[v] = 0; 
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(rank[a] < rank[b])
			swap(a, b);
		parent[b] = a;
		if(rank[a]==rank[b])
			rank[a]++;
	}
}

/********************************************************/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}