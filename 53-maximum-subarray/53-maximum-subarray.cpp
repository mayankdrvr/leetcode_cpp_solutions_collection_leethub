class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c=0,m=INT_MIN;
        if(nums.size()==1)
            return nums[0];
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
            m=max(m,c);
            if(c<0)
                c=0;
        }
        return m;
    }
};