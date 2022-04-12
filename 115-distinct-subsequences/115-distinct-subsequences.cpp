class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n=t.size();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        
        for(int i=0;i<=m;i++)
            dp[i][0] = 1;// put 1 in first row because an empty string is subsequence of all
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])//if the last char of both the string are same then consider these two cases: 
                    //1. all substring without the last char in s string
                    //2. all substring without the last char in both the strings i.e. in s and t both
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    //the last char of the strings doesn't match then the value is same as the value without last character
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];// the last element will contain the max  num of distinct subsequence
    }
};