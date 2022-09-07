/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    
private:
    TreeNode* recursion(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if (p->val < root->val && q->val < root->val){
            return recursion(root->left, p, q);
        }
        
        if (p->val > root->val && q->val > root->val){
            return recursion(root->right, p, q);
        }
        
        return root;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = recursion(root, p, q);
        
        return lca;
    }
};