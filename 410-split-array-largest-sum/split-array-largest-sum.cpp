class Solution
{
    bool canSplit(vector<int> &nums, int k, int mid)
    {
        int sum = 0;
        int cnt = 1;
        for (int n : nums)
        {
            if ((n + sum) <= mid)
            {
                sum += n;
            }
            else
            {
                sum = n;
                cnt++;
                if (cnt > k) return false;
            }
        }
        return true;
    }
    public:
        int splitArray(vector<int> &nums, int k)
        {
            int r = accumulate(nums.begin(), nums.end(), 0);
            if (k == 1) return r;
            int l = *max_element(nums.begin(), nums.end());
            while (l <r)
            {
                int mid = l + (r - l) / 2;
                if (canSplit(nums, k, mid))
                {
                    r = mid;
                }
                else l = mid + 1;
            }
            return r;
        }
};