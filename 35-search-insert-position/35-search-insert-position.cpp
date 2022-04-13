class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        if(target<nums[0])
            return 0;
        if(target>nums[len-1])
            return len;
        int s=0,e=len-1,mid;
        while(s<=e){
            mid=(s+e)/2;
            if(target==nums[mid])
                return mid;              
            else if(target>nums[mid])
                s=mid+1;
            else if(target<nums[mid])
                e=mid-1;
        }
        return s;
    }
};