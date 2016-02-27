#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return "";
        string res = "1";
        string tmp;
        int c = 1;
        while (c < n) {
            tmp.clear();
            int num = 1;
            int i = 0;
            while (i < res.length()) {
                if (i == res.length() - 1) {
                    tmp += to_string(num) + string(1, res[i]);
                    i ++;
                }
                else if (i < res.length()-1){
                    if (res[i] == res[i+1]) {
                        num ++;
                        i ++;
                    }
                    else {
                        tmp += to_string(num) + string(1, res[i]);
                        num = 1;
                        i ++;
                    }
                }
            }
            
            res = tmp;
            c ++;
        }
        
        return res;
    }
};

int main() {
	class Solution sn;
	return 0;
}
