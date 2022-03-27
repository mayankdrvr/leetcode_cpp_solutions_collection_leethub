class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> sol;
        if(nums.size()==1)
            return sol;
        for(int i=0;i<nums.size();i++){
            int idx=abs(nums[i])-1;
            if (nums[idx]>0)
                nums[idx] =(-nums[idx]);
            else 
                sol.push_back(abs(nums[i]));
        }
        return sol;
    }
};