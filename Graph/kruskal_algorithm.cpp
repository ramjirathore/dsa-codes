// Kruskal algo - O(MlogM) time and O(M) space
// O(MlogM + M*4alpha) time .. aplha ~ 1
// O(M+N+N) space

// This is a DSU implementation

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int u;
	int v; 
	int wt; 

	Node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};


bool comparator(Node a, Node b) {
	return a.wt < b.wt;
}

int findParent(int node, vector<int> &parent) {
	if(node == parent[node])
		return node;

	return parent[node] = findParent(parent[node], parent);
}

void doUnion(int u, int v, vector<int> &parent, vector<int> &Rank) {
	u = findParent(u, parent);
	v = findParent(v, parent);

	if(Rank[u] < Rank[v]) {
		parent[u] = v; 
	} else if(Rank[v] < Rank[u]) {
		parent[v] = u;
	} else {
		parent[v] = u;
		Rank[u]++;
	}
}

int main() {
	int N, M;
	cin >> N >> M; // Nodes and Edges

	vector<Node> edges;
	for(int i=0; i<M; i++) {
		int u, v, w; 
		cin >> u >> v >> w;
		edges.push_back(Node(u, v, w)); 
	}

	// sort the edges by weight
	sort(edges.begin(), edges.end(), comparator);

	// store parent and initialize them by itself
	vector<int> parent(N+1);

	for(int i=1; i<N+1; i++) {
		parent[i] = i;
	}

	// Create Rank array
	vector<int> Rank(N+1, 0);


	// to store mst (edges to be precise)
	vector<pair<int, int>> mst;
	// Cost for mst
	int cost = 0;


	for(auto it: edges) {
		if(findParent(it.u, parent) != findParent(it.v, parent)) {
			mst.push_back({it.u, it.v});
			cost += it.wt;

			doUnion(it.u, it.v, parent, Rank);
		}
	} 

	cout<<"Cost for mst "<<cost<<endl;
	for(auto it: mst) {
		cout<<it.first<<" - "<<it.second<<endl;
	}

}