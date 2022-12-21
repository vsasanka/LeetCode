class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        
        for (int i=0; i<n; i++){
            if (asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                    continue;
                }
                
                while (!st.empty() && st.top() > 0){
                    if (st.top() < abs(asteroids[i])){
                        st.pop();
                        if (st.empty() || (!st.empty() && st.top() < 0)) st.push(asteroids[i]);
                    }
                    else if (st.top() == abs(asteroids[i])){
                        st.pop();
                        break;
                    }
                    else{
                        break;
                    }
                    
                }
            }
        }
        
        vector<int> ans;
        
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};