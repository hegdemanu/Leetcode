class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();//rows
        int m = matrix[0].size();//columns
        int l = 0;int h = n - 1;//row search
        while(h >= l){
            int mid = l + (h - l) / 2;
            if (matrix[mid][m - 1] == target) return true;
            else if (matrix[mid][m - 1] < target) l = mid + 1;
            else{
                if(matrix[mid][0] == target) return true;
                else if(matrix[mid][0] > target) h = mid - 1;
                else{
                    int lo = 0; int hi = m - 1;// column search
                    while(hi >= lo){
                        int midy = lo + (hi - lo) / 2;
                        if (matrix[mid][midy] == target) return true;
                        else if (matrix[mid][midy]< target) lo = midy + 1;
                        else{
                            hi = midy - 1; 
                        }
                    }
                    return false;          
                }
            }

        }
        return false;
    }
};