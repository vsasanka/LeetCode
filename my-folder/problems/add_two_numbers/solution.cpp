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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* 
        c = 0;
        
        
        
        while (l1 && l2!= null){
            // add l1.val, l2.val, c
            
            ListNode* node1;
            node1.val = l1.val + l2.val + c;
            c = node1.val/10;
            node1.val = node1.val%10;
            
            prev->next = node1;
            prev = node1;
            node1->next= NULL;
        }
        
        while(l1!=NULL){
            ListNode* node1;
            node1.val = l1.val + c;
            c = node1.val/10;
            node1.val = node1.val%10;
            
            prev->next = node1;
            prev = node1;
            node1->next = NULL;
        }
        
        while(l2!=NULL){
        
        }
        
        
        */
        
        if (l1==NULL){
            return l2;
        }
        
        if (l2==NULL){
            return l1;
        }
        
        int c=0;
        
        ListNode* head = new ListNode();
        head->val = l1->val + l2->val;
        c = (head->val)/10;
        head->val = (head->val)%10;
        
        ListNode* prev=head;
        l1=l1->next;
        l2=l2->next;
        
        while(l1!=NULL && l2!=NULL){
            ListNode* node1 = new ListNode();
            node1->val = l1->val + l2->val + c;
            c = (node1->val)/10;
            node1->val = (node1->val)%10;
            
            prev->next = node1;
            prev = node1;
            node1->next = NULL;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL){
            ListNode* node1 = new ListNode();
            node1->val = l1->val + c;
            c = (node1->val)/10;
            node1->val = (node1->val)%10;
            
            prev->next = node1;
            prev = node1;
            node1->next = NULL;
            
            l1= l1->next;
        }
        
        while(l2!=NULL){
            ListNode* node1 = new ListNode();
            node1->val = l2->val + c;
            c = (node1->val)/10;
            node1->val = (node1->val)%10;
            
            prev->next = node1;
            prev = node1;
            node1->next = NULL;
            
            l2= l2->next;
        }
        
        if (c==1){
            ListNode* node1 = new ListNode();
            node1->val = c;
            
            prev->next = node1;
            node1->next = NULL;
        }
        
        return head;
    }
};