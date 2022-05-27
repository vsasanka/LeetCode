class Solution {
    
private:
    bool check(vector<int>& nums1, vector<int>& nums2, long long midval, long long k){
        long long val;
        long long int cnt=0;
        
        for (int i=0; i<nums1.size(); i++){
            val = nums1[i];
            
            if (val==0 and midval>=0){
                cnt += nums2.size();
            }
            
            else if(val>0){
                cnt += findminIndex(nums2, val, midval);
            }
            else if (val<0){
                cnt += findmaxIndex(nums2, val, midval);
            }
        }
        
        return cnt >= k;
    }
    
    int findminIndex(vector<int>& nums2, long long val, long long midval){
        
        int l = 0, r = nums2.size() - 1, res = -1;
        long long mid;
        
        while (l <= r){
            mid = (l + r)/2;
            
            if (val*nums2[mid] <= midval){
                res = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return res + 1;
    }
    
    int findmaxIndex(vector<int>& nums2, long long val, long long midval){
        
        long long l = 0, r = nums2.size() - 1, mid, res = nums2.size();
        
        while (l <= r){
            mid = (l + r)/2;
            
            if (val*nums2[mid] <= midval){
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return nums2.size() - res;
    }
    
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10, r = 1e10, mid, res=-1;
        
        while (l<=r){
            mid = (l+r)/2;
            
            if (check(nums1, nums2, mid, k)){
                res = mid;
                r = mid -1;
            }
            else l = mid + 1;
        }
        
        return res;
    }
};