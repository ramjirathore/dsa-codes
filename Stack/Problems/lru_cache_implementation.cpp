// PROBLEM -

// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity


// OPTIMAL - O(1) time and space for both get and set

class LRUCache {
public:
    class node {
    public: 
        int key;
        int value;
        node* next;
        node* prev;
        
        node() {}
        
        node(int given_key, int given_value) {
            key = given_key;
            value = given_value;
        }
    };
    
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    unordered_map<int, node*> mp;
    int cache_capacity;
    
    void addNode(node* new_node) {
        node* temp = head->next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }
    
    void deleteNode(node* del_node) {
        node* del_prev = del_node->prev;
        node* del_next = del_node->next;
        
        del_prev->next = del_next;
        del_next->prev = del_prev;
        
    }
    
    LRUCache(int capacity) {
        // initialize capacity
        cache_capacity = capacity;
        
        // head and tail point to each other
        head->next = tail;
        tail->prev = head;
        
        //clear map
        mp.clear();
    }
    
    int get(int key) {
        // if key present in map then
        // remove it from prev position
        // add it just after head(since its most recently used)
        // update the new address in the hashmap
        if(mp.find(key) != mp.end()) {
            node* temp = mp[key];
            deleteNode(temp); // remove
            addNode(temp); // add it in starting => most recently used
            mp[key] = head->next; // update the new address at same key
            return temp->value;
        }
        
        // if key not in map then -1
        return -1;
        
    }
    
    void put(int key, int value) {    
        // now if its already present just remove where it was
        // (new node will be added afterwards and it will be most recently used)
        if(mp.find(key) != mp.end()) {
            node* existing_node = mp[key];
            mp.erase(key);
            deleteNode(existing_node);
        }
        
        
        // if capacity has reached max capacity
        // remove the least recently used
        // from ll and hashmap both
        if(mp.size() == cache_capacity) {
            node* lruNode = tail->prev;
            deleteNode(lruNode);
            mp.erase(lruNode->key);
        }
     
        
        // now if its a new pair
        // just simply add after the head
        addNode(new node(key, value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */