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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool nullFound = false;

        q.push(root);

        while (!q.empty()){
            int n = q.size();

            for (int i=0; i<n; i++){
                if (q.front() == NULL) {
                    nullFound = true;
                    q.pop();
                    continue;
                }

                if (nullFound) return false;

                TreeNode* node = q.front();
                q.pop();

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};