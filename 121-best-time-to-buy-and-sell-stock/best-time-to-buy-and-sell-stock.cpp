class Solution {
public:
    int maxProfit(vector<int>& a)
    {
        int maxpb = a[0];
        int maxps = 0;
        int n = a.size();
        if (n == 0) return 0;
        for (int i =0; i < n; i++)
        {  
            maxpb = min(maxpb, a[i]);
            maxps = max(maxps, a[i]-maxpb);       
        }
        return maxps;
    }
};