int main() {
	//code
	
	vector<int > dist(N+1,INT_MAX);
	dist[src] = 0;
	for (int i = 1; i < V; i++) {
	    for (int i = 0; i < E; i++) {
	        int ii = edges[i][0];
	        int jj = edges[i][1];
	        int wt = edges[i][2];
	        if (dist[ii] != INT_MAX && dist[jj] > dist[ii] + wt) {
	            dist[jj] = dist[ii] + wt;
	        }
	    }
	}
	for (int i = 0; i < E; i++) {
	    if (dist[ii] != INT_MAX && dist[jj] > dist[ii] + wt) {
	        return true;
	    }
	}
	return false;
	return 0;
}