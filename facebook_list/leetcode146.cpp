
class LRUCache{
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        else {
            list<pair<int, int>>::iterator it = m[key];
            int val = it->second;
            l.splice(l.begin(), l, it);
            return val;
        }
    }
    
    void set(int key, int value) {
        if (m.find(key) != m.end()) {
            list<pair<int, int>>::iterator it = m[key];
            it->second = value;
            l.splice(l.begin(), l, it);
        }
        else {
            l.push_front(make_pair(key, value));
            list<pair<int, int>>::iterator it = l.begin();
            m[key] = it;
            if (l.size() > capacity) {
                //list<pair<int, int>>::iterator it2del = l.rbegin();
                auto it2del = l.rbegin();
                int key2del = it2del->first;
                m.erase(key2del);
                l.pop_back();
            }
        }
    }
};
