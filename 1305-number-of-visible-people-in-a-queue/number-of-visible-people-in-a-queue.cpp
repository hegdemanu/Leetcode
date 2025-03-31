class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> mark(n , 0);
        for(int i = n - 1; i >= 0; i--){
            int cansee = 1;
            while(!st.empty() && st.top() < heights[i]){
                st.pop();
                cansee ++;
            }
            if(!st.empty()){
                mark[i] = cansee;
                }
            else mark[i] = --cansee;
            
            st.push(heights[i]);
        }
        mark[n - 1] = 0;
        return mark;
    }
};