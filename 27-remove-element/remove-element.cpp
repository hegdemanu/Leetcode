class Solution {
public:
    int removeElement(vector<int>& n, int v) {
        int index = 0;
        int s1 = n.size();
        for (int i = 0; i < s1; i++){
            if(n[i] != v){
                n[index] = n[i];
                index++;
            }
        }
        return index;
    }
};