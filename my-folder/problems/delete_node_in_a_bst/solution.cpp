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

    void remove(TreeNode* root, TreeNode* parent, char child){
        // cout << root->val << " " << parent->val << endl;
        if (root->right != NULL){
            TreeNode* prev = root;
            TreeNode* curr = root->right;
            bool parentFlag = false;

            while (curr->left){
                prev = curr;
                curr = curr->left;
                parentFlag = true;
            }

            int temp = root->val;
            root->val = curr->val;
            curr->val = temp;

            if (parentFlag){
                remove(curr, prev, 'l');
            }
            else remove(curr, prev, 'r');
            
            return ;
        }
        else if (root->left != NULL){
            TreeNode* prev = root;
            TreeNode* curr = root->left;
            bool parentFlag = false;

            while (curr->right){
                prev = curr;
                curr = curr->right;
                parentFlag = true;
            }

            int temp = root->val;
            root->val = curr->val;
            curr->val = temp;

            if (parentFlag){
                remove(curr, prev, 'r');
            }
            else remove(curr, prev, 'l');
            
            return ;
        }
        if (child == 'l') parent->left = NULL;
        else {
            // cout << parent->val << " ";
            parent->right = NULL;
        }
    }

    void search(TreeNode* root, TreeNode* parent, int &key, char child){
        if (root == NULL) return ;

        if (root->val == key){
            remove(root, parent, child);
            return ;
        }

        search(root->left, root, key, 'l');
        search(root->right, root, key, 'r');
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        if (root->val == key && root->left == NULL && root->right == NULL) return NULL;

        search(root, NULL, key, 'n');

        return root;
    }
};