class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int u, v, len=edges.size(),curr,second;
        vector<vector<int>> adj(n);
        for(int i=0;i<len;i++){
            u=edges[i][0];
            v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> seen(n,false);
        q.push(source);
        seen[source]=true;
        while(!q.empty()){
            curr=q.front();
            for(int i=0;i<adj[curr].size();i++){
                second=adj[curr][i];
                if(!seen[second]){
                    q.push(second);
                    seen[second]=true;
                }
            }
            q.pop();
        }
        if(seen[destination])
            return true;
        else
            return false;
    }
};