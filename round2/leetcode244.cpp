
class WordDistance {
public:
    unordered_map<string, vector<int>> dict;
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i ++) {
            dict[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> l1 = dict[word1];
        vector<int> l2 = dict[word2];
        int minDist = numeric_limits<int>::max();
        int i = 0;
        int j = 0;
        for (; i < l1.size() && j < l2.size(); ) {
            minDist = min(minDist, abs(l1[i]-l2[j]));
            if (l1[i] < l2[j])
                i ++;
            else
                j ++;
        }
        return minDist;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
