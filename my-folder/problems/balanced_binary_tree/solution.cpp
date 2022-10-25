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
    
    int recursion(TreeNode* node, bool &bbt){
        if (node == NULL){
            return 0;
        }
        
        int left, right;
        
        left = recursion(node->left, bbt);
        right = recursion(node->right, bbt);
        
        bbt = abs(left - right) <= 1 ? true && bbt: false;
        
        return max(left, right) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        bool bbt = true;
        
        recursion(root, bbt);
        
        return bbt;
    }
};