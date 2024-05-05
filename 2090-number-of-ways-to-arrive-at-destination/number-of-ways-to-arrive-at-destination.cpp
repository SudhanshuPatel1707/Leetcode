class Solution {

public:
    int countPaths(int n, vector<vector<int>>& roads) {
    int N = n;
    int E = roads.size();
    
    vector<pair<int, int>> adjList[N];

    for (int i = 0; i < E; i++)
    {
        adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adjList[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    
    vector<long long> time(N, LLONG_MAX);
    vector<long long> ways(N, 0);
    
    // src = 0;

    time[0] = 0;
    ways[0] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;      // {level, node};
    pq.push({time[0], 0});
    
    int mod = (int)1e9 + 7;
    while (!pq.empty())
    {
        auto it  = pq.top();
        pq.pop();

        int node = it.second;
        long long T = it.first;

        for (int i = 0; i < adjList[node].size(); i++)
        {
            int m = adjList[node][i].first;
            long long t = adjList[node][i].second;

            // Our destination is (N-1)th node so will not pass through it we will just arrive it.
            
            if((T + t) < time[m]) 
            {
                time[m] = (T + t);
                pq.push({time[m], m});
                ways[m] = ways[node];
            }
            else if((T + t) == time[m]) ways[m] = (ways[m] + ways[node])%mod;
        }
    }
        
    return ways[N-1]%mod;
    }
};