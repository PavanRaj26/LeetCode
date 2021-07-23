vector<int> adj[V];

void recur(int V,vector<int> &inDeg, vector<int> &res) {
	bool allVis = false;
	for (int i = 0; i < V; i++) {
		if (!vis[i] && inDeg[i] == 0) {
			allVis = true;
			
			res.push_back(i);
			vector<int>::iterator it = adj[i].begin();
			for (; it!=adj[i].end(); it++) {
				int x = (*it);
				inDeg[x]--;
			}
			vis[i] = true;
			recur(V,inDeg,res);
			vis[i] = false;
			res.pop_back();
			it = adj[i].begin();
			for (; it!=adj[i].end(); it++) {
				int x = (*it);
				inDeg[x]++;
			}
			
		}
	}
	if (!allVis) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] <<" ";
		}
		cout << endl;
	}
}
void printAllTopologicalSorts() {
	
	vector<int> inDeg(V,0); 
	for (int i = 0; i < V; i++) {
		vector<int>::iterator it = adj[i].begin();
		for (; it!= adj[i].end(); it++) {
			int x = (*it);
			inDeg[x]++;
		}
	}
	vector<int> res;
	recur(V,inDeg,res);
}