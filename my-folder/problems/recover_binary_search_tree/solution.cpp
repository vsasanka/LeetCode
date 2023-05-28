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
public:
    void inorderTraversal(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second){
        if (root == NULL) return ;

        inorderTraversal(root->left, prev, first, second);
        
        if (prev == NULL){
            prev = root;
        }
        else if (first == NULL){
            if (prev->val > root->val) {
                first = prev;
                second = root;
            }
        }
        else{
            if (prev->val > root->val) second = root;
        }
        prev = root;

        inorderTraversal(root->right, prev, first, second);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *second = NULL;
        
        inorderTraversal(root, prev, first, second);

        int temp;
        temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};