class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0, j = 0;
        int numZeros = 0;
        int ans = 0;
        
        while (j < nums.size()){
            if (nums[j] == 0) numZeros++;
            
            if (numZeros <= k){
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                if (nums[i] == 0) numZeros--;
                i++; j++;
            }
        }
        
        return ans;
    }
};