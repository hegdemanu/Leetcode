class Solution {
public:
    void sortColors(vector<int>& a) {
        int i = 0;
        int j = 0;
        int n = a.size()-1;
        while(i<=n)
        {
            if (a[i] == 0)
            {
                swap(a[i],a[j]);
                j++;
                i++;
            }
            else if (a[i] == 2)
            {
                swap(a[i],a[n]);
                n--;
            }

            else{
                i++;
            }
        }

    }
};