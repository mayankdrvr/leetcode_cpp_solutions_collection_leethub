class Solution {
public:
    int KMPtheorm(string s) {
        int LPS[s.size()];
        LPS[0] = 0;
        int i = 1;
        int len = 0;
        while (i < s.size()) {
            if (s[i] == s[len]) {
                len++;
                LPS[i++] = len;
            } else {
                if (len > 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return LPS[s.size() - 1];
    }
    string shortestPalindrome(string s) {
        string part1 = s;
        reverse(s.begin(), s.end());
        string part2 = s;
        string str = part1 + "#" + part2;
        
        int len = KMPtheorm(str);
        
        reverse(s.begin(), s.end());
        string ans = s.substr(len);
        
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
};