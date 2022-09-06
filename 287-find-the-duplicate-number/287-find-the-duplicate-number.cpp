class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int len=nums.size(), res=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<len;i++){
            if(nums[i]==nums[i-1]){
                res=nums[i];
            }
        }
        return res;
    }
};