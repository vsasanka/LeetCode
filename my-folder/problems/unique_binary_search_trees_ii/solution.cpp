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
    vector<TreeNode*> recursion(int start, int end){
        if (start > end) return {NULL};
        
        vector<TreeNode*> ans;
        
        for (int currNode = start; currNode<= end; currNode++){
            vector<TreeNode*> left_trees = recursion(start, currNode-1);
            vector<TreeNode*> right_trees = recursion(currNode+1, end);
            
            for (auto lt : left_trees){
                for (auto rt: right_trees){
                    TreeNode* cNodePointer = new TreeNode(currNode);
                    cNodePointer->left = lt;
                    cNodePointer->right = rt;
                    
                    ans.push_back(cNodePointer);
                }
            }
        }
        return ans;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        
        
        return recursion(1,n);
    }
};