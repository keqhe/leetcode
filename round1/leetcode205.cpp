
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_map<char, char> map2;
        
        if (s.length() != t.length())
            return false;

        for (int i = 0; i < s.length(); i ++) {
            char sc = s[i];
            char tc = t[i];
            if (map.find(sc) == map.end())
                map[sc] = tc;
            else {
                if (map[sc] != tc)
                    return false;
            }
        }
        
        for (int j = 0; j < t.length(); j ++) {
            char tc = t[j];
            char sc = s[j];
            if (map2.find(tc) == map2.end())
                map2[tc] = sc;
            else {
                if (map2[tc] != sc)
                    return false;
            }
        }
        
        return true;
    }
};
