/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
private:
    bool isArrayPalindrome(vector<int>& array){
        int len = array.size();
        
        for (int i=0;i<len/2;i++){
            if (array[i]!=array[len-1-i]){
                return false;
            }
        }
        
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* curr=head;
        vector<int> array;
        
        while(curr!=NULL){
            array.push_back(curr->val);
            curr = curr->next;
        }
        
        return isArrayPalindrome(array);
    }
};