class Solution {
public:
    vector<int> gen_row(int n, vector<vector<int>> &answer) {
        if(n == 0 || n == 1) {
            vector<int> temp(n + 1, 1);
            return temp;
        }
        vector<int> temp(n + 1, 1);
        for(int i = 1; i < n; i++) {
            temp[i] = answer[n - 1][i - 1] + answer[n - 1][i];
        }
        return temp;
    }
    
    vector<vector<int>> generate(int n) {
        // Initialize without size to avoid empty rows
        vector<vector<int>> answer;
        
        for(int i = 0; i < n; i++) {
            vector<int> temp = gen_row(i, answer);
            answer.push_back(temp);
        }
        return answer;
    }
};