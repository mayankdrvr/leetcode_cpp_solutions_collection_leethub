class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sanity check, if the input array contains less than 3 element
        if (nums.size() < 3) {
            return {};
        }

        // heapsort, time: O(nlogn), space: O(1)
        sort(nums.begin(), nums.end());	
	
        vector<vector<int>> res;
        for (int k = 2; k < nums.size(); k++) {
            // k should be rightmost index of the duplicate group
            while (k + 1 < nums.size() && nums[k + 1] == nums[k]) {
                k++;
            }
            
            two_sum(res, nums, k);
        }
        return res;
    }

private:
    // time: O(n), space: O(1)
    void two_sum(vector<vector<int>>& res, const vector<int>& nums, int k) {
        int i = 0, j = k - 1;
        int target = 0 - nums[k];

        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                res.push_back({nums[i], nums[j], nums[k]});
                // move j to rightmost index of a new duplicate group
                while (j - 1 >= 0 && nums[j - 1] == nums[j]) {
                    j--;
                }
                j--;
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
    }
};
