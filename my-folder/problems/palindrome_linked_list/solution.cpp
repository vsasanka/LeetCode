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
public:
    
    
    bool isPalindrome(ListNode* head) {
        
        // fast, slow pointers
        ListNode* slow;
        ListNode* fast;
        
        slow = fast = head;
        // fast reaches end, slow stands at center
        
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        // use slow as head and reverse list
        
        ListNode* prev;
        ListNode* follow;
        
        prev = NULL;
        follow = slow->next;
        
        while (true){
            if (follow==NULL){
                slow->next = prev;
                break;
            }
            slow->next = prev;
            prev = slow;
            slow = follow;
            follow = follow->next;
        }
        
        // use new slow as head and compare for palindromes
        
        while (head != NULL){
            // cout << head->val << " " << slow->val << endl;
            if (head->val != slow->val){
                return false;
            }
            if (head==slow || head->next==slow){
                break;
            }
            head = head->next;
            slow = slow->next;
        }
        
        return true;
        
    }
};