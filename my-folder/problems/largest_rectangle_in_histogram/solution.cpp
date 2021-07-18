class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        
        stack<int> nums;
        
        for (int i=0; i<n; i++){
            if (nums.empty()){
                left[i] = -1;
            }
            else{
                while(!nums.empty() && heights[nums.top()] >= heights[i]){
                    nums.pop();
                }
                
                if (nums.empty()){
                    left[i] = -1;
                }
                else{
                    left[i] = nums.top();
                }
            }
            
            nums.push(i);
        }
        
        while(!nums.empty()){
            nums.pop();
        }
        
        for (int i=n-1; i>=0; i--){
            if (nums.empty()){
                right[i] = n;
            }
            else{
                while(!nums.empty() && heights[nums.top()] >= heights[i]){
                    nums.pop();
                }
                
                if (nums.empty()){
                    right[i] = n;
                }
                else{
                    right[i] = nums.top();
                }
            }
            
            nums.push(i);
        }
        
        int area = 0;
        
        for (int i=0; i<n; i++){
            area = max(area, (right[i] - left[i] - 1)*heights[i]);
        }
        
        return area;
    }
};