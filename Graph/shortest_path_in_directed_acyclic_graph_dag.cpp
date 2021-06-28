// PROBLEM - Find shortest path in directed acyclic graph(DAG)

// Approach - O(N+E) time and O(N) space

// The intution is similar to previous shortest path in undirected graph with unit weights
// We can do a simple dfs or bfs and simply update the node's distance
// But think while doing such you might be visiting the whole path again multiple times
// So to improve the time complexity we first do a topological sort and then do bfs/dfs using that


#include<bits/stdc++.h>
using namespace std; 

#define INF 1e9

class dag {
	vector<int> visited;
	stack<int> s;
public: 

	void findTopoSort(int src, vector<pair<int, int>> adj[]) {
		for(auto [node, wt]: adj[src]) {
			if(!visited[node]) {
				findTopoSort(node, adj);
			}
		}

		s.push(src);
	}

	void shortestPath(int src, vector<pair<int, int>> adj[], int N) {
		visited.resize(N, 0);

		for(int i=0; i<N; i++) {
			if(!visited[i]) {
				findTopoSort(i, adj);
			}
		}

		vector<int> dist(N, INF);

		dist[src] = 0;

		while(!s.empty()) {
			int node = s.top();
			s.pop();

			if(dist[node] != INF) {
				for(auto [curr, weight]: adj[node]) {
					if(dist[node] + weight < dist[curr]) {
						dist[curr] = dist[node] + weight;
					}
				}
			}
		}

		for(int i=0; i<N; i++) {
			cout<<i<<" "<<dist[i]<<endl;
		}
	}
};
int main() {
	int N, E;
	cin >> N >> E;

	vector<pair<int, int>> adj[N];

	// storing graph
	for(int i=0; i<E; i++) {
		int u, v, wt;
		cin >>u >> v>> wt;
		adj[u].push_back({v, wt});
	}
	
	dag g;
	g.shortestPath(0, adj, N);
}
