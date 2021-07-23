bool FloydWarshall() {
	int dist[V][V];
	for (int i = 0; i < V; i++) {
		for (int j = 0;j < V; j++) {
			dist[i][j] = graph[i][j];
		}
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			for (int k = 0; k < V; k++) {
					if (dist[i][j] > dist[i][k] + dist[k][j] && (dist[k][j] != INF && dist[i][k] != INF)) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (dist[V][V] < 0) return true;
	return false;
}