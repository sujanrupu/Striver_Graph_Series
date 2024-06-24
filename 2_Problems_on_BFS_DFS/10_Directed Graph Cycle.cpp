class Solution {
  public:
    bool check(int src, vector<int>adj[], unordered_map<int, bool>& vis, unordered_map<int, bool>& dfsVis) {
        vis[src] = 1;
        dfsVis[src] = 1;
        for(auto it : adj[src]) {
            if(!vis[it]) {
                bool ans = check(it, adj, vis, dfsVis);
                if(ans) return true;
            }
            else if(dfsVis[it] == true) return true;
        }
        dfsVis[src] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool>vis, dfsVis;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                bool ans = check(i, adj, vis, dfsVis);
                if(ans) return true;
            }
        }
        return false;
    }
};
