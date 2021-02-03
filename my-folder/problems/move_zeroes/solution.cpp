class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1,p2;
        
        p1 = 0;
        p2 = 0;
        
        int len = nums.size();
        
        while (p2<len){
            if (nums[p1]!=0){
                p1++;
                p2++;
            }
            else{
                while(p2<len){
                    if (nums[p2]!=0){
                        int temp = nums[p1];
                        nums[p1] = nums[p2];
                        nums[p2] = temp;
                        p1++;
                        p2++;
                        break;
                    }
                    p2++;
                }
            }
        }
    }
};