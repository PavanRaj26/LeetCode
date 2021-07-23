void getTopSort(int i, stack &st) {
	//Simple DFS with pushing to stack
}

int LongestPathinDag(int src) {
	
	vector<int> dist(V,0);
	stack<int> st;
	getTopSort(0,st);
	dist[src] = 0;
	
	while (!st.empty()) {
		int u = st.top(); st.pop();
		vector<int>::iterator it = adj[u].begin();
		for (; it != adj[u].end(); it++) {
			int x = (*it).first;
			int wt = (*it).second;
			if (dist[x] < dist[u] + wt) {
				dist[x] = dist[u] + wt;
			}
		}
	}
	//Print Distances
}