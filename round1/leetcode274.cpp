
class Solution {
public:
    //[0, 1, 3, 5, 6]
    int hIndex_sort1(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int hindex = 0;
        int size = citations.size();
        for (int i = 0; i < size; i ++) {
            int t = citations[i];
            int many = size - i;
            if (min(many, t) > hindex)
                hindex = min(many, t);
        }
        return hindex;
    }
    //[6, 5, 3, 1, 0]
    int hIndex_sort2(vector<int> & citations) {
        sort(citations.begin(), citations.end(), greater<int>());//large->small
        for (int i = 0; i < citations.size(); i ++) {
            if (i >= citations[i])
                return i;
        }
        //if all of indexes are smaller than citations.smallest
        return citations.size();
    }
    //[3, 0, 6, 1, 5]
    //http://bookshadow.com/weblog/2015/09/03/leetcode-h-index/
    int hIndex(vector<int> & citations) {
        int size = citations.size();
        //hindex must be <= the number of papers, 0 to len is the range
        //使用长度为N + 1的数组cnts记录引用次数在0 ~ N（N篇以上的记为N）的文章个数
        vector<int> cnts (size+1, 0);
        
        for (int i = 0; i < size; i ++) {
            int c = citations[i];
            if (c >= size)
                cnts[size] ++;
            else
                cnts[c] ++;
        }
        //cnt = [1, 1, 0, 1, 0, 2], cnt[i] means the number of papers that have been cited by i
        int sums = 0;
        for (int i = size; i >= 0; i --) {
            if (sums + cnts[i] >= i)
                return i;
            sums += cnts[i];
        }
        
        return 0;
    }
    
};
