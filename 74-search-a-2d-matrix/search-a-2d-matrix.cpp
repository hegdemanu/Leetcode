class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int lo = 0, hi = n - 1;
        
        // Binary Search to find the correct row
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target) {
                // Target is within this row, apply Binary Search on this row
                int l = 0, h = m - 1;
                while (l <= h) {
                    int midy = l + (h - l) / 2;
                    if (matrix[mid][midy] == target) return true;
                    else if (matrix[mid][midy] < target) l = midy + 1;
                    else h = midy - 1;
                }
                return false; // If not found within the row
            }
            else if (matrix[mid][m - 1] < target) lo = mid + 1; // Move to a lower row
            else hi = mid - 1; // Move to a higher row
        }
        
        return false;
    }
};
