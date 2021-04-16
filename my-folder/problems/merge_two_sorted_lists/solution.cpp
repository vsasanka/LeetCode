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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* h1=l1;
        ListNode* h2=l2;
        ListNode* head;
        
        if (h1==NULL){
            return h2;
        }
        
        if (h2==NULL){
            return h1;
        }
        
        head = l1;
        
        while( h1!=NULL && h2!=NULL){
            if (h1->val <= h2->val){
                if (h1->next!= NULL && h1->next->val > h2->val){
                    ListNode* temp = h1->next;
                    ListNode* temp2 = h2->next;
                    h1->next = h2;
                    h2->next = temp;
                    h2 = temp2;
                    h1 = h1->next;
                    
                }
                else if (h1->next==NULL){
                    h1->next = h2;
                    break;
                }
                else{
                    h1 = h1->next;
                }
            }
            else{
                if (h2->next!=NULL){
                    /*
                    ListNode* temp = h2->next;
                    ListNode* temp2 = h1->next;
                    h2->next = h1;
                    h1->next = temp;
                    h1 = temp2;
                    h2 = h2->next;
                    */
                    
                    ListNode* temp = h2->next;
                    
                    h2->next = h1;
                    h1 = h2;
                    h2 = temp;
                    
                    head = h1;
                    
                }
                else if (h2->next==NULL){
                    h2->next = h1;
                    head = h2;
                    break;
                }/*
                else{
                    h2 = h2->next;
                }*/
            }
        }
        
        return head;
    }
};