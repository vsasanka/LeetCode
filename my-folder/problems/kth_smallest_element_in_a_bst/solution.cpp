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
    
    bool found;
    int kthsmall;
    int assess;
    
private:
    bool findK(TreeNode* root,int k){
        if (root==NULL){
            return false;
        }
        
        bool search = findK(root->left,k);
        if (search){
            return true;
        }
        
        assess++;
        if (assess==k){
            kthsmall = root->val;
            found = true;
            return true;
        }
        
        return findK(root->right,k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        found = false;
        kthsmall = -1;
        assess=0;
        
        findK(root,k);
        
        return kthsmall;
    }
};