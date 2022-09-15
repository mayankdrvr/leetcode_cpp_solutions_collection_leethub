class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        string res = "";
        vector<string> strNums(size, "");
        for (int i = 0; i < size; i++) {
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b){
            return ((a+b) > (b+a));
        });
        
        for (auto num : strNums) {
            res += num;
        }
        
        return res[0] == '0' ? "0" : res;
    }
};