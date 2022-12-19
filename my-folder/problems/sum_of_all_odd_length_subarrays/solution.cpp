class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        
        for (int i=0; i<arr.size(); i++){
            ans += arr[i]*(((i+1)*(n-i)+1)/2);
        }
        
        return ans;
    }
};