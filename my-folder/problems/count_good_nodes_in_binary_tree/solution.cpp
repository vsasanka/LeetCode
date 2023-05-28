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
    void recursion(TreeNode* root, int &count, stack<int> &stk){
        if (root == NULL) return ;

        bool stPush = false;

        if (stk.top() <= root->val){
            count++;
            stk.push(root->val);
            stPush = true;
        }

        recursion(root->left, count, stk);
        recursion(root->right, count, stk);

        if (stPush) stk.pop();
    }

    int goodNodes(TreeNode* root) {
        int count = 1;
        stack<int> stk;

        if (root == NULL) return 0;

        stk.push(root->val);

        recursion(root->left, count, stk);
        recursion(root->right, count, stk);

        return count;
    }
};