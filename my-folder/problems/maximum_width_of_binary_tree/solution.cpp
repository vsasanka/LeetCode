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

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;

        if (root == NULL) return 0;

        q.push({root, 0});
        int ans = 1;

        while (!q.empty()){
            int n = q.size();

            bool leftFlag = false;
            int minLeft = 0, maxRight = 0;

            for (int i=0; i<n; i++){
                pair<TreeNode*, unsigned long long> node = q.front();
                q.pop();

                if (node.first->left != NULL){
                    q.push({node.first->left, (unsigned long long)node.second*2 + 1});
                    if (!leftFlag){
                        minLeft = node.second*2 + 1;
                        leftFlag = true;
                    }
                    maxRight = node.second*2 + 1;
                }

                if (node.first->right != NULL){
                    q.push({node.first->right, (unsigned long long)node.second*2 + 2});
                    if (!leftFlag){
                        minLeft = node.second*2 + 2;
                        leftFlag = true;
                    }
                    maxRight = node.second*2 + 2;
                }
            }

            ans = max(ans, maxRight - minLeft + 1);
        }

        return ans;
    }
};