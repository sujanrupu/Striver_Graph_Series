class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>>adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
        pq.push({0, 0});
        vector<long long>dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<long long>parent(n, 0);
        parent[0] = 1;
        long long mod = 1e9 + 7;
        while(!pq.empty()) {
            auto top = pq.top();    pq.pop();
            long long dis = top.first, node = top.second;
            for(auto it : adj[node]) {
                long long adjNode = it.first, weight = it.second;
                if(dis + weight < dist[adjNode]) {
                    dist[adjNode] = dis + weight;
                    pq.push({dis + weight, adjNode});
                    parent[adjNode] = parent[node];
                }
                else if(dis + weight == dist[adjNode]) 
                    parent[adjNode] = (parent[node] + parent[adjNode])%mod;
            }
        }
        return parent[n-1]%mod;
    }
};
