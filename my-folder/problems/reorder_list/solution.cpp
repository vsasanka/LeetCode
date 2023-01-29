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
        vector<ListNode*> nodes;
        
        ListNode* head2 = head;

        while (head2){
            nodes.push_back(head2);
            head2 = head2->next;
        }

        int i = 0, j = nodes.size() - 1;

        while (i < j){
            nodes[i]->next = nodes[j];
            if (i+1 < j) nodes[j]->next = nodes[i+1];
            i++, j--;
        }
        nodes[i]->next = NULL;
    }
};