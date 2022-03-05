class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max_int = *max_element(nums.begin(), nums.end());
        
        vector<int> number_sum(max_int+1, 0);
        
        vector<vector<int>> dp(2, number_sum);

        for (int i = 0; i < nums.size(); i++) {
            number_sum[nums[i]] += nums[i];
        }
        
        for (int i = 1; i < number_sum.size(); i++) {
            if (number_sum[i] != 0) {
                if (i == 1) {
                    dp[0][i] = dp[1][i-1] + number_sum[i];
                } else {
                    dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + number_sum[i];
                }
                
                dp[1][i] = dp[0][i-1];
            } else {
                int current_max = max(dp[0][i-1], dp[1][i-1]);
                dp[0][i] = current_max;
                dp[1][i] = current_max;
            }
            
        }
        
        int result = max(dp[0][number_sum.size()-1], dp[1][number_sum.size()-1]);
        
        return result;
        
    }
};