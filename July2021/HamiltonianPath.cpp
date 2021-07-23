int N = 100;
int graph[N][N];

bool hamiltonian(vector<int> &path,vector<bool> &vis) {
	if (path.size() == N) {
		if (graph[path[path.size()-1]][0]) {
			return true;
		}
		return false;
	}

	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		if (graph[path[path.size()-1]][i]) {
			vis[i] = true;
			path.push_back(i);
			if (hamiltonian(path,vis)) {
				return true;
			}
			path.emplace_back();
		}
	}
}

void printHamiltonian() {
	vector<int> path;
	path.push_back(0);
	vector<bool> vis(V,false);
	bool isHamil = hamiltonian(path,vis);
	if (!isHamil)return;
	for (int i = 0; i < path.size(); i++) {
		cout<< path[i] << " ";
	}
	cout << endl;
}