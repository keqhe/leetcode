
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto x : strs) {
            int len = x.length();
            res += to_string(len) + "#" + x;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int curr = 0;
        while (curr < s.length()) {
            int stop = s.find("#", curr);//think about "3#abc1#a"
            string strLen = s.substr(curr, stop-curr);
            int len = stoi(strLen);
            string str = s.substr(stop+1, len);
            res.push_back(str);
            curr = stop + 1 + len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
