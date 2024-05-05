class Solution {
private:
long long numOfways(int node, int dest, vector<int> parent[], vector<long long>& ways)
{
    int mod = (int)1e9 + 7;
    if(node == dest) return 1;
    if(ways[node] != 0) return ways[node];

    for (int i = 0; i < parent[node].size(); i++)
    {
        ways[node] = (numOfways(parent[node][i], dest, parent, ways) + ways[node])%mod;
    }

    return ways[node]%mod;
}
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    int mod = 1e9 + 7;
    int N = n;
    int E = roads.size();
    // Given an Undirected and connected Graph. 
    // We have to return the number of ways to arrive the N-1th node from the 0th node in shortest time.

    // S-1 : store all the edges when the condition, time[u] + W = time[v] is met, as an edge.
    
    vector<pair<int, int>> adjList[N];

    for (int i = 0; i < E; i++)
    {
        adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adjList[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    
    vector<long long> time(N, LLONG_MAX);
    vector<int> parent[N];
    
    // src = 0;

    time[0] = 0;
    
    set<pair<long long, int>> st;
    st.insert({time[0], 0});

    while (!st.empty())
    {
        auto it  = *st.begin();
        st.erase(it);

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
                st.insert({time[m], m});
                parent[m].clear();
                parent[m].push_back(node);
            }
            else if((T + t) == time[m]) parent[m].push_back(node);
            
        }
    }
    
    // Now we are having a DAG as parent.
    // So, backtrack from destination node to the start node using the edges stored in parent.

    vector<long long> ways(N, 0);

    return numOfways(N-1, 0, parent, ways);
    }
};