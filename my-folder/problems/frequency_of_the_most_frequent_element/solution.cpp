class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        long long sum = 0;
        int l = 0, r = 0;
        int maxLen = 0;
        
        sort(nums.begin(), nums.end());
        
        while (l < nums.size() && r < nums.size()){
            sum += nums[r];
            
            if ((long long)nums[r]*(r-l+1) <= sum + k){
                maxLen = max(maxLen, (r-l+1));
            }
            else{
                sum -= nums[l];
                l++;
            }
            r++;
        }
        
        return maxLen;
    }
};

/*
k = 7
50 - 23
43 - 20
42 - 19
47 - 19

*/