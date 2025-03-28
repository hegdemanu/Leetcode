class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n%2 == 1)return 0;
        for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()) return 0;
                if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else if(s[i] == '}' && st.top() == '{') st.pop();
                else return false;
            }
        }
        if(st.empty()) return 1;
        return 0;
       }
};