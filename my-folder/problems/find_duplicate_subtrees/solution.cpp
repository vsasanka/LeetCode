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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*> > map;
        serialize(root, map);
        vector<TreeNode*> ans;

        for (auto it: map){
            if (it.second.size() > 1) ans.push_back(it.second[0]);
        }

        return ans;
    }

private:
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*> > &map){
        if (node == NULL) return "";

        string s = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
        map[s].push_back(node);
        return s;
    }
};