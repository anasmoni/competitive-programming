class Solution {
     
     // low[u] -- >> min disc time of vertex that can be reached from subtree rooted at u
     
    vector<int>g[100005];
    vector<int>low, disc, parent;
    vector<vector<int> >res;
    vector<bool>vis;
    int time;
public:
    
    
    
    void dfs(int u){
        vis[u] = true;
        disc[u] = low[u] = ++time;
        
        for(int v : g[u]){
            if(vis[v] == false){
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if(low[v]>disc[u]){
                    res.push_back({u,v});
                }
            }
            else if(parent[u] != v) low[u] = min(low[u], disc[v]);
            
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vis = vector<bool>(n,false);
        parent = vector<int>(n,-1);
        low = vector<int>(n,-1);
        disc = vector<int>(n,-1);
        res.clear();
        time = 0;
        
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][1];
            int v = connections[i][0];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        return res;
    }
};
