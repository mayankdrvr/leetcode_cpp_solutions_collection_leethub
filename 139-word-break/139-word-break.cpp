class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        // we mark as true every index that we managed to segment so far
        for (int i=1; i<=s.size(); i++)
            for (int j=0; j<i; j++){
                
                if ((dp[j]) && (std::find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())) {
                    dp[i] = true;
                    break;
                }
                //cout<<"dp["<<i<<"]"<<" "<<dp[i]<<endl;
            }
        for(int i=0;i<dp.size();i++)
            cout<<dp[i]<<endl;
        return dp.back();   
    }
};