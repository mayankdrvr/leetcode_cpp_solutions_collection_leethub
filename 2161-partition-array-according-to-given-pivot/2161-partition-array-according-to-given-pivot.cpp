class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> sol;
        int len=nums.size(), count=0;
        for(int i=0;i<len;i++){
            if(nums[i]==pivot)
                count++;
            if(nums[i]<pivot)
                sol.push_back(nums[i]);
        }
        for(int i=1;i<=count;i++){
                sol.push_back(pivot);
        }
        for(int i=0;i<len;i++){
            if(nums[i]>pivot)
                sol.push_back(nums[i]);
        }
        return sol;
    }
};