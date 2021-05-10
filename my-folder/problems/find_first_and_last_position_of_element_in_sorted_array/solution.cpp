class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        
        if (nums.size()==0){
            return res;
        }
        
        int i,j;
        i = 0;
        j = nums.size()-1;
        int mid;
        
        while (i<j){
            mid = i + (j-i)/2;
            
            if (nums[mid]<target){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        
        if (nums[i]==target){
            res[0] = i;
        }
        
        i = 0;
        j = nums.size()-1;
        
        while(i<j){
            mid = i + (j-i)/2 + 1;
            
            if (nums[mid]<=target){
                i = mid;
            }
            else{
                j = mid-1;
            }
        }
        
        if (nums[i]==target){
            res[1]=i;
        }
        
        return res;
    }
};

// 5 7 7 8 8 10

// 