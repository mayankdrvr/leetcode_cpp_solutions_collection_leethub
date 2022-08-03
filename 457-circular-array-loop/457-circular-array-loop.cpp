class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        //cout<<(-5%5);
        //return true;
        
        
        int len=nums.size(),k=0,j=0;
         //cout<<nums.size();
        if(len==0)
            return false;
        bool res=false;
        int B[len]; 
        for (int m = 0; m < len; m++)
            {
              B[m] = 0;
            }
        for(int i=0;i<len;i++)
        {
            j=i;
            B[j]+=1;
            if(nums[i]>0)
                k=1;
            if(nums[i]<0)
                k=-1;
            while(k*nums[j]>0 && res==false)
            {
                j=(nums[j]+j)%len;
               // cout<<j;
                //cout<<j<<" ";
                if(j<0)
                    j+=len;
                B[j]+=1;
                if(nums[j]%len==0)
                    break;
                if(B[j]==2)
                res=true;
               
            }
            for (int m = 0; m < len; m++)
            {
              B[m] = 0;
            }
            if(res==true)
                break;
        }
        return res;
    }
};