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
    int preorderIndex;
    unordered_map<int,int> inorderMap;
    TreeNode* recursion(vector<int>& preorder, int left, int right){
        if (left > right) return NULL;

        TreeNode* root = new TreeNode(preorder[preorderIndex++]);

        root->left = recursion(preorder, left, inorderMap[root->val]-1);
        root->right = recursion(preorder, inorderMap[root->val]+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for (int i=0; i<inorder.size();i++){
            inorderMap[inorder[i]] = i;
        }

        preorderIndex = 0;

        return recursion(preorder, 0, preorder.size()-1);
    }
};