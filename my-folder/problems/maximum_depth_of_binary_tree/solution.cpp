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
    int maxDepth(TreeNode* root, int depth){
        if (root == NULL) return depth;

        depth++;

        return max(maxDepth(root->left, depth), maxDepth(root->right, depth));
        
    }

    int maxDepth(TreeNode* root) {
        int depth = 0;

        return maxDepth(root, depth);
    }
};