
class LRUCache{
public:
    unordered_map<int, list<pair<int, int>>::iterator> um;
    list<pair<int, int>> l;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (um.find(key) == um.end())
            return -1;
        else {
            auto it = um[key];
            int res = it->second;
            l.splice(l.begin(), l, it);
            return res;
        }
    }
    
    void set(int key, int value) {
        if (um.find(key) == um.end()) {//does not exist
            l.push_front(make_pair(key, value));
            if (l.size() == cap+1) {
                int old_key = l.back().first;
                um.erase(old_key);
                l.pop_back();
            }
            um[key] = l.begin();
        }
        else {
            auto it = um[key];
            it->second = value;
            l.splice(l.begin(), l, it);
        }
    }
};
