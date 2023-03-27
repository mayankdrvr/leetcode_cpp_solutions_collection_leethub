class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){      
		//Efficient Solution TimeO(N) & Auxiliary Space O(N)
        int length=nums.size();
        unordered_map<int,int> map;
        for(auto i=0;i<length;i++){
            if(map.find(target-nums[i])!=map.end()){
                return {i,map[target-nums[i]]};
        }
        map[nums[i]]=i;
        }
        return {};
    }
};