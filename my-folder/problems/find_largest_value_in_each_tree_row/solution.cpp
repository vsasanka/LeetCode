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
    void largestEachRow(TreeNode* root, vector<int> &largest, int height){
        if (root == NULL) return ;

        if (height > largest.size()){
            largest.push_back(root->val);
        }
        else{
            largest[height-1] = max(largest[height-1], root->val);
        }

        largestEachRow(root->left, largest, height + 1);
        largestEachRow(root->right, largest, height + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> largest;

        largestEachRow(root, largest, 1);

        return largest;
    }
};