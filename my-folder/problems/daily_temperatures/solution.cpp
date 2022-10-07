class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        ans[n - 1] = 0;
        st.push(n-1);
        int days;
        
        for (int i=n-2; i>=0; i--){
            
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            
            if (!st.empty()){
                days = st.top() - i;
            }
            else{
                days = 0;
            }
            
            st.push(i);
            
            ans[i] = days;
        }
        
        return ans;
    }
};