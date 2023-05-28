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
    TreeNode* recursion(unordered_map<int,int> &inorderIndex, vector<int>& postorder, int left, int right, int &poIndex){
        if (left > right) return NULL;

        poIndex--;

        cout << poIndex << endl;

        int value = postorder[poIndex];

        TreeNode* node = new TreeNode(value);

        node->right = recursion(inorderIndex, postorder, inorderIndex[value] + 1, right, poIndex);
        node->left = recursion(inorderIndex, postorder, left, inorderIndex[value] - 1, poIndex);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderIndex;
        int poIndex = inorder.size();

        for (int i=0; i<inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }

        return recursion(inorderIndex, postorder, 0, inorder.size() - 1, poIndex);
    }
};