
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int bull = 0;
        int cow = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bull++;
            else {
                if (m.find(secret[i]) != m.end())
                    m[secret[i]] += 1;
                else
                    m[secret[i]] = 1;
            }
        }
        for (int i = 0; i < secret.size(); i ++) {
            if (secret[i] != guess[i]) {
                int c = guess[i];
                if (m.find(c) != m.end()) {
                    if (m[c] != 0) {
                        m[c] -= 1;
                        cow ++;
                    }
                }
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
