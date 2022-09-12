/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string ser(TreeNode* root, string &data){
        if (!root) return data;
        
        data += to_string(root->val) + ",";
        
        ser(root->left, data);
        ser(root->right, data);
        
        return data;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        
        return ser(root, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* des(queue<int> &q, int min, int max){
        if (q.empty()) return NULL;
        
        int val = q.front();
        
        if (val < min || val > max){
            return NULL;
        }
        
        q.pop();
        
        TreeNode* node = new TreeNode(val);
        
        node->left = des(q, min, val);
        node->right = des(q, val, max);
        
        return node;
    }
    
    TreeNode* deserialize(string data) {
        queue<int> q;
         while (data.size() != 0){
             string s = data.substr(0, data.find(','));
             int num = stoi(s);
             q.push(num);
             // if (s.size() != data.size()) 
             data = data.substr(s.size()+1, data.size() - s.size()-1);
             // else break;
         }
            
        return des(q, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;