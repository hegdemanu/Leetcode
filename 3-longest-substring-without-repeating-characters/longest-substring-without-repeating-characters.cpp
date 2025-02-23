class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        // Initialize a vector to track the last occurrence of each ASCII
        // character (256 possible) Each element is initialized to -1,
        // indicating the character hasn't been seen yet
        vector<int> map(256, -1);

        // 'r' (right) and 'l' (left) pointers define the current window of
        // substring
        int r = 0, l = 0;
        // 'len' will store the maximum length of non-repeating substring found
        int len = 0;
        // 'n' is the length of the input string
        int n = s.size();

        // Iterate through each character in the string using the right pointer
        // 'r'
        while (r < n) {
            // Check if the current character has been seen before (i.e., its
            // last occurrence is not -1)
            if (map[s[r]] != -1) {
                // Update the left pointer to be the maximum of its current
                // position or one position after the last occurrence of the
                // current character. This ensures the window contains only
                // unique characters.
                l = max(map[s[r]] + 1, l);
            }

            // Calculate the current window size (r - l + 1) and update 'len' if
            // it's larger
            len = max(len, r - l + 1);

            // Record the current index 'r' as the last occurrence of the
            // character s[r]
            map[s[r]] = r;

            // Move the right pointer to the next character
            r++;
        }

        // Return the maximum length of non-repeating substring found
        return len;
    }
};
