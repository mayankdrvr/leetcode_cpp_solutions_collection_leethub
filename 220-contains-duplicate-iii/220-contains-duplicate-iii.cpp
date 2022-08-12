class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> set;
        for(int i = 0; i < nums.size(); i++){
            if(!set.empty()){
                auto p1 = set.lower_bound(nums[i]); 
                if(p1 != set.end() && (long long)(*p1) - nums[i] <= t || p1 != set.begin() && nums[i] - (long long)(*prev(p1)) <= t){
                    return true;
                }
            }
            
            set.insert(nums[i]);
            if(i - k >= 0){
                set.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};