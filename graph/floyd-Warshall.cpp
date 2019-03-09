#include <bits/stdc++.h>
using namespace std;

void floyd_Warshall(){
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(dist[i][k] < INF && dist[k][j] < INF)
					if(dist[i][j] < dist[i][k]+dist[k][j])
						parent[i][j] = i;
					else
						parent[i][j] = k;
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

			}
		}
	}
}

int main(void){

}