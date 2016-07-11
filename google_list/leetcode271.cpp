
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto s : strs) {
            int len = s.length();
            res += to_string(len) + ',' + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int index = s.find(',', i);
            int len = stoi(s.substr(i, index-i));
            string curr = s.substr(index+1, len);
            res.push_back(curr);
            i = index+1+len;//e.g., "3,abc4,"
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
