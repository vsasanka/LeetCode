class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        // fix first number and search for second
            // if second finds a number less than first -> bring first and second to second
            // if second finds a greater number than first -> fix the second number and search for 3rd
                // if third finds a number > second -> return true;
                // if third finds a number < second and > first -> bring second and third to 2nd, go on
        
        // return false
        if (nums.size()<3){
            return false;
        }
        
        int j,k;
        for (int i=0;i<nums.size();i++){
            j = i+1;
            k = i+1;
            while (j<nums.size() && k<nums.size()){
                if (nums[j]<=nums[i]){
                    i =j;
                    j++;
                }
                else{
                    k = j+1;
                    while(k<nums.size()){
                        if (nums[k]>nums[j]){
                            // cout << nums[i] << " " << nums[j] << " " << nums[k];
                            return true;
                        }
                        else if(nums[k]>nums[i] && nums[k]<=nums[j]){
                            j = k;
                        }
                        k++;
                    }
                }
            }
        }
        
        return false;
    }
};