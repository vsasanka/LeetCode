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
    void addNumbers(TreeNode* root, int &ans, int sum){
        if (root == NULL) return ;

        sum = sum*10 + root->val;

        if (root->left == NULL && root->right == NULL){
            ans += sum;
            return ;
        }

        addNumbers(root->left, ans, sum);
        addNumbers(root->right, ans, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;

        addNumbers(root, ans, 0);

        return ans;
    }
};