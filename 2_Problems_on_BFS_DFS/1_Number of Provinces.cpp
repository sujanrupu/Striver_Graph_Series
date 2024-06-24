class Solution {
public:
    void dfs(int src, unordered_map<int, bool>& vis, vector<int>adj[]) {
        vis[src] = 1;
        for(auto it : adj[src]) {
            if(!vis[it])
                dfs(it, vis, adj);
        }
    }

    int findCircleNum(vector<vector<int>>& ic) {
        int n = ic.size(), m = ic[0].size();
        vector<int>adj[n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ic[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        unordered_map<int, bool>vis;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                ans++;
            }
        }
        return ans;
    }
};
