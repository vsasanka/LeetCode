class Solution {
public:
    int trap(vector<int>& height) {
        
        if (height.size()==0){
            return 0;
        }
        
        int i = 0, j = height.size() - 1;
        int water = 0;
        int left_max = height[i], right_max = height[j];
        // i++,j--;
        
        while (i<j){
            if (left_max < right_max){
                i++;
                if (left_max > height[i]){
                    water += left_max - height[i];
                }
                else{
                    left_max = height[i];
                }
            }
            else{
                j--;
                
                if (right_max > height[j]){
                    water += right_max - height[j];
                }
                else{
                    right_max = height[j];
                }
            }
        }
        
        return water;
    }
};