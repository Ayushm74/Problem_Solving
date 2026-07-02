class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis,  vector<int>& inrec){
        vis[i] = 1;
        inrec[i] = 1;

        for(auto it : adj[i]){
            if(vis[it] == 0 && !dfs(it,adj,vis,inrec)){
                return false;
            }
            if(inrec[it] != 0){
                return false;
            }
        }
        inrec[i] = 0;
        return true;
        
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n+1);
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,0);
        vector<int> inrec(n+1,0);
        for(int i = 0;i<n;i++){
            if(vis[i] == 0 && !dfs(i,adj, vis,inrec)){
                return false;
            }
        }
        return true;
    }
};