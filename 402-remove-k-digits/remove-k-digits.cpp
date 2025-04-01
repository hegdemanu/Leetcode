class Solution {
public:
    string removeKdigits(string num, int k) {
       int n = num.size();
       stack<char> st;
       string mark;
       int cnt = 0;
       for(int i = 0; i < n; i++){
        while(!st.empty() && k > 0 && num[i] < st.top()){
            st.pop();
            k--;
        }
            st.push(num[i]);
        }
            while(!st.empty() && k > 0){
            st.pop();
            k--;
            }
            while(!st.empty()){
                mark+=st.top();
                st.pop();
            }
            reverse(mark.begin(), mark.end());
            if(mark.empty()){
                mark += '0';
                return mark;

            }
            else{
                int cnt = 0;
               for(int i = 0; i < mark.size(); i++){
                 if(mark[i] == '0'){
                   ++cnt;
                 }
                 else break;
                }
                cout<<cnt;
                if(cnt != 0) mark.erase(0,cnt);
            }
            if(mark.empty()){
                mark += '0';
                return mark;

            }
            return mark;
    }
};