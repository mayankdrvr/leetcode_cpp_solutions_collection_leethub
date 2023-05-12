class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        map<int,int> m;
        for(int i=0;i<len;i++)
            m[nums[i]]=i;
        for(int i=0;i<len;i++)
        {
            if(m.find(target-nums[i])!=m.end() && m[target-nums[i]]!=i)
                return {i,m[target-nums[i]]};
        }
        return {};
    }
};