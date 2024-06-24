class Solution {
public:
    bool check(int src, vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i = 0; i < n; i++)
            color[i] = -1;
        queue<int>q;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();   q.pop();
            for(auto it : graph[node]) {
                if(color[it] == -1) {
                    q.push(it);
                    color[it] = !color[node];
                }
                else if(color[it] == color[node])   return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i = 0; i < n; i++) {
            bool ans = check(i, graph);
            if(!ans)    return false;
        }
        return true;
    }
};
