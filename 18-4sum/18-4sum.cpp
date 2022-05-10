class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len=nums.size();
        vector<vector<int>> res;
        if(len<=3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            for(int j=i+1;j<len-2;j++){
                int tar=target-nums[i]-nums[j];
                int k=j+1, l=len-1;
                while(k<l){
                    if(nums[k]+nums[l]<tar)
                        k++;
                    else if(nums[k]+nums[l]>tar)
                        l--;
                    else{
                        vector<int> q(4,0);
                        q[0]=nums[i];
                        q[1]=nums[j];
                        q[2]=nums[k];
                        q[3]=nums[l];
                        res.push_back(q);
                        while(k<l && nums[k]==q[2])
                            k++;
                        while(k<l && nums[l]==q[3])
                            l--;
                    } 
                }
                while(j+1<len && nums[j]==nums[j+1])
                            j++;
            }
            while(i+1<len && nums[i]==nums[i+1])
                            i++;
        }
        return res;
    }
};