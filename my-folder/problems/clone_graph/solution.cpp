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
        
        Node* clone = new Node(node->val);
        vector<Node*> neighbor;
        
        mp[node] = clone;
        
        for (auto neig: node->neighbors){
            if (mp.find(neig) != mp.end()){
                neighbor.push_back(mp[neig]);
            }
            else{
                neighbor.push_back(traverseDFS(neig, mp));
            }
        }
        
        clone->neighbors = neighbor;
        
        return clone;
    }
    
public:
    Node* cloneGraph(Node* node) {
        
        if (node == NULL){
            return NULL;
        }
        
        if (node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }
        
        unordered_map<Node*, Node*> mp;
        
        return traverseDFS(node, mp);
    }
};