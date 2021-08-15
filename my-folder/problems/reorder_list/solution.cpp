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
    void reorderList(ListNode* head) {
        ListNode* fast;
        ListNode* slow;
        slow = fast = head;
        
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (slow->next == NULL){
            return ;
        }
        
        ListNode* h1 = head;
        ListNode* h1next = head->next;
        
        ListNode* h2 = slow->next;
        ListNode* h2next = h2->next;
        ListNode* h2prev = NULL;
        
        slow->next = NULL;
        
        while(true){
            
            if (h2next == NULL){
                h2->next = h2prev;
                break;
            }
            
            h2->next = h2prev;
            
            h2prev = h2;
            h2 = h2next;
            h2next = h2next->next;
        }
        
        h2next = h2->next;
        
        while(true){
            if (h2next == NULL){
                h1->next = h2;
                h2->next = h1next;
                break;
            }
            h1->next = h2;
            h2->next = h1next;
            
            h1 = h1next;
            h1next = h1next->next;
            
            h2 = h2next;
            h2next = h2next->next;
        }
        
        
    }
};