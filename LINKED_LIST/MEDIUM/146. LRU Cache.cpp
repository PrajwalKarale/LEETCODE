class LRUCache {
public:
    int n;
    list<int>doublyLL;
    // unordered_map<int, pair<Address, int>> keyAddress; Here Address is the address of the node present in the doublu linked list
    unordered_map<int, pair<list<int>:: iterator, int>> keyAddress;
    LRUCache(int capacity) {
        n = capacity;    
    }
    void recentlyUsed(int key){
        doublyLL.erase(keyAddress[key].first);
        doublyLL.push_front(key);
        keyAddress[key].first = doublyLL.begin();
    }
    int get(int key) {
        if(keyAddress.find(key) == keyAddress.end()){
            return -1;
        }
        recentlyUsed(key);
        return keyAddress[key].second;        
    }
    
    void put(int key, int value) {
        //If the key is already present in the map
        if(keyAddress.find(key) != keyAddress.end()){
            keyAddress[key].second = value;
            recentlyUsed(key);
        }else{
            //If key is not present i.e a completely new value
            doublyLL.push_front(key);
            keyAddress[key] = {doublyLL.begin(), value};
            n--;
        }
        // If capacity is full
        if(n < 0){
            int keyToBeDeleted = doublyLL.back();
            keyAddress.erase(keyToBeDeleted);
            doublyLL.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
