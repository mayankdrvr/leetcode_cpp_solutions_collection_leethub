class Solution {
public:
    void backtrack(int n,int k,vector<int> &curr,vector<vector<int> >&ans,int num){
        curr.push_back(num);
        if(curr.size()==k){
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        for(int i=num+1;i<=n;i++){
            backtrack(n,k,curr,ans,i);
        }
        curr.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> curr;
        for(int i=1;i<=n;i++){
            backtrack(n,k,curr,ans,i);
        }
        return ans;
    }
};