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
    bool equal(TreeNode* root, TreeNode* sub){
        if (root == NULL && sub == NULL){
            return true;
        }
        
        if (root == NULL || sub == NULL){
            return false;
        }
        
        if (root->val != sub->val){
            return false;
        }
        
        bool left = equal(root->left, sub->left);
        bool right = equal(root->right, sub->right);
        
        return left && right;
    }
    
    bool substree(TreeNode* root, TreeNode* sub){
        if (root == NULL && sub == NULL){
            return true;
        }
        
        if (root == NULL || sub == NULL){
            return false;
        }
        
        if (root->val == sub->val){
            bool found = equal(root, sub);
            if (found) return true;
        }
        
        bool left = substree(root->left, sub);
        bool right = substree(root->right, sub);
        
        return left || right;
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return substree(root,subRoot);
    }
};