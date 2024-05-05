class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& [adjNode, wt] : adj[node]) {
                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                    ways[adjNode] = ways[node];
                } else if (dis + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};