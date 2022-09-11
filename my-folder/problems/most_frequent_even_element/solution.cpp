class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> freven;
        int maxe = -1;
        int maxi = -1;
        
        for (int i=0; i<nums.size(); i++){
            if (nums[i]%2 == 0){
                freven[nums[i]]++;
                if (freven[nums[i]] > maxe){
                    maxe = freven[nums[i]];
                    maxi = i;
                }
                else if (freven[nums[i]] == maxe && nums[i] < nums[maxi]){
                    maxi = i;
                    continue;
                }
            }
        }
        if (maxe == -1) return -1;
        return nums[maxi];
    }
};