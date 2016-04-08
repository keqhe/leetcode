
class Solution {
public:
    //time complexity is O(MN)
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty())
            return res;
        int unit_size = words[0].length();
        int total_size = unit_size * words.size();
        multiset<string> ms;
        for (auto x : words)
            ms.insert(x);
        for (int i = 0; i+total_size <= s.length(); i += 1) {
            multiset<string> tmp = ms;
            bool found = true;
            for (int j = i; j < i + total_size ; j += unit_size) {
                string str = s.substr(j, unit_size);
                if (tmp.find(str) != tmp.end()) {
                    tmp.erase(tmp.find(str));
                }
                else {
                    found = false;
                    break;//no hope for this i
                }
            }
            if (found)
                res.push_back(i);
            
        }
        return res;
    }
};
