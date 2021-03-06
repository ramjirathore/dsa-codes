// O((N+E)logN) time and O(N) space

#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> pi;
#define INF 1e9

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pi, vector<pi>, greater<pi>> pq; 
        
        pq.push({0, S});
        
        vector<int> dist(V, INF);
        dist[S] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]) {
                int curr = it[0];
                int weight = it[1];
                
                if(dist[node] + weight < dist[curr]) {
                    dist[curr] = dist[node] + weight;
                    pq.push({dist[curr], curr});
                } 
            }
        }
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

