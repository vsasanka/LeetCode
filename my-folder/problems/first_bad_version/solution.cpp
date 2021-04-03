// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l,r;
        l = 0;
        r = n-1;
        
        while(true){
            int mid = l + (r-l)/2;
            
            if (isBadVersion(mid)){
                if ((mid-1<0) || isBadVersion(mid-1)==false){
                    return mid;
                }
                else{
                    r = mid-1;
                    continue;
                }
            }
            else{
                if (isBadVersion(mid+1)){
                    return mid+1;
                }
                else{
                    l = mid+1;
                    continue;
                }
            }
        }
    }
};