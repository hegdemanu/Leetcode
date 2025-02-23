class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (n + m)/2 + (n+m)%2 ;
        for (int i = 0; i < n ; i++)
        {
            nums1[m + i] = nums2[i];
        }
        
        while(gap > 0)
        {
            int l = 0;
            int r = l + gap;
            {
                while(r < n + m)
                {
                 if (nums1[l] > nums1[r])
                 {
                    swap(nums1[l], nums1[r]);
                    l++;
                    r++;
                 }
                 else r++, l++ ;
                }
                if (gap == 1) break;
                gap = ((gap)/2) + (gap%2);
            }
        }
    }
};