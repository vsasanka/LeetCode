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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL){
            return head;
        }
        
        int llSize = 0;
        ListNode* head1 = head;
        while (head1){
            llSize++;
            head1 = head1->next;
        }

        int toRemove = llSize - n;

        if (toRemove == 0){
            return head->next;
        }

        ListNode *prev, *curr;

        prev = NULL;
        curr = head;

        while(toRemove--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        return head;
    }
};