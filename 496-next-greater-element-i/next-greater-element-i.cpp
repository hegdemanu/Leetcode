class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> mark(size2, 0);
        vector<int> mark2(size1, -1);
        unordered_map <int,int> map;
        stack<int> st;
        for(int i = size2 - 1; i >= 0; i--){
                while(!st.empty() && nums2[i] >= st.top()){
                    st.pop();
                }
            if(!st.empty() && st.top() > nums2[i]){
                mark[i] = st.top();
                }
            else if(st.empty()) mark[i] = -1;
            for(int j = size1 - 1; j >= 0; j--){
                if(nums1[j] == nums2[i]){
                   mark2[j] = mark[i];
                }
            }
            st.push(nums2[i]);
        }
        for(int i = size2 - 1; i >= 0; i--){
            
        }
        return mark2;
    }
};