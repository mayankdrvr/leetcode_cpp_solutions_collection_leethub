class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> T(s.length()+1, vector<bool>(p.length()+1, false));

        T[0][0] = true;
        //Deals with patterns like a* or a*b* or a*b*c*
        for (int i = 1; i < T[0].size(); i++) {
            if (p[i-1] == '*') {
                T[0][i] = T[0][i - 2];
            }
        }

        for (int i = 1; i < T.size(); i++) {
            for (int j = 1; j < T[0].size(); j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    T[i][j] = T[i-1][j-1];
                } else if (p[j - 1] == '*')  {
                    T[i][j] = T[i][j - 2];
                    if (p[j-2] == '.' || p[j - 2] == s[i - 1]) {
                        T[i][j] = T[i][j] | T[i - 1][j];
                    }
                } else {
                    T[i][j] = false;
                }
            }
        }
        return T[s.length()][p.length()];
    }
};