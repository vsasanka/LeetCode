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
    void recursion(TreeNode* root, vector<int>& res){
        if(root==NULL){
            return;
        }
        
        if (root->left){
            recursion(root->left, res);
        }
        
        if (root->right){
            recursion(root->right, res);
        }
        
        res.push_back(root->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        if (!root){
            return res;
        }
        
        recursion(root, res);
        
        return res;
    }
};