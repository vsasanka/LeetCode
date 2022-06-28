class NumArray {
public:
    vector<int> nums;
    vector<int> contSum;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        contSumArray(nums);
    }
    
    void contSumArray(vector<int>&nums){
        int elem = 0;
        
        for (int i=0; i<nums.size(); i++){
            elem += nums[i];
            contSum.push_back(elem);
        }
    }
    
    int sumRange(int left, int right) {
        
        return contSum[right] - contSum[left] + nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */