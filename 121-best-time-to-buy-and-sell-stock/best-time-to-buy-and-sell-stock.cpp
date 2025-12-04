class Solution {
public:
    int maxProfit(vector<int>& a)
    {
        int maxpb = a[0],maxps = 0, r = a.size(), l = 0;
        if (r == 0) return 0;
        while(l < r)
        {  
            maxpb = min(maxpb, a[l]);
            maxps = max(maxps, a[l]-maxpb); 
            l++;      
        }
        return maxps;
    }
};