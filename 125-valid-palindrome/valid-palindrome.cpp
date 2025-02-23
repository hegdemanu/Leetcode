class Solution {
public:
bool helper(string &s, int i, int j){
    if(i >= j) return 1;
    else if(!isalnum(s[i]))return helper(s, i+1, j);
    else if(!isalnum(s[j]))return helper(s, i, j-1);
    else if(tolower(s[i]) != tolower(s[j]))return false;
    else return helper(s, i+1, j-1);

}
    bool isPalindrome(string s) {
        return helper(s, 0, s.size()-1);
    }
};