
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int bull = 0;
        int cow = 0;
        for (int i = 0; i < secret.length(); i ++) {
            if (secret[i] == guess[i])
                bull ++;
            else 
                m[secret[i]] ++;
        }
        
        for (int i = 0; i < guess.length(); i ++) {
            char c = guess[i];
            if (m.find(c) != m.end()) {
                //if (m[c] > 0) {
                if (m[c] > 0 && guess[i] != secret[i]) {
                    cow ++;
                    m[c] --;
                }
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
