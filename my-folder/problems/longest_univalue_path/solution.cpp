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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;

        if (root == NULL) return 0;

        int a = recursion(root->left, root, ans);
        int b = recursion(root->right, root, ans);

        ans = max(ans, a + b);

        return ans;
    }

private:
    int recursion(TreeNode* root, TreeNode* parent, int &ans){
        if (root == NULL) return 0;

        int a = recursion(root->left, root, ans);
        int b = recursion(root->right, root, ans);

        ans = max(ans, a + b);

        if (root->val == parent->val) return max(a,b) + 1;
        return 0;
    }
};