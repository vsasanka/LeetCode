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
    int recursion(TreeNode* node, int &diameter){
        if (node == NULL){
            return 0;
        }
        
        int left, right;
        
        left = recursion(node->left, diameter);
        right = recursion(node->right, diameter);
        
        diameter = max(diameter, left + right);
        
        return max(left, right) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        recursion(root, diameter);
        
        return diameter;
    }
};