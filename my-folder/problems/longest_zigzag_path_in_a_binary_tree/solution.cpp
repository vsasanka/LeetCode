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
    int recursion(TreeNode* root, int zigzagLength, char parent){
        if (root == NULL) return zigzagLength;

        int a, b;

        if (parent == 'r'){
            a = recursion(root->left, zigzagLength+1, 'l');
            b = recursion(root->right, 1, 'r');
        }
        else{
            a = recursion(root->right, zigzagLength+1, 'r');
            b = recursion(root->left, 1, 'l');
        }

        return max(a,b);
    }

    int longestZigZag(TreeNode* root) {
        return max(recursion(root, 0, 'r'), recursion(root, 0, 'l')) - 1;
    }
};