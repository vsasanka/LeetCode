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
    int sum(TreeNode* root, unordered_map<int,int> &sumMapping, int &maxCount){
        if (root == NULL) return 0;

        int ls = 0, rs = 0;

        ls = sum(root->left, sumMapping, maxCount);
        rs = sum(root->right, sumMapping, maxCount);

        int sum = ls + rs + root->val;

        sumMapping[sum]++;

        if (sumMapping[sum] > maxCount) maxCount = sumMapping[sum];
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> sumMapping;
        int maxCount = 0;
        vector<int> ans;

        sum(root, sumMapping, maxCount);

        for (auto p : sumMapping){
            if (p.second == maxCount) ans.push_back(p.first);
        }

        return ans;
    }
};