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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if (root != NULL && root->val < low){
            root = root->right;
            return trimBST(root, low, high);
        }

        if (root != NULL && root->val > high){
            root = root->left;
            return trimBST(root, low, high);
        }

        if (root == NULL) return root;

        recursion(root->left, root, low, high);
        recursion(root->right, root, low, high);

        return root;
    }

private:
    void recursion(TreeNode* node, TreeNode* parent, int &left, int &right){
        if (node == NULL) return ;

        if (node->val < left){
            parent->left = node->right;
            recursion(node->right, parent, left, right);
        }
        else if (node->val > right){
            parent->right = node->left;
            recursion(node->left, parent, left, right);
        }
        else{
            recursion(node->left, node, left, right);
            recursion(node->right, node, left, right);
        }
    }
};