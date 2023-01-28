/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
private:
    Node* traverseDFS(Node* node, unordered_map<Node*, Node*> &mp){
        // cout << node->val << endl;

        if (mp.find(node) != mp.end()) return mp[node];
        
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for (Node* n : node->neighbors){
            newNode->neighbors.push_back(traverseDFS(n, mp));
        }

        return newNode;
    }
    
public:
    Node* cloneGraph(Node* node) {
        
        if (node == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        return traverseDFS(node, mp);

    }
};