class Solution {
    vector<int> Nse(int n, vector<int> m) {
        stack<int> st;
        vector<int> mark(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && m[st.top()]>= m[i]) {
                st.pop();
            }
            if (!st.empty())
                mark[i] = st.top();
            else
                mark[i] = -1;
            st.push(i);
        }
        return mark;
    }
    vector<int> Pse(int n, vector<int> m) {
        stack<int> st;
        vector<int> mark(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && m[st.top()] >= m[i]) {
                st.pop();
            }
            if (!st.empty())
                mark[i] = st.top();
            else
                mark[i] = n;
            st.push(i);
        }
        return mark;
    }
    int greaterarea(int n, vector<int> m) {
        vector<int> pse = Pse(n, m);
        vector<int> nse = Nse(n, m);
        int area = 0;
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            area = (pse[i] - nse[i] - 1) *(m[i]);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix1) {
        int n = matrix1.size();
        int m = matrix1[0].size();
        vector<int> temp(m, 0);
        int area = 0;
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix1[i][j] == '1') {
                    temp[j]++;
                }
                else if(matrix1[i][j] == '0') temp[j] = 0;
                else temp[j] = -1;
            }
            area = greaterarea(m, temp);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};