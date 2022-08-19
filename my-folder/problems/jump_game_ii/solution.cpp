class Solution {
    
private:
    int prevJump(vector<int>& nums, int end){
        for (int i=0; i<end; i++){
            if (nums[i] >= (end - i)){
                return i;
            }
        }
        
        return end - 1;
    }
    
public:
    int jump(vector<int>& nums) {
        
        int jumpcount = 0;
        int jumpindex = nums.size() - 1;
        
        while(jumpindex > 0){
            jumpindex = prevJump(nums, jumpindex);
            jumpcount++;
        }
        
        return jumpcount;
    }
};