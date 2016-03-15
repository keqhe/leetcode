class Solution {
public:
    string helper(vector<string>& words, int left, int right, int maxWidth) {
        string res;
        int cnt = right - left + 1;
        if (cnt == 1) {//there is only one word in this line
            res = words[left];
            int leftover = maxWidth - words[left].size();
            res += string(leftover, ' ');
            return res;
        }
        else {
            int leftover = maxWidth;
            for (int i = left; i <= right; i ++) {
                    leftover -= words[i].length();
            }
            cout << "leftover is: " << leftover << endl;
            vector<int> spaces(cnt-1, 0);
            
            int j = 0;
            while (leftover > 0) {
                spaces[j%(cnt-1)] ++;
                j ++;
                leftover --;
            }
            for (int i = left; i <= right; i ++) {
                if (i < right)
                    res = res + words[i] + string(spaces[i-left], ' ');
                else if (i == right)
                    res = res + words[i];
            }
            return res;
        }
    }
    
    string helper2(vector<string>& words, int left, int right, int maxWidth) {
        string res;
        for (int i = left; i <= right; i ++)
            res += words[i] + ' ';
        res.pop_back();
        res += string(maxWidth-res.length(), ' ');
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.empty()) {
            return res;
        }
        
        int start_idx = 0;
        int acc_len = 0;
        for (int i = 0; i < words.size(); i ++) {
            
            if (acc_len + words[i].length() > maxWidth) {
                //process
                string s = helper(words, start_idx, i-1, maxWidth);
                res.push_back(s);
                acc_len = words[i].length() + 1;
                start_idx = i;
            }
            else if (acc_len + words[i].length() == maxWidth) {
                //process
                string s;
                if (i < words.size() -1 )
                    s = helper(words, start_idx, i, maxWidth);
                else if (i == words.size()-1) 
                    s = helper2(words, start_idx, i, maxWidth);
                res.push_back(s);
                acc_len = 0;
                start_idx = i+1;
            }
            else {
                acc_len += words[i].length() + 1;
            }
        }
        if (acc_len > 0) {
            string tmp = helper2(words, start_idx, words.size()-1, maxWidth);
            res.push_back(tmp);
        }
        return res;
    }
};
