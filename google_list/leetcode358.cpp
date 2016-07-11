
class Solution {
public:
    
    //https://discuss.leetcode.com/topic/48091/c-unordered_map-priority_queue-solution-using-cache
    string rearrangeString(string str, int k) {
        if (str.empty())
            return "";
        if (k == 0)
            return str;
        unordered_map<char, int> dict;
        priority_queue<pair<int, char>> pq;
        int length = str.length();
        string res;
        for (auto c : str)
            dict[c] ++;
        for (auto kv : dict) 
            pq.push(make_pair(kv.second, kv.first));
        while (!pq.empty()) {
            vector<pair<int, char>> cache;
            int count = min(k, length);
            for (int i = 0; i < count; i ++) {
                if (pq.empty())
                    return "";
                auto curr = pq.top();
                pq.pop();
                res += curr.second;
                length --;
                curr.first --;
                if (curr.first > 0)
                    cache.push_back(curr);
            }
            for (auto x : cache)
                pq.push(x);
        }
        return res;
    }
};
