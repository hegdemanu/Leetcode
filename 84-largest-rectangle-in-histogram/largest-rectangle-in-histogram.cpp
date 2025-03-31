class Solution {
    vector<int> prevsmaller(vector<int>& heights, int n){
        vector<int> mark(n,0);
        stack<int>  st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                st.pop();  
            }
            if(!st.empty()) mark[i] = st.top();
            else mark[i] = -1;
            st.push(i); 
         }
         return mark;
    }
    vector<int> nextgreater(vector<int>& heights, int n){
        vector<int> mark(n,0);
        stack<int>  st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();   
            }
            if(!st.empty()) mark[i] = st.top();
            else mark[i] = n;
            st.push(i);
        }
        return mark;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 1) return heights[0];
        stack<int>  st;
        vector<int> next = nextgreater(heights, n);
        vector<int> prev = prevsmaller(heights, n);
        int area = 0;
        int maxarea = 0;
        for(int i = 0; i < n; i++){
            area = (next[i] - prev[i] - 1)*(heights[i]);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};