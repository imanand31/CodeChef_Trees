class Solution {
public:

    vector<int> visited;
    void bfs(int x,vector<vector<int>>& rooms){
        queue<int> q;
        q.push(x);
        visited[x]=1;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(auto &nb:rooms[i]){
                if(visited[nb]!=-1 ){
                    continue;
                }
                q.push(nb);
                visited[nb]=1;
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        visited.resize(n,-1);
        bfs(0, rooms);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                return false;
            }
        }
        return true;
    }
};