#define ss second
#define ff first
class Solution {
    queue< pair< pair<int,char>,int> > q;
    priority_queue< pair<int,char> > pq;
    unordered_map<char,int> mp;
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        if (n == 0) return tasks.size();
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        unordered_map<char,int>::iterator it = mp.begin();
        for (;it != mp.end(); it++) {
            pq.push(make_pair((*it).ss,(*it).ff));
        }
        int ans = 0;
        int idx = 0;
        
        while(!q.empty() || !pq.empty()) {
            if (pq.empty()) {
                ans++;
            }
            else {
                pair<int,char> cur = pq.top();
                pq.pop();
                ans++;
                cur.ff = cur.ff-1;
                if (cur.ff >= 1)
                    q.push(make_pair(cur,idx+n));
            }
            
            if (!q.empty()) {
            pair< pair<int,char>,int> pp = q.front();
            if (pp.ss <= idx) {
                pq.push(q.front().ff);
                q.pop();
            }
                        }
            idx++;
        }
        return ans;
    }
};
