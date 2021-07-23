vector<int> adj[27];
vector<bool> vis(27,false);
	
void getTopSort(int i,stack<int> &st) {
	vis[i] = true;
	vector<int>::iterator it = adj[i].begin();
	for (; it!= adj[i].end(); it++) {
		int x= (*it);
		if (vis[x]) continue;
		dfs(x,st);
		
	}
	st.push(i);
	return;
}
string getALienOrder(vector<string> v) {
	int n = v.size();
	
	string ans="";
	stack<int> st;
	
	for (int i = 1; i < v.size(); i++) {
		string s = v[i-1];
		string t = v[i];
		int sz = min(s.size(),t.size());
		for (int j = 0; j < sz; j++) {
			if (s[j] != t[j]) {
				int u = s[j] - 'a';
				int v = t[j] - 'a';
				adj[u].push_back(v);
				break;
			}
		}
	}
	for (int i = 0;i < 27; i++) {
			if (!vis[i]) {
				getTopSort(i,st);
			}
	}
	while(!st.empty()) {
		int j= st.top();
		st.pop();
		char c = j + 'a';
		string t(1,ss);
		ans = ans + ss;
	}
	return ans
}