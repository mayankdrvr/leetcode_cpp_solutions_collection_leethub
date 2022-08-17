class Solution {
public:
string shortestPalindrome(string s)
{
    int n = s.size();
    string rev(s);
    string str(s);
    reverse(rev.begin(),rev.end());
    s=s+"#"+rev;
    int lps[s.size()];
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < s.size())
    {
        if (s[j] == s[i])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    int k=lps[s.size()-1];
    return rev.substr(0,n-k)+str;
    
}
    
    
};