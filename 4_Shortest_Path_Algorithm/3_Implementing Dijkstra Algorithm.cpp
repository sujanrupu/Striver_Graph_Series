class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V, 1e9);
        dist[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, S});
        while(!pq.empty()) {
            auto top = pq.top();    pq.pop();
            int dis = top.first, node = top.second;
            for(auto it : adj[node]) {
                int adjNode = it[0], weight = it[1];
                if(dis+weight < dist[adjNode]) {
                    dist[adjNode] = dis+weight;
                    pq.push({dis+weight, adjNode});
                }
            }
        }
        return dist;
    }
};
