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
    void buttomLeft(TreeNode* root, int &totalHeight, int currHeight, int &ans){
        if (root == NULL) return ;

        currHeight++;

        if (currHeight > totalHeight) {
            ans = root->val;
            totalHeight = currHeight;
        }

        buttomLeft(root->left, totalHeight, currHeight, ans);
        buttomLeft(root->right, totalHeight, currHeight, ans);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int height = 0;
        int ans = root->val;

        buttomLeft(root, height, 0, ans);

        return ans;
    }
};