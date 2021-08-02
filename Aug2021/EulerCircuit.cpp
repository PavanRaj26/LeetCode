#include <stdio.h>

class Graph {
  list<int> *adj;
  
  public:
  Graph(int V);
  void push(int u,int v);
  void dfs(int i, stack<int> &st);
  void topSort(stack<int> &st);
  Graph * transpose();
  bool isSingleSCC();
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    
}
void Graph::push(int u,int v) {
    adj[u].push_back(v);
}
void Graph::dfs(int i,stack<int> &st,vector<bool> &vis) {
    
    vis[i] = 1;
    list<int>::iterator it = adj[i].begin();
    for (; it != adj[i].end(); it++) {
        int x = (*it);
        if (vis[x])continue;
        dfs(x);
    }
    st.push(i);
}
void Graph::topSort(stack<int> &st) {
    int V = this->V;
    vector<bool> vis(V,false);
    for (int i = 0; i < V; i++) {
        if (vis[i]==false) {
            dfs(i,st,vis);
        }
    }
}
Graph Graph::transpose() {
    Graph gTr(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0;j < adj[i].size(); j++) {
            gTr.adj[adj[i][j]].push_back(i);
        }
    }
    return gTr;
}
bool Graph::isSingleSCC() {
    
    stack<int> st;
	topSort(st);
	int n;
	for (int i = 0; i < V; i++) if (adj[i].size() != 0) {
	    n = i;
	    break;
	}
	
	vector<bool> vis(V,false);
	dfs(n,st,vis);
	for (int i = 0;i < V; i++) if (adj[i].size() > 0 && vis[i] == false) return false;
	
	Graph gTr = g.transpose();
	int x = st.top();
	for (int i = 0; i < V; i++) vis[i] = false;
	dfs(0,st,vis);
	for (int i = 0; i < V; i++) if (adj[i].size() && vis[i] == false) return false;
	return true;
}
int main() {
	//code
    Graph g = new Graph(10);
	bool ans=true;
	vector<int> inDeg(V,0);
	vector<int> outDeg(V,0);
	if (!isSingleSCC()) {ans = false;}
	for (int i = 0; i < V; i++) {
	    outDeg[i] = adj[i].size();
	    vector<int>::iterator it = adj[i].begin();
	    for (; it!= adj[i].end(); it++) {
	        int x = (*it);
	        inDeg[x]++;
	    }
	}
	for (int i = 0; i < V; i++) {
	    if (inDeg[i] != outDeg[i]) {ans = false;}
	}
	return true;
	return 0;
}