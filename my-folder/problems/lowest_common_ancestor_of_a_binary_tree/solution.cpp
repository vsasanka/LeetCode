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
    int recursion(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &lca){
        
        if (!root) return 0;
        
        int left = 0, right = 0, gen = 0;
        
        if (p == root || q == root){
            gen = 1;
        }
        
        left = recursion(root->left, p,q,lca);
        if (left == 10) return 10;
        right = recursion(root->right, p,q,lca);
        if (right == 10) return 10;
        
        if (left + right + gen == 2){
            lca = root;
            return 10;
        }
//         else if (right == 1 && gen == 1){
            
//         }
//         else if (left == 1 && right == 1)
        
        return left + right + gen;
    }
    
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;
        
        int i = recursion(root, p, q, lca);
        
        return lca;
    }
};