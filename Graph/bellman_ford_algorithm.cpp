// TC - O((N-1)E) time and O(N) space


#include<bits/stdc++.h>
using namespace std;

#define inf 1e9

struct node {
	int u;
	int v;
	int wt;

	node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};

int main() {
	int n;
	int m;

	cin >> n >> m;

	vector<node> edges;

	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges.push_back(node(u, v, w));
	}

	int src;
	cin >> src;


	vector<int> dist(n, inf);
	dist[src] = 0;


	// Relax N-1 times
	for(int i=1; i<=n-1; i++) {
		for(auto it: edges) {
			if(dist[it.u] + it.wt < dist[it.v]) {
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
	}


	// Do it one more time if dist reduces then => negative cycle is there
	bool flag = false;
	for(auto it: edges) {
		if(dist[it.u] + it.wt < dist[it.v]) {
			flag = true;
			cout<<"Negative cycle"<<endl;
			dist[it.v] = dist[it.u] + it.wt;
			break;
		}
	}

	if(!flag) {
		for(int i=0; i<n; i++) {
			cout<<i<<" "<<dist[i]<<endl;
		}
	}

}
