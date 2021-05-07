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
    ListNode* oddEvenList(ListNode* head) {
        
        if (head==NULL){
            return head;
        }
        
        ListNode* last=head;
        int count=1;
        while(last->next!=NULL){
            last = last->next;
            count++;
        }
        
        if (count<3){
            return head;
        }
        
        ListNode* prev, *curr;
        
        prev = head;
        curr = head->next;
        
        for(int i=0;i<count/2;i++){
            last->next = curr;
            prev->next = curr->next;
            prev = prev->next;
            
            curr = prev->next;
            last = last->next;
            last->next = NULL;
        }
        
        return head;
    }
};