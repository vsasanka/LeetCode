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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        recursion(root, val);
        return root;
    }

private:
    void recursion(TreeNode* root, int val){
        if (root->val > val){
            if (root->left == NULL){
                TreeNode* node = new TreeNode(val);
                root->left = node;
            }
            else{
                recursion(root->left, val);
            }
        }
        else{
            if (root->right == NULL){
                TreeNode* node = new TreeNode(val);
                root->right = node;
            }
            else{
                recursion(root->right, val);
            }
        }
    }
};