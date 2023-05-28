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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (root == NULL) return ans;

        q.push(root);

        while (!q.empty()){
            int x = q.size();
            vector<int> v;

            for (int i=0; i<x; i++){
                TreeNode* t = q.front();
                v.push_back(t->val);
                q.pop();
                if (t->left != NULL) q.push(t->left);
                if (t->right != NULL) q.push(t->right);
            }

            ans.push_back(v);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};