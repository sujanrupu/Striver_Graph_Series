class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        for(auto it : prerequisites)
            adj[it[0]].push_back(it[1]);
        unordered_map<int, int>indegree;
        vector<int>ans;
        for(int i = 0; i < n; i++) {
	        for(auto it : adj[i])
	            indegree[it]++;
	    }
	    queue<int>q;
	    for(int i = 0; i < n; i++) {
	        if(indegree[i] == 0)    q.push(i);
	    }
	    while(!q.empty()) {
	        int node = q.front();   q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0)
	                q.push(it);
	        }
	    }
        if(ans.size() == n) return true;
        return false;
    }
};
