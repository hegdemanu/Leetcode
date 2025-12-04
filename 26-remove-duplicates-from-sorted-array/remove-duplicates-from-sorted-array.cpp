class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
    int slow = 0, fast = 1;
    if (arr.size() == 0) return 0;
    while (fast < arr.size()) {
        if ((arr[slow] != arr[fast])) {
            slow++;
             arr[slow] = arr[fast];
             
        }
        fast++;
}
        return slow+1;        
    }
};