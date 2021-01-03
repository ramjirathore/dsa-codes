#include<iostream>
#include<list>
using namespace std;

// PROBLEM - Application of list class : Adjacency list for weighted graph
// SOLUTION -

// Structure - array of lists having indices as nodes
// further each consisting of lists 
// having pair of connecting node and weight

int main() {
	// either create static or dynamic
	// static - 
	//list<pair<int, int>> l[100];


	// dynamic
	list<pair<int, int>> *l; 

	// no. of vertices
	int n;
	cin>>n;

	l = new list<pair<int, int>>[n];

	// edges
	int e;
	cin>>e;

	for(int i=0; i<e; i++) {
		int x,y,w;
		cin>>x>>y>>w;

		// undirected graph
		l[x].push_back(make_pair(y,w));
		l[y].push_back(make_pair(x,w));
	}

	// print the graph
	for(int i=0; i<n; i++) {
		
		cout<<"Linked List"<<i<<" -> ";
		// printing ith linked list
		for(auto xp: l[i]) {
			cout<<"("<<xp.first<<","<<xp.second<<")"<<" ";
		}
		cout<<endl;
	}

	return 0;

}