class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperature) {
        int n = temperature.size();
        stack<int> st;
        vector<int> mark(n, 0);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && temperature[st.top()] <= temperature[i]){
                st.pop();
            }
            if(!st.empty()) mark[i] = st.top() - i;
            st.push(i);
        }
        return mark;
    }
};