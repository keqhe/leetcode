
/*
http://www.cnblogs.com/grandyang/p/5272039.html

这道题给我们了许多单词，让我们找出回文对，就是两个单词拼起来是个回文字符串，我最开始尝试的是brute force的方法，每两个单词都拼接起来然后判断是否是回文字符串，但是通过不了OJ，会超时，可能这也是这道题标为Hard的原因之一吧，那么我们只能找别的方法来做，通过学习大神们的解法，发现如下两种方法比较好，其实两种方法的核心思想都一样，写法略有不同而已，那么我们先来看第一种方法吧，要用到哈希表来建立每个单词和其位置的映射，然后需要一个set来保存出现过的单词的长度，算法的思想是，遍历单词集，对于遍历到的单词，我们对其翻转一下，然后在哈希表查找翻转后的字符串是否存在，注意不能和原字符串的坐标位置相同，因为有可能一个单词翻转后和原单词相等，现在我们只是处理了bat和tab的情况，还存在abcd和cba，dcb和abcd这些情况需要考虑，这就是我们为啥需要用set，由于set是自动排序的，我们可以找到当前单词长度在set中的iterator，然后从开头开始遍历set，遍历比当前单词小的长度，比如abcdd翻转后为ddcba，我们发现set中有长度为3的单词，然后我们dd是否为回文串，若是，再看cba是否存在于哈希表，若存在，则说明abcdd和cba是回文对，存入结果中，对于dcb和aabcd这类的情况也是同样处理，我们要在set里找的字符串要在遍历到的字符串的左边和右边分别尝试，看是否是回文对，这样遍历完单词集，就能得到所有的回文对，参见代码如下：
*/
class Solution {
public:
    bool isPal(string s, int l, int r) {
        if (l > r)
            return false;
        while (l < r) {
            if (s[l] == s[r]) {
                l ++;
                r--;
            }
            else 
                return false;
        }
        return true;
    }
    //time complexity is O(nK^2), better than naive solution which is O(n^2K)
    //for this problem, remember that there are three cases: 
    /*
        1)tab and bat
        2)abcdd and cba
        3)ddcba and abc
    */
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if (words.size() < 2)
            return res;
        unordered_map<string, int> m;
        set<int> lens;
        for (int i = 0; i < words.size(); i ++) {
            m[words[i]] = i;
            lens.insert(words[i].size());
        }
        
        for (int i = 0; i < words.size(); i ++) {
            string curr = words[i];
            reverse(curr.begin(), curr.end());
            //handle the case of bat, tab
            if (m.find(curr) != m.end() && i != m[curr]) {
                res.push_back({i, m[curr]});
            }
            int curr_len = curr.length();
            auto len_pointer = lens.find(curr_len);
           
            for (auto it = lens.begin(); it != len_pointer; it ++) {
                int len = *it;
                //"abcdd" -> "ddcba"
                //and "cba"
                if (isPal(curr, 0, curr_len-len-1) && m.find(curr.substr(curr_len - len)) != m.end()) {
                    res.push_back({i, m[curr.substr(curr_len - len)]});
                }
                //"ddcba"->abcdd
                //cba
                if (isPal(curr, len, curr_len-1) && m.find(curr.substr(0, len)) != m.end()) {
                    res.push_back({m[curr.substr(0, len)], i});
                }
            }
        }
        
        return res;
    }
};
