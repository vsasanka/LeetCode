class Solution {
    vector<vector<int>> result;
    
private:
    void recursion(vector<int>& nums, int index){
        
        if (index==nums.size()){
            result.push_back(nums);
            return ;
        }
        
        for (int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recursion(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        recursion(nums, 0);
        
        return result;
    }
};