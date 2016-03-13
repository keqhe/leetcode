class Solution {
public:
    //assuming that there are k words and s's length is N, time complexity is O(kN)
    /*
    一个长度为k*M (M is each word's length) 的子串在S上从左到右平移，每个位置上，直接去判断是不是每一个L中的单词都出现了一次。
    */
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty())
            return res;
        int k = words.size();
        int M = words[0].length();
        int N = s.length();
        if (k*M > N)
            return res;
        unordered_map<string, int> count;
        unordered_map<string, int> curr;
        for (auto x : words) {
            count[x] ++;
        }
        for (auto x : count)
            cout << "x.first: " << x.first << " x.second: " << x.second << endl;
        curr = count;
        for (auto x : curr)
            cout << "x.first: " << x.first << " x.second: " << x.second << endl;
        //for (int i = 0; i + k*M < N; i ++) { 
        //WRONG, this testcase: "wordgoodgoodgoodbestword"
        //["word","good","best","good"]
        for (int i = 0; i + k*M <= N; i ++) { 
            curr = count;
            for (int j = 0; j < k; j ++) {
                string str = s.substr(i+j*M, M);
                if (curr.find(str) != curr.end()) {
                    if (curr[str] >= 1) {
                        curr[str] --;
                        if (curr[str] == 0)
                            curr.erase(str);
                    }
                    else
                        break;
                }
                else
                    break;
            }
            if (curr.empty())
                res.push_back(i);
        }
        return res;
    }
};
