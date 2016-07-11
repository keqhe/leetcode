
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        sort(citations.begin(), citations.end(), std::greater<int>());
        int hindex = 0;
        for (int i = 0; i < citations.size(); i ++) {
            int cnt = i+1;
            int citation = citations[i];
            if (cnt <= citation) {
                hindex = max(hindex, cnt);
            }
        }
        return hindex;
    }
};
