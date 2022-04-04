/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1, r = n;
        int temp;
        while (l<=r){
            temp = l + (r-l)/2;
            
            if (guess(temp)==-1){
                r = temp - 1;
            }
            else if (guess(temp)==1){
                l = temp + 1;
            }
            else{
                return temp;
            }
        }
        return 0;
    }
    
};