class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = matrix.size();//rows
        if (n == 0) return false;
        int m = matrix[0].size();//columns
        if (m == 0) return false;
        int l = 0;int h = m*n - 1;//row search
        
        while(h >= l){
            int mid = l + (h - l) / 2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) h = mid - 1;
            else l = mid + 1;

        }
        return false;
    }
};