class Solution {
public:
    vector<int> vis;
    vector<int> ans;

    bool dfs(int node, vector<vector<int>>& adj){
        vis[node] = 0;

        for(auto it : adj[node]){
            if(vis[it] == 0) return true;

            if(vis[it] == -1){
                if(dfs(it, adj)) return true;
            }
        }

        vis[node] = 1;
        ans.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {

        vis = vector<int>(numCourses, -1);

        vector<vector<int>> adj(numCourses);

        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(vis[i] == -1){
                if(dfs(i, adj)) return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};