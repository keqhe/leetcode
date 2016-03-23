
class Solution {
public:
    //可以看到第n位的格雷码由两部分构成，一部分是n-1位格雷码，再加上 1<<(n-1)和n-1位格雷码的逆序的和。
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
            return res;
        }
        
        res = grayCode(n-1);
        int sz = res.size();
        int addNumber = 1 << (n-1);
        for (int i = sz - 1; i >= 0; i --) {
            res.push_back(addNumber + res[i]);
        }
        return res;
    }
    
    //-----------backtracking, but the sequence order OJ does not accept
    //NOTE: the solution below is WRONG, but it is a good excise for backtracking
    void helper(int n, int index, string tillnow, vector<int> & res) {
        if (index == n) {
            int a = stoi(tillnow, NULL, 2);
            res.push_back(a);
            return; //i forgot it...
        }
        string choice = "01";
        for (int i = 0; i < choice.length(); i ++) {
            helper(n, index+1, tillnow+choice[i], res);
        }
    }
    vector<int> grayCode2(int n) {
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
            return res;
        }
        
        helper(n, 0, "", res);
    }
};
