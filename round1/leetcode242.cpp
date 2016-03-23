
class Solution {
public:
    bool isAnagram(string s, string t) {
        priority_queue<int, vector<int>, std::greater<int>> pq_s;
        priority_queue<int, vector<int>, greater<int>> pq_t;

        if (s.length() != t.length())
                return false;

        for (int i = 0; i < s.length(); i ++) {
                pq_s.push(s[i]);
        }

        for (int i = 0; i < t.length(); i ++) {
                pq_t.push(t[i]);
        }
        while(!pq_s.empty() && !pq_t.empty()) {
                char stop = pq_s.top();
                char ttop = pq_t.top();

                if (stop == ttop) {
                        pq_s.pop();
                        pq_t.pop();
                }
                else
                        return false;
        }
        
        if (pq_s.empty() && pq_t.empty())
                return true;
        else
                return false;
    }
};
