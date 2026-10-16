class Solution {
public:
    vector<int> dist;
    vector<vector<int>> adj;
    void bfs(int x){
        queue<int> q;
        q.push(x);
        dist[x]=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(auto &nb:adj[i]){
                if(dist[nb]!=-1){
                    continue;
                }
                dist[nb]=dist[i]+1;
                q.push(nb);
            }
        }


    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n);
        dist.resize(n,-1);

        for(int i=0;i<edges.size();i++){
            int a,b;
            a=edges[i][0];
            b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(source);
        return dist[destination]!=-1;
    }
};