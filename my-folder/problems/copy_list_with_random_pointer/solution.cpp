/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        Node* head_new = new Node(head->val);
        Node* node1 = head;
        Node* node2 = head_new;
        
        unordered_map<Node*,Node*> mp;
        
        mp[head] = head_new;
        mp[NULL] = NULL;
        
        while (node1){
            if (mp.find(node1->next) == mp.end()){
                node2->next = new Node(node1->next->val);
                mp[node1->next] = node2->next;
            }
            else{
                node2->next = mp[node1->next];
            }
            
            if (mp.find(node1->random) == mp.end()){
                node2->random = new Node(node1->random->val);
                mp[node1->random] = node2->random;
            }
            else{
                node2->random = mp[node1->random];
            }
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return head_new;
    }
};