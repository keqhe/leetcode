
class Solution {
public:
    vector<string> helper(int n) {
        if (n == 0) {
            vector<string> res;
            res.push_back("");
            return res;
        }
        if (n == 1) {
            vector<string> res;
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
            return res;
        }
        
        if (n > 1) {
            vector<string> start = {"0", "1", "8", "6", "9"};
            vector<string> end = {"0", "1", "8", "9", "6"};
            vector<string> tmp = helper(n-2);
            vector<string> res;
            for (int i = 0; i < tmp.size(); i ++) {
                for (int j = 0; j < start.size(); j ++) {
                    string a = start[j];
                    a += tmp[i] + end[j];
                    
                    res.push_back(a);
                }
            }
            return res;
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        vector<string> res = helper(n);
        vector<string> ret;
        cout << "debug..." << endl;
        for (int i = 0; i < res.size(); i ++) {
            //cout << res[i] << " ";
            
            if (res[i].length() > 1 && res[i][0] == '0') {
                //cout << res[i] << endl;
                continue;
            }
            ret.push_back(res[i]);
        }
        return ret;
    }
};
