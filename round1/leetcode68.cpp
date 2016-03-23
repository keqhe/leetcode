
class Solution {
public:
    int getLen (vector<string> & v) {
        if (v.empty())
            return 0;
        int total = 0;
        for (int i = 0; i < v.size(); i ++)
            total += v[i].length() + 1;
        return total;
    }
    
    int getLen2 (vector<string> & v) {
        if (v.empty())
            return 0;
        int total = 0;
        for (int i = 0; i < v.size(); i ++)
            total += v[i].length();
        return total;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.empty()) {
            return res;
        }
        vector<string> curr;
        for (int i = 0; i < words.size(); i ++) {
            string w = words[i];
            //cout << " processing word : " << w << endl;
            if (getLen(curr) + w.length() == maxWidth) {
                string tmp;
                for (auto & x : curr) {
                    if (tmp != "")
                        tmp += ' ';
                    tmp += x;
                }
                if (tmp != "")
                        tmp += ' ';
                tmp += w;
                //cout << "tmp :" << tmp<< endl;
                res.push_back(tmp);
                curr.clear();
            }
            else if (getLen(curr) + w.length() < maxWidth) {
                curr.push_back(w);
                if (i == words.size()-1) {
                    string tmp;
                    for (auto & x : curr) {
                        if (tmp != "")
                            tmp += ' ';
                        tmp += x;
                    }
                    
                    //cout << "tmp is :" << tmp << endl;
                    int extra = maxWidth - tmp.size();
                    tmp += string(extra,' ');
                    res.push_back(tmp);
                    curr.clear();
                }
            }
            else {
                int real_char = getLen2(curr);
                int spaces = maxWidth - real_char;
                int wc = curr.size();
                string tmp;
                if (wc == 1) {
                     tmp += curr[0];
                     tmp += string(spaces, ' ');
                     res.push_back(tmp);
                     curr.clear();
                }
                else {
                    int avg = spaces / (wc - 1);
                    int left = spaces;
                    
                    //cout << "spaces is :" << spaces << endl;
                    //cout << "left is :" << left << endl;
                    for (int j = curr.size() - 1; j >= 0; j --) {
                        tmp = curr[j] + tmp;
                        if (j == 1)
                            tmp = string(left, ' ') + tmp;
                        else if (j > 0) {
                            tmp = string(avg, ' ') + tmp;
                            left -= avg;
                            wc --;
                            avg = left / (wc - 1);
                        }
                        
                    }
                    
                    res.push_back(tmp);
                    curr.clear();
                }
                if (i < words.size() - 1)
                    curr.push_back(w);
                else {
                    //cout << "debug..." << endl;
                    string tmp = w+string(maxWidth-w.length(), ' ');
                    res.push_back(tmp);
                }
            }
        }
        
        //the left curr
        /*
        int real_char = getLen2(curr);
        int spaces = maxWidth - real_char;
        int wc = curr.size();
        string tmp;
        if (wc == 1) {
                tmp += curr[0];
                tmp += string(spaces, ' ');
                res.push_back(tmp);
                curr.clear();
        }
        else if (wc > 1) {
            int avg = spaces / (wc - 1);
            int left = spaces;
            for (int j = curr.size() - 1; j >= 0; j --) {
                tmp = curr[j] + tmp;
                if (j == 1)
                        tmp = string(left, ' ') + tmp;
                else if (j > 0) {
                        tmp = string(avg, ' ') + tmp;
                        left -= avg;
                }
            }
                    
            res.push_back(tmp);
            curr.clear();
        }
        */
        return res;
    }
};
