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

    int getMaxIndex(vector<int> &nums, int &begin, int &end){
        int maxIndex = begin;
        int maxValue = nums[begin];

        for (int i = begin; i <= end; i++){
            if (nums[i] > maxValue){
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right){
        if (left > right ) return NULL;

        int rootIndex = getMaxIndex(nums, left, right);

        TreeNode* root = new TreeNode(nums[rootIndex]);

        root->left = constructMaximumBinaryTree(nums, left, rootIndex - 1);
        root->right = constructMaximumBinaryTree(nums, rootIndex + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};