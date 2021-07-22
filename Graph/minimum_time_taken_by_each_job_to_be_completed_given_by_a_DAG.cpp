// PROBLEM -

// Given a Directed Acyclic Graph having V vertices and E edges, 
// where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. 
// The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

// LINK - https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

// Topological sort approach - 
// O(N+E) time and O(N) space

#include<bits/stdc++.h>
using namespace std;

int main() {
	int N, E;
	cin>>N>>E;

	vector<int> adj[N+1];
	vector<int> indeg(N+1, 0);

	for(int i=0; i<E; i++) {
		int u, v; 
		cin >> u >> v;
		adj[u].push_back(v);
		indeg[v]++;
	}


	vector<int> job(N+1, 0);
	queue<int> q;

	for(int i=1; i<=N; i++) {
		if(indeg[i] == 0) {
			q.push(i);
			job[i] = 1;
		}
	}


	while(!q.empty()) {
		int node = q.front();
		q.pop();


		for(auto u: adj[node]) {
			indeg[u]--;
			if(indeg[u] == 0) {
				job[u] = job[node] + 1;
				q.push(u);
			}
		}
	}


	for(int i=1; i<N+1; i++) {
		cout<<job[i]<<" ";
	}

	return 0;
}