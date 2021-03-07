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
    
private:
    int recursion(TreeNode* root, int max_val){
        int left,right;
        max_val +=1;
        left = max_val;
        right = max_val;
        
        if (root->left==NULL && root->right==NULL){
            return max_val;
        }
        
        if (root->left!=NULL){
            left = recursion(root->left, max_val);
        }
        
        if (root->right!=NULL){
            right = recursion(root->right, max_val);
        }
        
        return max(left, right);
    }
    
public:
    int maxDepth(TreeNode* root) {
        int max_val = 0;
        
        if (root==NULL){
            return 0;
        }
        
        return recursion(root, max_val);
    }
};