class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool> numsMap;
        int longestseq = 0;
        int seq = 0;
        int present;
        
        for (int i=0; i<nums.size(); i++){
            numsMap[nums[i]] = true;
        }
        
        // iterate across all nums
        for (int i = 0; i<nums.size(); i++){
            
            if (numsMap[nums[i]-1] == true){
                continue;
            }
            
            // check if currrent num's preceding number is present
            // if yes, continue without any operation
            // if no
                // loop for finding the size of sequence the current number can begin to form
            
            seq = 1;
            present = nums[i] + 1;
            while(numsMap[present] == true){
                seq++;
                present++;
            }
            
            longestseq = max(seq, longestseq);
        }
        
        return longestseq;
    }
};