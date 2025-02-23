class Solution {
public:
void merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if (nums[left] <= nums[right]){
            temp.emplace_back(nums[left]);
            left++;
        }
        else{
            temp.emplace_back(nums[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.emplace_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.emplace_back(nums[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}
    void mergesort(vector<int>& nums, int low, int high){
        if (low >= high)return;
        int mid = (low + high)/2 ;
        mergesort(nums, low, mid);
        mergesort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        mergesort(nums,low, high);
        return nums;
    }
};