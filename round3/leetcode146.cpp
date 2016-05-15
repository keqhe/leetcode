
class LRUCache{
public:
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> ht;
    int cap;
    LRUCache(int capacity) {
       cap = capacity; 
    }
    
    int get(int key) {
        if (ht.find(key) != ht.end()) {
            auto it = ht[key];
            int val = it->second;
            
            lru.splice(lru.begin(), lru, it);
            
            return val;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        if (ht.find(key) != ht.end()) {//exists, then update its value
            auto it = ht[key];
            it->second = value;
            
            lru.splice(lru.begin(), lru, it);
        }
        else {
            pair<int, int> tmp = make_pair(key, value);
            if (lru.size() == cap) {
                pair<int, int> x = lru.back();
                int old_key = x.first;
                ht.erase(old_key);
                lru.pop_back();
            }
            lru.push_front(tmp);
            ht[key] = lru.begin();
        }
    }
};
