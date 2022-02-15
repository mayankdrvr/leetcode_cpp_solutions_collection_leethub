class Solution {
public:
    double findPath(vector<vector<double>>& graph,int n,int src,int dst,vector<bool>& visited){
    
    //basically here you have to find out the path starting from the vertex u and ending at vertex v
    //and multiply there weight as we progress
    visited[src] = true;
    if(visited[dst] == true)    return (double)1.0;
    
    for(int i=0;i<graph[src].size();i++){
        int neighbour = i;
        double weight = graph[src][i];
        if(weight != -1.0){
            if(!visited[neighbour]){
                double temp = (double)findPath(graph,n,neighbour,dst,visited);
                if(temp >=0) return (double)((double)weight * temp);
            }
        }
        
    }
    
    return (double)-1.0;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        
        int count = 0;
        
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            if(mp.find(u) == mp.end()){
                mp[u] = count++;
            }
            if(mp.find(v) == mp.end()){
                mp[v] = count++;
            }
        }
        
        int n = count;
        //n  corresponds to the no. of the vertices in the graph
        vector<vector<double>> graph(n,vector<double>(n,-1.0));
        //-1.0 in the graph indicates that no valid path or edge exists between u and v
        
        //fill the weight in graph using values(vector)
        
        for(int i=0;i<equations.size();i++){
            
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            
            graph[u][v] = values[i];
            graph[v][u] = (double)((double)1.0/values[i]);      //this part in the problem is really cool
        }
        
        //now we are set and from this point run all the queries before checking there validity
        vector<double> result;
        
        for(int i=0;i<queries.size();i++){
            
            string uSrc = queries[i][0];
            string vDst = queries[i][1];
            
            if(mp.find(uSrc) != mp.end() && mp.find(vDst) != mp.end()){
                
                if(uSrc == vDst){
                    result.push_back((double)1.0);
                }else{
                    int u = mp[uSrc];
                    int v = mp[vDst];
                    vector<bool> visited(n,false);
                    double ans = findPath(graph,n,u,v,visited);
                    result.push_back(ans);
                }
                
            }else{
                result.push_back((double)-1.0);
            }
            
        }
        
        return result;
    }
};