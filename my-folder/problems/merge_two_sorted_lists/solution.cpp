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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* parent = new ListNode(-1);
        ListNode* parentOriginal = parent;

        while(list1 && list2){
            if (list1->val < list2->val){
                parent->next = new ListNode(list1->val);
                list1 = list1->next;
                parent = parent->next;
            }
            else{
                parent->next = new ListNode(list2->val);
                list2 = list2->next;
                parent = parent->next;
            }
        }

        while(list1){
            parent->next = new ListNode(list1->val);
            list1 = list1->next;
            parent = parent->next;
        }

        while(list2){
            parent->next = new ListNode(list2->val);
            list2 = list2->next;
            parent = parent->next;
        }

        return parentOriginal->next;
    }
};