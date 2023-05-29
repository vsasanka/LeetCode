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
    void recursion(TreeNode* root, int &targetSum, vector<int> &rootToLeafValues, int sum, vector<vector<int>> &ans){
        if (root == NULL) return ;

        sum += root->val;
        rootToLeafValues.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum){
                ans.push_back(rootToLeafValues);
            }

            rootToLeafValues.pop_back();
            
            return ;
        }

        recursion(root->left, targetSum, rootToLeafValues, sum, ans);
        recursion(root->right, targetSum, rootToLeafValues, sum, ans);

        rootToLeafValues.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> rootToLeafValues;

        recursion(root, targetSum, rootToLeafValues, 0, ans);

        return ans;
    }
};