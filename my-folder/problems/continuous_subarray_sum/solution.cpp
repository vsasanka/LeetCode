class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        vector<int> prefix(nums.size(), 0);
        
        prefix[0] = nums[0];
        
        if (nums.size() == 1){
            return false;
        }
        
        for (int i=1; i<prefix.size(); i++){
            prefix[i] = prefix[i-1] + nums[i];
            // cout << prefix[i] << " ";
        }
        
        // cout << endl;
        
        mp[0] = -1;
        
        for (int i=0; i<prefix.size(); i++){
            if (mp.find(prefix[i]%k) != mp.end()){
                if (i - mp[prefix[i]%k] > 1) return true;
            }
            else{
                mp[prefix[i]%k] = i;
            }
        }
        
        return false;
    }
};

// 23 25 31 35 42