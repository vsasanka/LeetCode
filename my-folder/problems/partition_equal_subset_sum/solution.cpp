class Solution {

private:
    bool recursion(int i, int sum1, int sum2, vector<int> &nums, map<int, int> &dp){
        if (i == nums.size()){
            if (sum1 == sum2) return true;
            return false;
        }
        
        bool a1 = recursion(i+1, sum1 + nums[i], sum2, nums, dp);
        if (a1) return true;
        bool a2 = recursion(i+1, sum1, sum2 + nums[i], nums, dp);
        if (a2) return true;
        
        dp[i] = a1 || a2;
        
        return dp[i];
    }
    
public:
    bool canPartition(vector<int>& nums) {
        
        set<int> dp;
        set<int>::reverse_iterator si;
        unordered_set<int> tempSet;
        
        dp.insert(0);
        
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        if (sum%2 == 1){
            return false;
        }
        
        sum /= 2;
        
        for (int n : nums){
            set<int> set2;
            
            for (si = dp.rbegin(); si != dp.rend(); si++){
                set2.insert(*si + n);
                if (*si + n == sum) return true;
            }
            
            for (auto num : set2){
                dp.insert(num);
            }
            
            set2.clear();
        }
        
        return false;
    }
};