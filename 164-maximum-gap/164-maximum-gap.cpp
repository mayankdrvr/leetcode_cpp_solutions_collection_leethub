class Solution {
public:
    int MAX = 2*1e9;
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int res = 0;
        int big = *max_element(nums.begin(), nums.end());
        int smol = *min_element(nums.begin(), nums.end());
        int mindiff = (big-smol+n-2)/(n-1);
        if(mindiff==0) return 0;
        vector<pair<int,int>> mm(n);
        for(int i=0; i<n; i++){
            mm[i].first = MAX+1;
            mm[i].second = -1;
        }
        for(int i=0; i<n; i++){
            int x = (nums[i]-smol)/mindiff;
            mm[x].first = min(nums[i],mm[x].first);
            mm[x].second = max(nums[i],mm[x].second);
        }
        int i=1;
        int prev=mm[0].second;
        while(prev==-1) prev=mm[i++].second;
        while(i<n){
            while(i<n && mm[i].first==MAX+1) i++;
            if(i==n) break;
            int diff = mm[i].first-prev;
            res = max(res,diff);
            prev = mm[i++].second;
        }
        return res;
        
    }
};