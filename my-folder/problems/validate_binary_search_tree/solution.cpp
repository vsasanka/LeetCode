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
    bool recursion(TreeNode* node, long left, long right){
        if (node == NULL) return true;

        if (node->val <= left || node->val >= right) return false;

        return recursion(node->left, left, node->val) && recursion(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return recursion(root, LONG_MIN, LONG_MAX);
    }
};