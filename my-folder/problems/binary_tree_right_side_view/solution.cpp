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
    void recursion(TreeNode* root, vector<int> &ans, int height){
        if (root == NULL) return ;
        
        if (ans.size() >= height + 1){
            ans[height] = root->val;
        }
        else{
            ans.push_back(root->val);
        }
        
        recursion(root->left, ans, height + 1);
        recursion(root->right, ans, height + 1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        recursion(root, ans, 0);
        
        return ans;
    }
};