class Solution {
    
private:
    /*int recursion(left_lim, right_lim){
        if (sumarray[right_lim] - sumarray[left_lim] + nums[left_lim] == target){
            return min(minima, minima)
        }
    }*/
    
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        vector<int> sumarray;
        int sum = 0;
        
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            sumarray.push_back(sum);
        }
        
        int forward = 0, back = 0, localsum = 0;
        int minlen = INT_MAX;
        
        while (forward < sumarray.size() && back < sumarray.size()) {
            localsum = sumarray[forward] - sumarray[back] + nums[back];
            if (localsum < target){
                forward++;
            }
            else{
                minlen = min(minlen, forward - back + 1);
                back++;
            }
        }
        
        if (minlen == INT_MAX){
            return 0;
        }
        
        return minlen;
    }
};

/*

2 5 6 8 12 15

2
5
6
8
6
10

*/