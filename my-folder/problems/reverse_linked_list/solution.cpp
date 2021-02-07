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
    ListNode* reverseLink(ListNode* prev, ListNode* curr){
        
        ListNode* head_new;
        if (curr->next==NULL){
            curr->next = prev;
            return curr;
        }
        else{
            head_new = reverseLink(prev->next,curr->next);
            curr->next = prev;
            return head_new;
        }
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        
        if (head==NULL){
            return NULL;
        }
        
        if (head->next==NULL){
            return head;
        }
        
        ListNode* head_new = reverseLink(head, head->next);
        
        head->next = NULL;
        
        return head_new;
    }
};