
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bi (n);
        string s = bi.to_string();
        int result = 0;
        for (int i = 0; i < s.length(); i ++) {
                if (s[i] == '1')
                result += 1;
        }
        return result;
    }
};
