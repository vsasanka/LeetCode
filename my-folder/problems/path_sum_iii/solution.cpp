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
    void recursion(TreeNode* root, int &targetSum, vector<long long> &sums, int &ans){
        if (root == NULL) return ;

        int n = sums.size();
        for (int i=0; i<n; i++){
            sums[i] += root->val;
            if (sums[i] == targetSum) ans++;
        }
        sums.push_back(root->val);
        if (root->val == targetSum) ans++;

        recursion(root->left, targetSum, sums, ans);
        recursion(root->right, targetSum, sums, ans);

        sums.pop_back();
        for (int i=0; i<n; i++){
            sums[i] -= root->val;
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> sums;
        int ans = 0;

        recursion(root, targetSum, sums, ans);

        return ans;
    }
};