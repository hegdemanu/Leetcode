class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector < int > mpp(256, -1);
        int n = s.size();
        int j = 0;
        int maxi = 0;
        for (int i = 0; i < n; i ++){
            // mpp.push_back(s[i], i);
            if (mpp[s[i]] != -1)
                j = max(mpp[s[i]] + 1, j);
                mpp[s[i]] = i;
                maxi = max(maxi, i - j + 1);
             }
      return maxi;
    }
};
// Let's break down how it works:

// vector<int> mpp(256, -1): Creates a vector to store the last position of each character (using ASCII values as indices)
// j: Keeps track of the start of current window of non-repeating characters
// For each character at position i:

// If we've seen this character before (mpp[s[i]] != -1), we may need to move the window start
// We take max of (mpp[s[i]] + 1, j) to ensure we don't move the window start backwards
// Update the last seen position of current character
// Calculate length of current window (i - j + 1) and update maximum if needed