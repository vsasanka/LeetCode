class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if (nums.size() == 1){
            return true;
        }
        
        if (nums[0] == 0){
            return false;
        }
        
        // vector<int> range(nums.size(), 0);
        // range[0] = 1;
        int sofar = 0;
        
        for (int i=0; i<nums.size(); i++){
            
//             cout << range[i] << " ";
            
//             if (range[i] == 0){
//                 return false;
//             }
            
            if (sofar < i){
                return false;
            }
            
            // for (int j=i+1; j<=i+nums[i]; j++){
            //     range[j] = 1;
            //     if (j == nums.size() - 1){
            //         return true;
            //     }
            // }
            
            sofar = max(sofar, i+nums[i]);
            
            if (sofar >= nums.size() - 1){
                return true;
            }
        }
        
        return false;
    }
};

/*

1 1 0 0 

*/