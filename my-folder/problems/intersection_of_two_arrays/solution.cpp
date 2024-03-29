class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()){
            
            if (i+1 < nums1.size() && nums1[i]==nums1[i+1]){
                i++;
                continue;
            }
            
            if (j+1 < nums2.size() && nums2[j]==nums2[j+1]){
                j++;
                continue;
            }
            
            if (nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        
        return ans;
    }
};