class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack<int> st;
        int n = nums.size();
        int flag = 0;
        int popedMax = INT_MIN;
        
        for (int i=n-1; i>=0; i--){
            if (flag == 1 && !st.empty() && nums[i] < st.top() && nums[i] < popedMax) return true;
            
            while (!st.empty() && nums[i] > st.top()){
                flag = 1;
                popedMax = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};