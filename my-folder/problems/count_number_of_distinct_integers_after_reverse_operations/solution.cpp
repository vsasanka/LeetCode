class Solution {
    
private:
    bool isPalindromeNum(int num){
        int newNum = 0;
        
        while (num){
            newNum *= 10;
            newNum += num%10;
            num /= 10;
        }
        
        if (newNum == num){
            return true;
        }
        return false;
    }
    
public:
    int countDistinctIntegers(vector<int>& nums) {
        int count = 0;
        
        for (int i=nums.size()-1; i>=0; i--){
            int num = nums[i];
            
//             if (nums[i]%10 == 0){
//                 while(num%10 == 0) num /= 10;
                
//                 int newNum = 0;
//                 while (num){
//                     newNum *= 10;
//                     newNum += num%10;
//                     num /= 10;
//                 }
                
//                 if (find(nums.begin(),nums.end(), num) == nums.end()){
//                     cout << nums[i] << endl;
//                     count += 2;
//                 }
//                 else{
//                     count += 1;
//                 }
//             }
//             else if (!isPalindromeNum(nums[i])){
//                 cout << nums[i] << endl;
//                 count += 2;
//             }
            
            int newNum = 0;
            while (num){
                newNum *= 10;
                newNum += num%10;
                num /= 10;
            }
            
            nums.push_back(newNum);
        }
        
        unordered_map<int,int> freq;
        
        count = nums.size();
        
        for (int i=0; i<nums.size(); i++){
            // cout << nums[i] << " ";
            freq[nums[i]]++;
            if (freq[nums[i]] > 1){
                count--;
                freq[nums[i]] = 1;
            }
        }
        
        return count;
    }
};