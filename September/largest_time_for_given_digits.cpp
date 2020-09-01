class Solution {
public:
    
    string largestTimeFromDigits(vector<int>& A) {
        vector<pair<int,int> > v;
        for (int i =0; i < 4; i++) {            
            for (int j = 0; j < 4; j++) {
                if (i != j)
                for (int k = 0; k < 4; k++) {
                    if (k != i && k != j)
                    for (int l = 0; l < 4; l++) {
                        if (l != k && l != i && l != j) {
                            int num1 = 10 * A[i] + A[j];
                            int num2 = 10 * A[k] + A[l];
                            if (num1 <= 23 && num2 <= 59) {
                                v.push_back(make_pair(num1,num2));
                            }
                            // v.push_back(make_pair(num2,num1));
                        }
                    }
                }
            }
        }
        if (v.size() == 0) {
            return "";
        }
        sort(v.begin(),v.end());
        
        string res = "";
        string res1,res2;
        string z(1,'0');
        int num1 = v[v.size()-1].first;
        int num2 = v[v.size()-1].second;
        cout <<num1<<" "<<num2<<endl;
        int tmp1= num1;
        int tmp2 = num2;
        if (num1 == 0) res1 = res1 + "0";
        if (num2 == 0) res2 = res2 + "0";
        while(num1) {
            string r(1,num1%10+'0');
            res1 = res1 + r;            
            num1/=10;
        }
        while(num2) {
            string r(1,num2%10+'0');
            res2 = res2 + r;
            num2/=10;
        }
        cout <<res1<<" ";
        reverse(res1.begin(),res1.end());
        reverse(res2.begin(),res2.end());        
        cout <<res1<<endl;
        if (tmp1 < 10) res1= z + res1;
        if (tmp2 < 10) res2= z + res2;
        
        res = res1 + ":" + res2;
        return res;
    }
    
};


