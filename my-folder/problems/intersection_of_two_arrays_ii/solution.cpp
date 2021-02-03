class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        hash_parent, hash_child
        
        for (iterate array parent){
            if (nums1[i] present in hash_parent){
                hash_parent[nums1[i]]++;
            }
            else{
                hash_parent.add(nums[i]);
            }
        }
        
        for (iterate array child){
            if (nums2[i] present in hash_parent){
                ans.push_back();
                hash_parent[nums1[i]]--;
                if (hash_parent[nums1]==0){
                    hash_parent.remove(nums1[i]);
                }
            }
        }
        
        
        
        */
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> ans;
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int i,j;
        i=0;
        j=0;
        
        while(i<len1 && j<len2){
            if (nums1[i]>nums2[j]){
                j++;
            }
            else if (nums1[i]<nums2[j]){
                i++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return ans;
    }
};