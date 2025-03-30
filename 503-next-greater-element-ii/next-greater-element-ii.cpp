class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int ni = nums.size();
    vector<int> mark(ni, 0);
    stack<int> st;
    for(int i = ni - 1; i >=0; i--){
        st.push(nums[i]);
    }
    for(int i = ni - 1; i >=0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(!st.empty() && st.top() > nums[i]) mark[i] = st.top();
        else mark[i] = -1;
        st.push(nums[i]);
    }
    return mark;
    }
};