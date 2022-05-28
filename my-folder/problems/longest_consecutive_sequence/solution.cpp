class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> record(nums.begin(), nums.end());
        int res = 0;
        
        for (auto n: nums){
            if (record.find(n)==record.end()) continue;
            
            int prev=n-1, next=n+1;
            
            while (record.find(prev)!=record.end()) record.erase(prev--);
            while (record.find(next)!=record.end()) record.erase(next++);
            
            res = max(res, next - prev - 1);
        }
        
        return res;
    }
};