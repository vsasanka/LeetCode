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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev, *curr, *next;

        if (head == NULL) return NULL;

        if (head->next == NULL) return head;

        prev = NULL;
        curr = head;
        next = head->next;

        while (curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next == NULL)
                return prev;
            next = next->next;
        }

        return curr;
    }
};