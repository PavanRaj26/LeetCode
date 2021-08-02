// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct Cell {
        int i;
        int dis;
        //Cell(int i,int dis) : i(i),dis(dis) {};
    };
    int minThrow(int N, int arr[]){
        // code here
        //Variables
        queue<Cell> Q;
        vector<int> pos(32,-1);
        vector<bool> vis(32,false);
        
        //pre-fill
        
        for (int i = 0; i < N; i+=2) {
            pos[arr[i]] = arr[i+1];
            
        }
        //Logic
        Cell c = {1,0};
        Q.push(c);
        vis[1] = true;
        Cell cc;
        while (!Q.empty()) {
            cc = Q.front();
            Q.pop();
            int i = cc.i;
            if (i == 30) {
                break;
            }
            for (int j = i + 1; j <= i + 6 && j <= 30; j++) {
                
                if (!vis[j]) {
                    Cell a;
                    int dis = cc.dis;
                    a.dis = dis + 1;
                    vis[j] = true;
                    
                    if (pos[j] != -1) {
                        a.i = pos[j];
                    }  else {
                        a.i = j;
                    }
                    //cout << a.i <<" "<<a.dis << endl;
                    Q.push(a);
                }
            }
        }
        
        return cc.dis;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends