#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int Rank[100000];

void makeSet() {
	for(int i=1; i<=100000; i++) {
		parent[i] = i;
		Rank[i] = 0;
	}
}

// 7->6->5->4 
// 4 is the ultimate parent
int findParent(int node) {
	if(node == parent[node]) {
		return node;
	}

	// Path Compression by storing the parent
	return parent[node] = findParent(parent[node]);
}


void Union(int u, int v) {
	u = findParent(u);
	v = findParent(v);

	if(Rank[u] < Rank[v]) {
		parent[u] = v;
	} else if(Rank[v] < Rank[v]) {
		parent[v] = u;
	} else {
		parent[v] = u;
		Rank[u]++;
	}
}

int main() {
	makeSet();

	int m; 
	cin >> m;
	while(m--) {
		int u, v;
		cin >> u >> v; 
		Union(u, v);
	}

	// if 2 and 3 belong to the same component or not
	if(findParent(3) != findParent(4)) {
		cout<<"Different Component";
	} else {
		cout<<"Same Component";
	}





}