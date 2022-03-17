class Solution {
public:
    int randomSelect(vector<int>& nums, int lo, int hi, int k) {
        if (lo == hi) 
            return nums[lo];
        
        int q = randomPartition(nums, lo, hi);
        int i = hi - q + 1;
        
        if (k == i) return nums[q];
        else if (k > i) return randomSelect(nums, lo, q-1, k-i);
        return randomSelect(nums, q+1, hi, k);
        
    }
    
    int randomPartition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] <= pivot)
                swap(nums[i++], nums[j]);
        }
        
        swap(nums[i], nums[r]);
        
        return i;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return randomSelect(nums, 0, nums.size()-1, k);
    }
};