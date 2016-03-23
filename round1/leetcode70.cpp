
class Solution {
public:
    unordered_map<int, long> sub {{0,0}, {1,1}, {2,2}};
    int climbStairs(int n) {
        for (int i = 3; i <= n; i ++) {
            //sub.insert({i, sub[i-1] + sub[i-2]});
            sub[i] = sub[i-1] + sub[i-2];
        }
        //for (unordered_map<int,long>::iterator it = sub.begin(); it != sub.end(); it ++) {
        //    cout<< it->first << ' ' << it->second << endl;
        //}
        if (n < 3)
            return sub[n];
        else
            return sub[n];
    }
};
