class Solution {
public:
    int reverse(int x) {
        int t = 0;
        
        while (x != 0) { 
            if (t > INT_MAX/10 || t < INT_MIN/10) return 0;
            
            t = t*10 + (x%10);
            x /= 10;
        }
        return t;
    }
};