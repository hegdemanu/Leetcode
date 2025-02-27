//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  bool canWePlaceCows(vector<int> &stalls, int k, int mid){
      int cowCnt = 1; int lastPos = stalls[0];// cows placed and last pos
      int n = stalls.size();
      for (int i = 1; i < n; i++){
        //   lastCnt = min(stalls[i] - stalls[i - 1], lastCnt);
          if ((stalls[i] - lastPos) >= mid){
              cowCnt++;
              lastPos = stalls[i];
          }
          if (cowCnt >= k) return true;
      }
      return 0;
  }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int h = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
        int l = 1;
        // canWePlaceCows(stalls,k, mid)
        while(l <= h){
            int mid = l + (h - l) / 2;
            if (canWePlaceCows(stalls,k, mid)) l = mid + 1;
            else h = mid - 1;
        }
        return h;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends