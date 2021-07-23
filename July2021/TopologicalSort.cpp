#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
void dfs(int i, stack &st) {
	vis[i] = true;
	vector<int>::iterator it = adj[i].begin();
	for (; it != adj[i].end(); it++) {
		int x = (*it);
		if (vis[x]) continue;
		dfs(x,st);
	}
	st.push(i);
}
void printTopologicalSort(vector<int> adj[],int V) {
	stack<int> st;
	vector<bool> vis(V,false);
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs(i,st);
		}	
	}
	while (!st.empty()) {
		cout << st.top() <<" ";
	}
	cout <<endl;
}
