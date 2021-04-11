class Solution {
    
private:
    void shift(vector<int>& nums, int start, int offset){
        for (int i=start; i<nums.size()-offset;i++){
            nums[i] = nums[i+offset];
        }
    }
    
public:
    int removeDuplicates(vector<int>& nums) {
        int rep,uniquep;
        uniquep=0;
        rep=0;
        int val=1;
        
        if (nums.size()==0){
            return 0;
        }
        
        for (int i=1;i<nums.size();i++){
            if (nums[i]<nums[uniquep]){
                return val;
            }
            else if (nums[i]==nums[uniquep]){
                rep++;
            }
            else if(rep!=0){
                shift(nums, uniquep+1, rep);
                rep=0;
                uniquep++;
                i = uniquep;
                val++;
            }
            else{
                uniquep = i;
                val++;
            }
        }
        
        return val;
    }
};