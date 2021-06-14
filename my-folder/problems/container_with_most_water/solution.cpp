class Solution {
public:
    int maxArea(vector<int>& height) {
        int left, right;
        left = 0;
        right = height.size()-1;
        int maxa = 0;
        
        while( left < right){
            if (height[left] < height[right]){
                maxa = max(maxa, height[left]*(right - left));
                left++;
            }
            else{
                maxa = max(maxa, height[right]*(right - left));
                right--;
            }
        }
        
        return maxa;
    }
};