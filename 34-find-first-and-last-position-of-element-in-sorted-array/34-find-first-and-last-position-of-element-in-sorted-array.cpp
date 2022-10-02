class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2, -1);
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        int index = -1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target){
                index = i;
                break;
            }
        if(index != -1){
            ans[0] = index;
            ans[1] = index + mp[target] - 1;
        }
        return ans;
    }
};