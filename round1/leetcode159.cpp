
class Solution {
public:
    //ref: https://leetcode.com/discuss/21929/share-my-c-solution
    //ref; http://www.programcreek.com/2013/02/longest-substring-which-contains-2-unique-characters/
    //the above link also talks how to extend the solution to k distnct chars
    
    // it seems that if we change this checking "while(count > 2)" to "while(count > k)", this solution can be extended to "Longest Substring with At Most k Distinct Characters" case.
    //while the following version is easy to understand, it can not pass a large test case
    //TLE version
    /*
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> dict;
        int start = 0; 
        int count = 0;
        int len = 1;
        for (int i = 0; i < s.length(); i ++) {
            char c = s[i];
            dict[c] ++;
            if (dict[c] == 1) {//new char
                count ++;//count keeps track the number of distinct chars
                while (count > 2) {//the problem asks for substrings with 2 unique chars
                    dict[start] --;
                    if (dict[start] == 0)
                        count --;//okay, count is reduced to 2
                    start ++;
                }
            }
            if (i - start + 1 > len)
                len = i - start + 1;
        }
        
        return len;
    }*/
    //so I checked this one: https://leetcode.com/discuss/63013/simple-o-n-java-solution-easily-extend-to-k-characters
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> index;
        int left = 0;
        int right = 0;
        int maxLen = 1;
        for (int i = 0; i < s.length(); i ++) {
            char c = s[i];
            if (index.size() <= 2) {
                index[c] = i;
                //right ++;
            }
            //else { ERROR prone here
            if (index.size() > 2) {
                int leftMost = s.length();
                for (auto & e : index) {
                    leftMost = min(e.second, leftMost);
                }
                index.erase(s[leftMost]);
                left = leftMost+1;
            }
            maxLen = max(maxLen, i - left + 1);
        }
        
        return maxLen;
    }
};
