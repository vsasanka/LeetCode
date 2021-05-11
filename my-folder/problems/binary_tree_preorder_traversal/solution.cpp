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
    void recursion(TreeNode* node, vector<int>& order){
        if (node==NULL){
            return ;
        }
        
        order.push_back(node->val);
        
        if (node->left){
            recursion(node->left, order);
        }
        
        if (node->right){
            recursion(node->right, order);
        }
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        if (!root){
            return order;
        }
        recursion(root,order);
        return order;
    }
};