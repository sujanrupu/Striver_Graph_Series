class Solution {
  public:
    void dfs(int src, vector<int>adj[], unordered_map<int, bool>& vis, vector<int>& ans) {
        vis[src] = 1;
        ans.push_back(src);
        for(auto it : adj[src]) {
            if(!vis[it])
                dfs(it, adj, vis, ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int, bool>vis;
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                dfs(i, adj, vis, ans);
        }
        return ans;
    }
};
