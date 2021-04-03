class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n);
        
        int i,j,k;
        
        i=0;
        j=0;
        k=0;
        
        while(i<m && j<n){
            if (nums1[i]<nums2[j]){
                nums3[k]=nums1[i];
                i++;
                k++;
            }
            else{
                nums3[k]=nums2[j];
                j++;
                k++;
            }
        }
        
        while(i<m){
            nums3[k] = nums1[i];
            i++;
            k++;
        }
        
        while(j<n){
            nums3[k] = nums2[j];
            j++;
            k++;
        }
        
        for (int a=0;a<m+n;a++){
            nums1[a]=nums3[a];
        }
    }
    
};