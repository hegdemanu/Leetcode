class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row = m[0].size();
        int col = m.size();
        int x = 1;
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if (m[i][j] == 0) {
                    m[i][0] = 0;
                    if (j != 0) {
                        m[0][j] = 0;
                    } else
                        x = 0;
                }
            }
        }
        for (int i = 1; i < col; i++) {
            for (int j = 1; j < row; j++) {
                if (m[i][j] != 0) {
                    if ((m[0][j] == 0) || (m[i][0] == 0)) {
                        m[i][j] = 0;
                    }
                }
            }
        }
        if(m[0][0] == 0) {
              for (int i = 0; i < row; i++) m[0][i]=0;
        }
          if(x==0){
             for (int i = 0; i < col; i++) m[i][0]=0;
        }
    }
};