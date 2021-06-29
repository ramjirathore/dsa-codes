// Brute force - O((N+E)*N) time and O(N) space 

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX); // for storing weights
        vector<bool> mstSet(V, false); // For checking if a node is in mst or not
        vector<int> parent(V, -1); // For storing parent of each node in mst
        
        key[0] = 0; // to start from some node
        for(int cnt = 0; cnt < V-1; cnt++) { // Since mst must have n-1 edges
            int minWt = INT_MAX;
            int u; // key having minimum weight
            
            // find key having minimum weight
            for(int v=0; v<V; v++) {
                if(mstSet[v] == false and key[v] < minWt) {
                    minWt = key[v];
                    u = v;
                }
            }
            
            mstSet[u] = true;
            
            for(auto it: adj[u]) {
                int v = it[0];
                int wt = it[1];
                if(mstSet[v] == false and wt < key[v]) {
                    parent[v] = u;
                    key[v] = wt;
                }
            }
        }
        
        
        int mstWeight = 0;
        for(auto it: key) {
            mstWeight += it;
        }
        
        return mstWeight;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

// Efficient approach - O((N+E)logN) time and O(N) space

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,m;
    cin >> N >> m;
    vector<pair<int,int> > adj[N]; 

    int a,b,wt;
    for(int i = 0; i<m ; i++){
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }   
    
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}