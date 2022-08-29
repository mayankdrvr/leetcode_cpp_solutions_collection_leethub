class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> s,s2;
        int len=trust.size();
        double sum=0, sum2=0;
        for(int i=0;i<len;i++){
            s.insert(trust[i][0]);
            //s2.insert(trust[i][1])
        }
        if(s.size()==n-1){
                for(int i=1;i<=n;i++)
                            sum+=i;
                for(auto it=s.begin();it!=s.end();it++)
                        sum2+=*it; 
                int sol=sum-sum2;
                for(int i=0;i<len;i++){
                    if(trust[i][1]==sol)
                        s2.insert(trust[i][0]);
            }
            if(s2.size()==n-1)
                return sol;
        }
        
            return -1;
    }
};