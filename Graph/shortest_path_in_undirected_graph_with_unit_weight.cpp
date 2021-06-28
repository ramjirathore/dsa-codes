// The approach is simple we do a variation of BFS - O(N+E) time and O(N) space
// We initalise a distance vector with inf
// Then while traversing we check if the current dist is less than the one present in the dist array
// If yes then we update it


vector<int> shortest(vector<int> adj[], int N, int src) {
	vector<int> dist(N, INT_MAX);

	queue<int> q;
	q.push(src);

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto it: adj[node]) {
			if(dist[it] + 1 < dist[node]) {
				dist[node] = dist[it] + 1;
				q.push(it);
			}
		}

	}

	return dist;
}