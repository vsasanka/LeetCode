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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = NULL;
        ListNode* ans = NULL;

        while (true){
            int smallestVal = INT_MAX;
            int smallListIndex = -1;

            for (int i=0; i<lists.size(); i++){
                // ListNode* listNow = lists[i];
                if (lists[i] != NULL && lists[i]->val < smallestVal){
                    smallestVal = lists[i]->val;
                    smallListIndex = i;
                }
            }

            if (smallListIndex == -1){
                break;
            }

            ListNode* node = new ListNode();
            node->val = smallestVal;
            lists[smallListIndex] = lists[smallListIndex]->next;

            if (!head){
                head = node;
                ans = node;
            }
            else{
                head->next = node;
                head = node;
            }
        }

        return ans;
    }
};