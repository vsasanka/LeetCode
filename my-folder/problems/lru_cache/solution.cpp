struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
};

class LRUCache {
    Node* left;
    Node* right;
    
    int capacity;
    int nodes;
    unordered_map<int,Node*> mp;
    
public:
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        left = new Node;
        left->key = 0;
        left->val = 0;
        
        right = new Node;
        right->key = 0;
        right->val = 0;
        
        left->next = right;
        // left->prev = NULL;
        right->prev = left;
        // right->next = NULL;
        
        this->capacity = capacity;
        this->nodes = 0;
    }
    
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveFront(Node* node){
        node->prev = right->prev;
        node->next = right;
        
        node->prev->next = node;
        right->prev = node;
    }
    
    void removeLeft (){
        Node* rem = left->next;
        mp.erase(rem->key);
        
        Node* leftNode2 = left->next->next;
        
        left->next = leftNode2;
        leftNode2->prev = left;
        
        
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()){
            return -1;
        }
        
        removeNode(mp[key]);
        moveFront(mp[key]);
        
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            removeNode(mp[key]);
            moveFront(mp[key]);
            mp[key]->val = value;
        }
        else{
            Node* newNode = new Node;
            newNode->key = key;
            newNode->val = value;
            
            moveFront(newNode);
            
            mp[key] = newNode;
            
            nodes++;
            
            if (nodes > capacity){
                removeLeft();
                nodes--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */