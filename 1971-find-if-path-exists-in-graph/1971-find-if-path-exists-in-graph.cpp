class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& visited, int curr, int end){
        if(curr==end)
            return true;
        if(visited[curr])
            return false;
        visited[curr]=1;
        for(int i=0;i<g[curr].size();i++){
            if(dfs(g, visited, g[curr][i], end)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n);
        return dfs(g, visited, source, destination);
    }
};