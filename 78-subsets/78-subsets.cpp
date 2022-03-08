class Solution {
    vector<vector<int>> sol;
public:
    void generate(vector<int> &subset, int i, vector<int> &nums){
        if(i==nums.size()){
            sol.push_back(subset);
            return;
        }
        generate(subset, i+1, nums);
        subset.push_back(nums[i]);
        generate(subset, i+1, nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0, len=nums.size()-2;
        vector<int> subset;
        generate(subset, i, nums);
        return sol;
    }
};