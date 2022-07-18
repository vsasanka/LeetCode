class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = 0;
        int num = nums.size();
        
        vector<int> count(2*num + 1, -1);
        count[num] = 0;
        int sum = 0;
        
        for (int i=0; i<num; i++){
            sum += nums[i]==1 ? 1:-1;
            
            if (sum == 0){
                len = max(len, i+1);
            }
            else if (count[sum + num] != -1){
                len = max(len, i - count[sum + num]);
            }
            else{
                count[sum + num] = i;
            }
        }
        
        return len;
    }
};

/*

0 1 1 1 1 1 0

6
4
*/