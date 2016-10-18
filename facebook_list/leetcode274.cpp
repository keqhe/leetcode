
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int num = 0;
        sort(citations.begin(), citations.end(), std::greater<int>());
        for (int i = 0; i < citations.size(); i ++) {
            num ++;
            if (citations[i] >= num) {
                continue;
            }
            else {
                return num-1;
            }
        }
        return num;
    }
};
