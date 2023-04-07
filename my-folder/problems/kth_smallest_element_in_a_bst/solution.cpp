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
    void recursion(TreeNode* root, int &k, int &ans, int &rank){
        if (root == NULL) return ;

        recursion(root->left, k, ans, rank);
        rank++;
        if (rank == k) {
            ans = root->val;
            return ;
        }
        recursion(root->right, k, ans, rank);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans, rank = 0;
        recursion(root, k, ans, rank);
        
        return ans;
    }
};