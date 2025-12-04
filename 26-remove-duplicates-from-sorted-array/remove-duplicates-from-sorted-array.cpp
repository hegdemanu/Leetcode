class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int s1 = n.size();
        int sol = 0;
        int i = 1;
        int j = 0;
        for(int i = 0; i < s1; i++){
            while(n[i] != n[j]){
                j++;
                n[j] = n[i];
            }
        }
        return j+1;
        }
};