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
    bool recursion(TreeNode* root, int left_lim, int right_lim){
        // check for range
        
        bool left_sub_tree = true;
        bool right_sub_tree = true;
        
        if (root->val < left_lim || root->val > right_lim){
            return false;
        }
        
        // check if leaf node
        
        if (root->left==NULL && root->right == NULL){
            return true;
        }
        
        // check for left sub tree
        
        if (root->left!=NULL){
            if (root->val==INT_MIN){
                return false;
            }
            left_sub_tree = recursion(root->left, left_lim, root->val-1);
        }
        
        // check for right sub tree
        
        if (root->right!=NULL){
            if (root->val==INT_MAX){
                return false;
            }
            right_sub_tree = recursion(root->right, root->val+1, right_lim);
        }
        
        return left_sub_tree && right_sub_tree;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        // int INT_MIN = ;
        // int INT_MAX = ;
        
        if (root->left==NULL && root->right==NULL){
            return true;
        }
        
        
        return recursion(root, INT_MIN, INT_MAX);
    }
};