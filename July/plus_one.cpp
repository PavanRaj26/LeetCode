class Solution {
    private:
    vector<int> v;

public:
    vector<int> plusOne(vector<int>& a) {
        
        int car = 1;
        int n= a.size();
        for (int i = n - 1; i >= 0; i--) {
            int sum = (a[i] + car);
            v.push_back(sum %10);
            car = sum / 10;
        }
        if (car) v.push_back(1);
        reverse(v.begin(),v.end());
        return v;
    }
};
