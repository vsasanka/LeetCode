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
    TreeNode* recursion(TreeNode* prev_node, int l, int r, vector<int>& nums){
        if (l>r){
            return NULL;
        }
        
        TreeNode* curr_node = new TreeNode;
        int mid = (l+r)/2;
        curr_node->val = nums[mid];
        // prev_node = curr_node;
        curr_node->left = recursion(curr_node->left, l, mid-1, nums);
        curr_node->right = recursion(curr_node->right, mid+1, r, nums);
        return curr_node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = new TreeNode;
        
        if (nums.size()==0){
            return NULL;
        }
        
        root->val = nums[nums.size()/2];
        
        if (nums.size()!=1){
            root->left = recursion(root->left, 0,nums.size()/2-1, nums);
            root->right = recursion(root->right, nums.size()/2+1,nums.size()-1, nums);
        }
        else{
            root->left = NULL;
            root->right = NULL;
        }
        return root;
    }
};