// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int n = s.size() - 1;
        for (int i = 0; i <= n/2; i++){
        swap(s[n-i],s[i]);
        }
        return s;
    }
};
