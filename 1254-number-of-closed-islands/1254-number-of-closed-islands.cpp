class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j){
        
        // Just the normal limits check and condition check  
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1)
            return;
        
        //update the value from Water To Land
        grid[i][j]=1;
        
        // DFS in all 4 directions
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        // Update all the corners which are of no use from land to water through DFS
        for(int i=0;i<m;i++){
            if(grid[i][0]==0)
                dfs(grid,i,0);
            if(grid[i][n-1]==0)
                dfs(grid,i,n-1);
        }
        // Update all the corners which are of no use from land to water through DFS
        for(int i=0;i<n;i++){
            if(grid[0][i]==0)
                dfs(grid,0,i);
            if(grid[m-1][i]==0)
                dfs(grid,m-1,i);
        }
        
        int count=0;
        
        //Now Count all the island present inside and return answer
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
};