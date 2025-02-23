class Solution {
public:
    void nextPermutation(vector<int>& a) 
    {
        int n = a.size();
        int point = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                point = i ;
                break;
            }
        }
        if (point == -1)
        {
            reverse(a.begin(), a.end());
        }
        else 
        {
            for (int i = n -1;i > point;i--)
        {
            if (a[i] > a[point])
            {
                swap(a[point], a[i]);
                break;
            }
        }
         reverse(a.begin() + (point + 1), a.end()); ;  
        }  
        
    }
};