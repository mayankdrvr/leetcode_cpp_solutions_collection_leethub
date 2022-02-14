class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len=nums.size();
        unordered_map<int,int> m;
        if(len==2)
            return {0,1};
        for(int i=0;i<len;i++){
            m[nums[i]]=i;
        }
        
        for(int i=0;i<len;i++){
            cout<<i<<" "<<m[nums[i]]<<endl;
            if(m.find(target-nums[i])!=m.end() && m[target-nums[i]]!=i)
                return {i,m[target-nums[i]]};
        }
    return {};
    }
};