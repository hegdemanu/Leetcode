class Solution {
    int binary_search(int high, int low, int target, vector<int>& nums){
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] != target){
                if (nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            else return mid;
        }
        return -1;
    }
    int left_search(int high, int low, int target, vector<int>& nums){
       int result = binary_search(high, low, target, nums);

        cout << "res: " << result << endl;

       if (result == -1) return result;
      else{
         while((result-1) >=0 && nums [result] == nums[result - 1]){
        result--;
       }
       return result;
      }

    }
    int right_search(int high, int low, int target, vector<int>& nums){
       int result = binary_search(high, low, target, nums);
       if (result == -1) return result;
       else {
        while((result + 1) < nums.size() && nums [result] == nums[result + 1] ){
        result++;
       }
       return result;
       }
      

    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        vector<int> solution = {-1, -1};
        if (nums.empty()) return {-1, -1};
        else if (high < 1){
            if (nums[0] == target) return{0, 0};
            else return solution;
        }
        else{
            solution[0] = left_search(high, 0, target, nums);
            solution[1] = right_search(high, 0, target, nums);
            
            }
       return solution;
    }
};