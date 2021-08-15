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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (k == 1){
            return head;
        }
        
        ListNode* left;
        
        ListNode* p0, *p1, *p2;
        
        ListNode *leftin;
        
        p0 = NULL;
        p1 = head;
        p2 = head->next;
        
        left = p0;
        leftin = p1;
        
        int flag = 1;
        
        while(flag){
            
            
            // runs k times
            for (int i=0; i<k; i++){
                // reverse wiring
                p1->next = p0;
                
                if (p2 == NULL){
                    flag = 0;
                    if (i<k-1){
                        flag = 2;
                        for (int j=i; j>=0; j--){
                            p1->next = p2;
                            
                            p2 = p1;
                            p1 = p0;
                            p0 = p0->next;
                        }
                    }
                    else{
                        p0 = p1;
                        p1 = p2;
                
                    }
                    break;
                }
                
                p0 = p1;
                p1 = p2;
                
                p2 = p2->next;
            }
            
            if (flag == 2){
                break;
            }
            
            // make left -> rightin
            if (left != NULL){
                left->next = p0;
            }
            else{
                head = p0;
            }
            // make leftin -> right
            leftin->next = p1;
            
            // redeclare variables
            left = leftin;
            leftin = p1;
        }
        
        return head;
    }
};