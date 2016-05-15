
class Solution {
public:
    string helper(vector<string>& words, int maxWidth, int start, int end) {
        if (start == end) {
            return words[start] + string(maxWidth-words[start].length(), ' ');
        }
        vector<int> gaps(end-start, 0);
        int trueLen = 0;
        for (int i = start; i <= end; i ++) {
            trueLen += words[i].length();
        }
        int extra = maxWidth - trueLen;
        cout << "debug extra: " << extra << endl;
        int j = 0;
        while (extra > 0) {//using loop to allocate spaces properly
            gaps[j] += 1;
            j = (j+1) % gaps.size();
            extra --;
        }
        string res;
        j = 0;
        for (int i = start; i <= end; i ++) {
            if (i == end)
                res += words[i];
            else
                res += words[i] + string(gaps[j++], ' ');
        }
        return res;
    }
    string helper2(vector<string>& words, int maxWidth, int start, int end) {
        if (start == end) {
            return words[start] + string(maxWidth-words[start].length(), ' ');
        }
        string res;
        for (int i = start; i <= end; i ++) {
            if (i == end)
                res += words[i];
            else
                res += words[i] + ' ';
        }
        int currLen = res.length();
        if (currLen < maxWidth)
            res += string(maxWidth-currLen, ' ');
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        if (words.empty())
            return res;
        int start = 0;
        int i = 0;
        for (; i < words.size(); i ++) {
            cout << "debug i: " << i << endl;
            string line;
            if (i == words.size()-1) {//be careful here
                line = helper2(words, maxWidth, start, i);
                res.push_back(line);
                break;
            }
            //not the last word in the array
            int acc = 0;
            for (int j = start; j <= i; j ++) {
                acc += words[j].length();
            }
            int minLen = acc + i - start;
            cout << "debug minLen: " << minLen << endl;
            if (minLen == maxWidth) {
                line = helper(words, maxWidth, start, i);
                res.push_back(line);
                start = i+1;
            }
            else if (minLen < maxWidth) {
                if (i+1 < words.size()) {
                    if (minLen + 1 + words[i+1].length() <= maxWidth)//current line should continue
                        continue;
                    else {//current line should stop at 
                        line = helper(words, maxWidth, start, i);
                        res.push_back(line);
                        start = i + 1;
                    }
                }
            }
            cout << "debug line:" << line << endl;
        }
        return res;
    }
};
