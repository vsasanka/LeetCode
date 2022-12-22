class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<int,char>> st;
        
        
        for (int i=0; i<s.size(); i++){
            if (st.empty() || st.top().second != s[i]){
                st.push({1,s[i]});
            }
            else{
                if (st.top().first + 1 == k){
                    st.pop();
                }
                else{
                    int count = st.top().first + 1;
                    st.pop();
                    st.push({count, s[i]});
                }
            }
        }
        
        string ans;
        
        while (!st.empty()){
            ans.append(st.top().first, st.top().second);
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};