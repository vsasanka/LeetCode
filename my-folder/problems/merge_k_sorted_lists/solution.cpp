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
    ListNode* returnMin(vector<ListNode*>& lists){
        
        ListNode* min = NULL;
        int minIndex = -1;
        
        for (int i=0; i<lists.size(); i++){
            
            if (min==NULL){
                min = lists[i];
                minIndex = i;
                continue;
            }
            
            if (lists[i] != NULL){
                if (lists[i]->val < min->val){
                    min = lists[i];
                    minIndex = i;
                }
            }
        }
        
        if (min != NULL) lists[minIndex] = lists[minIndex]->next;
        return min;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        
        while (true){
            ListNode* min = returnMin(lists);
            if (min == NULL) break;
            curr->next = new ListNode(min->val);
            curr = curr->next;
        }
        
        return ans->next;
    }
};

/*

1 2 3
1 4 5
4 5 6

*/