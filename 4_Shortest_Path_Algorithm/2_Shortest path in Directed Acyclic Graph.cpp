class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>>adj[N];
        for(auto it : edges)
            adj[it[0]].push_back({it[1], it[2]});
        vector<int>dist(N, 1e9);
        queue<int>q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()) {
            int node = q.front();   q.pop();
            for(auto it : adj[node]) {
                int adjNode = it.first, weight = it.second;
                if(dist[node]+weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                    q.push(adjNode);
                }
            }
        }
        vector<int>ans(N, -1);
        for(int i = 0; i < N; i++) {
            if(dist[i]!=1e9)
                ans[i] = dist[i];
        }
        return ans;
    }
};
