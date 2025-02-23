class Solution {
public:
    int countPrimes(int n) {
         if (n <= 2) return 0;
     vector<bool> v(n, true);  // Correct vector initialization syntax
        v[0] = v[1] = false;
        
        for (int i = 2; i * i < n; i++) {  // Start i from 2
        {
            if (v[i])
            {
                for (int j = i * i; j < n; j += i)  // Declare j as int
                {
                    v[j] = false;
                }
            }
        }
        
    } 
    return count(v.begin(), v.end(), true);
    }
    };