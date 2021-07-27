// Apply bellman ford algorithm - O(N*E) time and O(N) space

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    
	    int m = edges.size();
	    
	    // Relax n-1 times 
	    for(int j=1; j<=n-1; j++) {
    	    for(int i=0; i<m; i++) {
    	        int u = edges[i][0];
    	        int v = edges[i][1];
    	        int wt = edges[i][2];
    	        
    	        if(dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
    	            dist[v] = dist[u] + wt;
    	        }
    	    }
	    }
	    
	    // Try one more time if it relaxes then it contains negative cycle
	   
	    for(int i=0; i<m; i++) {
    	    int u = edges[i][0];
    	    int v = edges[i][1];
    	    int wt = edges[i][2];
    	        
    	    if(dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
    	       //  dist[v] = dist[u] + wt;
    	       return 1;
    	    }
    	}
    	
    	return 0;

	}
};