class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> reminders;
        reminders[0] = 1;
        int count = 0;
        int sum = 0;
        int rem;
        
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            rem = (sum%k + k)%k;
            
            if (reminders[rem] != 0){
                count += reminders[rem];
            }
            
            reminders[rem]++;
            
            // cout << rem << " ";
        }
        
        return count;
    }
};