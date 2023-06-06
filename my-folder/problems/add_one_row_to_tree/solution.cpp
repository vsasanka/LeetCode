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
    void addRow(TreeNode* root, int val, int &depth, int currDepth){
        if (root == NULL) return ;

        if (currDepth == depth - 1){
            TreeNode* newNode1 = new TreeNode(val);
            TreeNode* newNode2 = new TreeNode(val);

            newNode1->left = root->left;
            newNode2->right = root->right;

            root->left = newNode1;
            root->right = newNode2;

            return ;
        }

        addRow(root->left, val, depth, currDepth + 1);
        addRow(root->right, val, depth, currDepth + 1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        addRow(root, val, depth, 1);
        return root;
    }
};