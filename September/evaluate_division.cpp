class Solution {
    private :
    map<string, vector<pair<string,double > > > mp;
    vector<double> ans;
    map<string,int> vis;
    string target;
    
public:
    bool checkTar(string x,string y) {
        if (x.size() != y.size()) return false;
        for (int i =0; i < x.size(); i++) {
            if (x[i] != y[i]) return false;
        }
        return true;
    }
    bool dfs(string i,double &d) {
        
        vis[i] = 1;
        vector<pair<string,double> >::iterator it = mp[i].begin();
        
        for (; it!= mp[i].end(); it++) {
            string x=(*it).first;
            double y=(*it).second;
            d = d * y;
            if (checkTar(x,target)) {                
                return true;
            }
            if (vis[x] == 0 && dfs(x,d)) {                
                return true;
            } 
            d = d / y;
        }
        return false;        
    }
    vector<double> calcEquation(vector<vector<string>>& eqns, vector<double>& values, vector<vector<string>>& queries) {
        map<string,int> hsh;
        
        for (int i =0; i < eqns.size(); i++) {
            string a = eqns[i][0];
            string b = eqns[i][1];
            double val = values[i];            
            mp[a].push_back(make_pair(b,val));
            mp[b].push_back(make_pair(a,1.0 / val));                        
            hsh[a] = 1;
            hsh[b] = 1;
        }
        for (int i = 0; i < queries.size(); i++) {
            string a1 = queries[i][0];
            string b1 = queries[i][1];
            target = b1;
            double val = 1.0;
            cout << a1 <<" "<<b1 << " "<<target << endl;
            if (hsh.find(a1) == hsh.end() || hsh.find(b1) == hsh.end()) {
                ans.push_back(-1.0);
            }
            else if (checkTar(a1,b1)) {
                ans.push_back(1.0);
                
            } else {
                if (dfs(a1,val)) {
                    ans.push_back(val);
                    vis.clear();
                } else {
                    ans.push_back(-1.0);
                }
            }
        }
        return ans;
    }
};
