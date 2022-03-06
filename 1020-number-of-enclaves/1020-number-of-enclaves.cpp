class Solution {
public:
    void dfs(int i,int j,int r,int c,vector<vector<int>>& A)
    {   if(i<0||j<0||i>=r||j>=c||A[i][j]!=1) return;
        if(A[i][j]==1)
        {    A[i][j]=0;
             dfs(i+1,j,r,c,A);
             dfs(i-1,j,r,c,A);
             dfs(i,j+1,r,c,A);
             dfs(i,j-1,r,c,A);
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        int r=A.size();
        if(r==0) return 0;
        int c=A[0].size();
        for(int i=0;i<r;i++)
        {   dfs(i,0,r,c,A);
            dfs(i,c-1,r,c,A);
        }
        for(int j=0;j<c;j++)
        {   dfs(0,j,r,c,A);
            dfs(r-1,j,r,c,A);
        }
        int ans=0;
        for(int i=0;i<r;i++)
        {   for(int j=0;j<c;j++)
            {   if(A[i][j]==1) 
                ans++;
            }
        }
        return ans;
    }
};
