
class Solution {
public:
//[6,5,3,1,0]
    int hIndex_sort(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater<int>());
        for (int i = 0; i < citations.size(); i ++) {
            if (citations[i] < i+1)
                return i;
        }
        return citations.size();
    }
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int sz = citations.size();
        vector<int> cnt(sz+1, 0);
        for (auto x : citations) {
            if (x > sz)
                cnt[sz] ++;
            else
                cnt[x] ++;
        }
        //[0, 1, 2, 3, 4, 5]
        //[1, 1, 0, 1, 0, 2]
        int acc = 0;
        for (int i = cnt.size()-1; i >= 0; i --) {
            acc += cnt[i];
            if (acc >= i)
                return i;
        }
        return citations.size();
    }  
};
