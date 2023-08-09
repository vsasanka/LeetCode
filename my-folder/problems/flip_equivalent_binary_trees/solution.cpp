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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return true;

        if (root1 == NULL || root2 == NULL) return false;

        if (root1->val != root2->val) return false;

        int a = -1, b = -1, c = -1, d = -1;

        if (root1->left != NULL) a = root1->left->val;
        if (root1->right != NULL) b = root1->right->val;
        if (root2->left != NULL) c = root2->left->val;
        if (root2->right != NULL) d = root2->right->val;

        if (a == c && b == d) return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        if (a == d && b == c) return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

        return false;
    }
};