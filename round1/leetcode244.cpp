
class WordDistance {
public:
    //ref: https://leetcode.com/discuss/50190/java-solution-using-hashmap
    unordered_map<string,vector<int>> m;
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i ++) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0;
        int j = 0;
        int res = numeric_limits<int>::max();
        while (i < m[word1].size() && j < m[word2].size()) {
            if (m[word1][i] < m[word2][j]) {
                res = min(res, abs(m[word1][i]-m[word2][j]));
                i ++;
            }
            else {
                res = min(res, abs(m[word1][i]-m[word2][j]));
                j ++;
            }
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
