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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bst(vector<int> &nodes, int left, int right){
        if (left > right) return NULL;
        
        int mid = left + (right - left + 1)/2;

        TreeNode* node = new TreeNode(nodes[mid]);

        node->left = bst(nodes, left, mid - 1);
        node->right = bst(nodes, mid + 1, right);

        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;

        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }

        return bst(nodes, 0, nodes.size() - 1);
    }
};