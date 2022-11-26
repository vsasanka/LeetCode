class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int> s1, s2;
        int n = arr.size();
        vector<int> next_small(n);
        vector<int> prev_small(n);
        int MOD = 1000000007;
        
        for (int i=0; i<n; i++){
            next_small[i] = n-i-1;
            prev_small[i] = i;
        }
        
        for (int i=0; i<n; i++){
            while (!s1.empty() && arr[i] < arr[s1.top()]){
                next_small[s1.top()] = i - s1.top() - 1;
                s1.pop();
            }
            s1.push(i);
        }
        
        for (int i=n-1; i>=0; i--){
            while (!s2.empty() && arr[i] <= arr[s2.top()]){
                prev_small[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }
            s2.push(i);
        }
        
        long sum = 0;
        
        for (int i=0; i<n; i++){
            sum += (long)(next_small[i]+1)*(prev_small[i]+1)*arr[i];
            sum %= MOD;
        }
        
        return (int)sum;
    }
};