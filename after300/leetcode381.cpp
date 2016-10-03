
class RandomizedCollection {
public:
    //https://discuss.leetcode.com/topic/54381/c-128m-solution-real-o-1-solution
    unordered_map<int, vector<int>> m;//key is key, vector stores index in store;
    vector<pair<int, int>> store;//first is val, second is the index of m[val]
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto it = m.find(val);
        if (it == m.end()) {
            store.push_back(make_pair(val, 0));
            m[val].push_back(store.size()-1);
            return true;
        }
        else {
            int size = m[val].size();
            store.push_back(make_pair(val, size));
            m[val].push_back(store.size()-1);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) {
            return false;
        }
        else {
            vector<int> index = m[val];
            int x = index.back();
            swap(store[x], store[store.size()-1]);
            //update m[store[x].first]
            m[store[x].first][store[x].second] =  x;
            store.pop_back();
            m[val].pop_back();
            if (m[val].empty()) {
                m.erase(val);
            }
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int r = random() % (store.size());
        return store[r].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
