
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (int i = 0; i < strs.size(); i ++) {
            int len = strs[i].length();
            res += to_string(len) + "#" + strs[i];
        }
        return res;
    }
    //recursive meets TLE
    void helper(string s, vector<string> & res) {
        if (s.empty())
            return;//end of processing
        int found = s.find('#');
        int len = stoi(s.substr(0, found));
        string tmp = s.substr(found+1, len);
        res.push_back(tmp);
        helper(s.substr(found+1+len), res);//3#abc2#ab
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        if (s.empty())
            return res;
        int i = 0;
        while (i < s.length()) {
            int found = s.find('#', i);//find '#' starting from index i
            int len = stoi(s.substr(i, found));
            string tmp = s.substr(found+1, len);
            res.push_back(tmp);
            i = found+1+len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
