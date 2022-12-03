class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> element_index;
        for(auto i=0;i<nums.size();i++){
            
            element_index[nums[i]]=i;
        }
        for(auto i=0;i<nums.size();i++){
            if(element_index.find(target-nums[i])!=element_index.end() && element_index[target-nums[i]]!=i)
                    return {i,element_index[target-nums[i]]};            
        }
        return {-1};
    }
};

/*
3 0
3 1






*/