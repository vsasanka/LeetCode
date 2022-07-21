class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefsum;
        int count = 0;
        int sum = 0;
        prefsum[0] = 1;
        
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            if (prefsum[sum - goal] != 0){
                count += prefsum[sum - goal];
            }
            prefsum[sum]++;
        }
        
        return count;
    }
};

/*

1 0 1 1 1 0 0 0 1 1 1 0 0

1 1 2 3 4 4 4 4 5 6 7 7 7 

1 0 1 0 1    2

1 2
2 2    2


*/