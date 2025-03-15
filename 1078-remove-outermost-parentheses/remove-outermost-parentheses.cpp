class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int l = 0, r = 0, cnt = 0;
        int n = s.length();

        while (r < n) {
            if (s[r] == '(') {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt == 0) {  // Found a complete primitive
                ans += s.substr(l + 1, r - l - 1);  // Extract inner content
                l = ++r;  // Move to the next primitive
            } else {
                r++;
            }
        }
        return ans;
    }
};
