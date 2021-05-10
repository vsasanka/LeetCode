class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l,r;
        l = 0;
        r = nums.size()-1;
        int mid;
        
        while(l<=r){
            mid = l + (r-l)/2;
            
            // cout << l << " "<< mid << " " << r << endl;
            
            if (nums[mid]<target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return l;
    }
};
// 1 2 4 5 6 , 7 -> l
// 1 2 4 5 6 , 0 -> l 
// 1 2 4 5 6 , 3
// 1 2 4 5 6 , 4 -> 3

/* while(){
    
    
    // mid == target
    return mid
    // mid < target
        if mid==l
            return l
        else
            adjust l
    // mid > target
    adjust r
}
*/