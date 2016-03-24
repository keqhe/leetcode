
class LRUCache{
public:
    //ref: https://leetcode.com/discuss/61270/clean-short-standard-solution-writing-like-other-lengthy-ones
    unordered_map<int,list<pair<int,int>>::iterator> dict;
    list<pair<int, int>> l;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = dict.find(key);
        if (it == dict.end())
            return -1;
        else {
            int res = it->second->second;//it->second it type of list<pair<int,int>>::iterator
            l.splice(l.begin(), l, it->second);//move the visited to list front
            return res;
        }
    }
    
    void set(int key, int value) {
        auto it = dict.find(key);
        if (it == dict.end()) {
            if (l.size() == cap) {
                int key2del = l.back().first;
                l.pop_back();
                dict.erase(key2del);
                l.push_front(make_pair(key, value));
                dict[key] = l.begin();
            }
            else {
                l.push_front(make_pair(key, value));
                dict[key] = l.begin();
            }
        }
        else  {//exists
            l.splice(l.begin(), l, it->second);
            it->second->second = value;
        }
    }
};
