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
    void preOrderTraversal(TreeNode* root, queue<TreeNode*> &nodes){
        if (root == NULL) return ;

        nodes.push(root);
        preOrderTraversal(root->left, nodes);
        preOrderTraversal(root->right, nodes);
    }

public:
    void flatten(TreeNode* root) {
        if (root == NULL) return ;

        queue<TreeNode*> nodes;

        preOrderTraversal(root, nodes);

        TreeNode* prev = nodes.front();
        prev->left = NULL;
        prev->right = NULL;
        nodes.pop();

        while (!nodes.empty()){
            TreeNode* curr = nodes.front();
            curr->left = NULL;
            curr->right = NULL;
            prev->right = curr;
            prev = curr;
            nodes.pop();
        }

    }
};