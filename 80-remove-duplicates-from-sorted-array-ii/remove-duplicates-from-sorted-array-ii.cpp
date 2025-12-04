class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if (arr.size() <= 2) return arr.size();
        int slow = 2, fast = 2;
    while (fast < arr.size()) {
        if ((arr[fast] != arr[slow-2])) {
            arr[slow] = arr[fast];
            slow++;
        }
        fast++;
}
        return slow;
    }  
};