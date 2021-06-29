// Kosaraju's Algorithm for Strongly Connected Components - 
// O(N+E) time and O(N+E) space

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &s, vector<int> &visited, vector<int> adj[]) {
	visited[node] = 1;

	for(auto it: adj[node]) {
		if(!visited[it]) {
			dfs(it,s, visited, adj);
		}
	}

	s.push(node);
}

void revDfs(int node, vector<int> adj[], vector<int> &visited) {
	cout<<node<<" ";
	visited[node] = 1;

	for(auto it: adj[node]) {
		if(!visited[it]) {
			revDfs(it, adj, visited);
		}
	}
}

int main() {
	int N, E;
	cin >> N >> E;

	vector<int> adj[N+1];

	// Taking input of graph 
	for(int i=0; i<E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); 
	}

	// 1. Find finishing time
	vector<int> visited(N+1, 0);
	stack<int> s;

	for(int i=1; i<=N; i++) {
		if(!visited[i]) {
			dfs(i, s, visited, adj);
		}
	}

	// 2. Tranpose the graph
	vector<int> transpose[N+1];

	for(int i=1; i<=N; i++) {
		visited[i] = 0;
		for(auto it: adj[i]) {
			transpose[it].push_back(i);
		}

	}

	// 3. Do dfs on finishing time 
	while(!s.empty()) {
		int node = s.top();
		s.pop();

		if(!visited[node]) {
			revDfs(node, transpose, visited);
			cout<<endl;
		}
	}

}