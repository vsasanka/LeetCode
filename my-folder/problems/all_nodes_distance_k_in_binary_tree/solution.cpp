/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, int> map;
        vector<int> res;
        populateMap(root, target, map);
        findRes(root, k, 0, res, map);
        return res;
    }

private:
    void findRes(TreeNode* root, int &k, int length, vector<int> &res, unordered_map<TreeNode*, int> &map){
        if (root == NULL) return ;

        if (map.find(root) != map.end()) length = map[root];

        if (length == k) res.push_back(root->val);

        findRes(root->left, k, length + 1, res, map);
        findRes(root->right, k, length + 1, res, map);
    }

    int populateMap(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, int> &map){
        if (root == NULL) return -1;

        if (root == target){
            map[root] = 0;
            return 0;
        }

        int left = populateMap(root->left, target, map);

        if (left >= 0){
            map[root] = left + 1;
            return left + 1;
        }

        int right = populateMap(root->right, target, map);

        if (right >= 0){
            map[root] = right + 1;
            return right + 1;
        }

        return -1;
    }
};