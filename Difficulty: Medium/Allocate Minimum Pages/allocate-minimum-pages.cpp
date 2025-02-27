//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int bookAllocation(vector<int> &arr, int k, int mid, int n){
        int sCnt = 1; int pageCnt = 0;
        for(int i = 0; i < n; i++){
            if (pageCnt + arr[i] <= mid) pageCnt += arr[i];
            else {
                pageCnt = arr[i];
                sCnt++;
                if (sCnt > k) return sCnt;
            };
        }
        return sCnt;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int l = *max_element(arr.begin(), arr.end());
        if(n < k) return -1;
        if (n == k) return l;
        int r = accumulate(arr.begin(), arr.end(), 0);
        if (n == 1) return r;
        while(l <= r){
            int mid = l + (r - l)/ 2;
            int s = bookAllocation(arr, k, mid, n);
            
            // if(s == k) mid;
            // else 
            if(s > k) l = mid + 1;
            else r = mid - 1;
            
        }
        return l;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends