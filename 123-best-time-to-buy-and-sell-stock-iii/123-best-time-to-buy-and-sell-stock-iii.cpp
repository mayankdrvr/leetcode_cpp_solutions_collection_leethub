class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int len=prices.size();
        if(len<2)
            return 0;
        int result=0;
        int Pmin=prices[0],Pmax=prices[len-1];
        vector<int> Profit1(len,0);
        vector<int> Profit2(len,0);
        for(int i=1;i<len;i++)
        {   Profit1[i]=max(Profit1[i-1],prices[i]-Pmin);
            Pmin=min(Pmin,prices[i]);
            int j=len-1-i;
            Profit2[j]=max(Profit2[j+1],Pmax-prices[j]);
            Pmax=max(Pmax,prices[j]);  
        }
        for(int i=1;i<len;i++)
        {
            if(Profit1[i]+Profit2[i]>=result)
            result=Profit1[i]+Profit2[i];
        }
            return result;
    }
};