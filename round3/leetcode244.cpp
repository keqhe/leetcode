
class WordDistance {
public:
    unordered_map<string, vector<int>> m;//string, the indecies where string appears
    WordDistance(vector<string>& words) {
        if (words.empty())
            return;
        for (int i = 0; i < words.size(); i ++) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector <int> a = m[word1];
        vector <int> b = m[word2];
        
        int minDist = numeric_limits<int>::max();
        int i = 0;
        int j = 0;
        for (; i < a.size() && j < b.size(); ) {
            minDist = min(minDist, abs(a[i]-b[j]));
            if (a[i] < b[j])
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
