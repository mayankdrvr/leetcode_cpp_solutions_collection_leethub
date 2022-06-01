class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size(), meh=0, msf=INT_MIN;
        for(int i=0;i<len;i++){
            meh+=nums[i];
            if(meh>msf)
                msf=meh;
            if(meh<0)
                meh=0;
        }
        return msf;
    }
};