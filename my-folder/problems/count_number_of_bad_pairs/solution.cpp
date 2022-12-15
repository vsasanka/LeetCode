class Solution {
    
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        
        unordered_map<int,int> mp;
        vector<long long>factDP(nums.size(), 1);
        
        
        for (int i=0; i<nums.size(); i++){
            mp[nums[i] - i]++;
        }
        
        for (auto i : mp){
            if (i.second > 1){
                ans += ((long long)(i.second)*(i.second-1))/2;
            }
        }
        
        int n = nums.size();
        
        ans = ((long long)n*(n-1))/2 - ans;
        
        return ans;
    }
};

