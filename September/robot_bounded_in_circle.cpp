class Solution {
public:
    bool isRobotBounded(string a) {
        int n= a.size();
        int cnt= 0;
        int dir = 0;
        int x= 0;
        int y = 0;
        int cc = 4;
        while(cc--) {
            for (int i =0; i < n; i++) {
                if (a[i] == 'L') {
                    dir = (dir -1 + 4) % 4; 
                } else if (a[i] == 'R') {
                    dir = (dir + 1) % 4;
                }
                else {
                    if (dir == 0) {
                        y = y + 1;                    
                    } else if (dir == 1) {
                        x = x + 1;
                    } else if (dir == 2) {
                        y = y - 1;
                    } else {
                        x = x - 1;
                    }
                }
            }
        }
        if (x == 0 && y == 0) {
            return true;
        }
        
        return false;
    }
};
