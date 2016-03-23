
class LRUCache{
public:
    //follow this ref: https://leetcode.com/discuss/61270/clean-short-standard-solution-writing-like-other-lengthy-ones
    //idea: use hash table and doubly-linked list (list in c++)
    int cap = 0;
    unordered_map<int, list<pair<int,int>>::iterator> ht;
    list<pair<int,int>> m_list;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        unordered_map<int, list<pair<int,int>>::iterator>::iterator found = ht.find(key);
        if (found != ht.end()) {
            list<pair<int,int>>::iterator it = found->second;
            m_list.splice(m_list.begin(), m_list, it);//LRU
            return it->second;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {//O(1)
        unordered_map<int, list<pair<int,int>>::iterator>::iterator found = ht.find(key);
        if (found != ht.end()) {//key exist
            list<pair<int,int>>::iterator it = found->second;
            it->second = value;//update value
            m_list.splice(m_list.begin(), m_list, it);//LRU
            return;
        }
        //key does not exist
        if (m_list.size() == cap) {
            int key2del = m_list.back().first;
            ht.erase(key2del);
            m_list.pop_back();
        }
        m_list.push_front(make_pair(key, value));//LRU
        ht[key] = m_list.begin();
    }
};
