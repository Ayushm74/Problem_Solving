class Solution {
public:
    void dfs(int i, vector<int> & vis, vector<vector<int>> &adj){
        vis[i] = 1;
        
        for (auto it : adj[i]) {
        if (!vis[it]) {
            dfs(it, vis, adj);
        }
}
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    //    vector<vector<int>> adj;
        int n = isConnected.size();
        int m = isConnected[0].size();
         vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        vector<int> vis(n,0);
        for(int i = 0;i<n;i++){
            
            if(vis[i]== 0){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};