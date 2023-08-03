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
    vector<vector<string>> printTree(TreeNode* root) {
        int maxHeight = 0;
        heightOfTree(root, 0, maxHeight);

        int m = maxHeight + 1;
        int n = pow(2, m) - 1;

        vector<vector<string>> ans(m, vector<string>(n, ""));

        populateMatrix(root, 0, (n-1)/2, maxHeight, ans);

        return ans;
    }

private:
    void heightOfTree(TreeNode* root, int height, int &maxHeight){
        if (root == NULL) return ;

        maxHeight = max(height, maxHeight);

        heightOfTree(root->left, height+1, maxHeight);
        heightOfTree(root->right, height+1, maxHeight);
    }

    void populateMatrix(TreeNode* root, int row, int col, int &maxHeight, vector<vector<string>> &ans){
        if (root == NULL) return ;

        ans[row][col] = to_string(root->val);

        populateMatrix(root->left, row + 1, col - pow(2, maxHeight - row - 1), maxHeight, ans);
        populateMatrix(root->right, row + 1, col + pow(2, maxHeight - row - 1), maxHeight, ans);
    }
};