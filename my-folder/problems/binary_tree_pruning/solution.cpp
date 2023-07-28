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
    TreeNode* pruneTree(TreeNode* root) {
        bool res = removeNodes(root);
        if (res) return NULL;
        return root;
    }

private:
    bool removeNodes(TreeNode* root){
        if (root == NULL) return true;

        bool left = removeNodes(root->left);
        bool right = removeNodes(root->right);

        if (left && right && root->val == 0) return true;

        if (left) root->left = NULL;

        if (right) root->right = NULL;

        return false;
    }
};