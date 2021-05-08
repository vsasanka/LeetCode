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
    void inorder(TreeNode* node,vector<int> &vec){
        if (node==NULL){
            return ;
        }
        
        inorder(node->left,vec);
        vec.push_back(node->val);
        inorder(node->right,vec);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        if (!root){
            return vec;
        }
        
        inorder(root,vec);
        
        return vec;
    }
};