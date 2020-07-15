class Solution {
public:
    double angleClock(int h, int m) {
        
        if (h == 12) h = 0;
        if (m == 60) {
            m = 0;
            h += 1;
            if (h > 12) h = h - 12;
        }
                    double h_angle = 0.5 * (h * 60 + m);
            double m_angle = 6 * m;
            double angle = abs(h_angle - m_angle);  
  
            angle = min(360*1.0 - angle, angle);  
      
            return angle;

    }
};
