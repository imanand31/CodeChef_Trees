
int parent[100005];
vector<int> adj[100005];
void dfs(int cur,int par){
    parent[cur]=par;
    for(auto &nb:adj[cur]){
        if(nb==par){
            continue;
        }
        
        dfs(nb,cur);
    }
}


int kthAncestor(int n, vector<vector<int>> &edges, int v, int k) {
    // write your code here 
    
  
    int ctr=0;
    
    int u,b;
    
    for(auto &edge:edges){
        u=edge[0];
        b=edge[1];
        adj[u].push_back(b);
        adj[b].push_back(u);
    }
    
      dfs(1,-1);
    
    while(ctr<k && v!=-1){
        v=parent[v];
        ctr++;
    }
    
    return v;
    
    
    
}