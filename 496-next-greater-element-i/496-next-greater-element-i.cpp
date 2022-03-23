class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        // support variables
        int len1 = n1.size(), len2 = n2.size();
        vector<int> res(len1, -1);
        if (!len2) return res;
        // dp array and stack replacement array; pos == -1 means empty stack
        int dp[len2], s[len2], pos = -1;
        unordered_map<int, int> matches;
        // marking all the necessary keys in matches
        for (auto n: n1) matches[n] = -1;
        // going to populate both the dp table and
        for (int i = len2 - 1, n; i >= 0; i--) {
            n = n2[i];
            // updating matches if it is a necessary key for later
            if (matches.find(n) != end(matches)) {
                matches[n] = i;
            }
            // working with the array to populate dp
            while (pos > -1 && s[pos] <= n) pos--;
            if (pos == -1) dp[i] = -1;
            else dp[i] = s[pos];
            s[++pos] = n;
        }
        for (int i = 0; i < len1; i++) {
            res[i] = dp[matches[n1[i]]];
        }
        return res;
    }
};