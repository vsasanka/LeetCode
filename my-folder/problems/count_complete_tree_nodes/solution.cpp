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
    int recursion(TreeNode* root){
        if (root == NULL) return 0;
        
        int hl = 0, hr = 0;
        TreeNode* ln = root, *rn = root;

        while (ln){
            hl++;
            ln = ln->left;
        }

        while (rn){
            hr++;
            rn = rn->right;
        }

        if (hl == hr) return pow(2, hl) - 1;

        return 1 + recursion(root->left) + recursion(root->right);
    }

    int countNodes(TreeNode* root) {
        return recursion(root);
    }
};