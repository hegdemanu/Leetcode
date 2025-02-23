class Solution {
public:
    bool isPalindrome(int x) {
        int m = x;
        int t = 0;

        if (x>=0)
        {while (m!=0)
        {
        if (t>INT_MAX/10 || t<INT_MIN/10){return 0;}
          t = (m%10)+(t*10);
          m/=10;
        }
        if (t==x)
        {
            return 1;
        }
        else {
            return 0;
        }

        }
        else {
            return 0;
            }
    }
};