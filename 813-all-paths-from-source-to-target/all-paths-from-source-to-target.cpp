class Solution {
private:
vector<vector<int>> dfs(int node, int des, vector<vector<int>>& graph, vector<vector<int>> trace[])
{
    if(node == des)
    {
        return trace[node] = {{node}};
    }

    if(trace[node].size() != 0) return trace[node];

    for(int i = 0; i < graph[node].size(); i++)
    {
        int adjNode = graph[node][i];

        vector<vector<int>> v = dfs(adjNode, des, graph, trace);
        for(int i = 0; i < v.size(); i++)
        {
            v[i].push_back(node);
            trace[node].push_back(v[i]);
        }
    }

    return trace[node];
}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int N = graph.size();
    // Lets trace all the paths from ith node to the (N-1)th node and store them.
    vector<vector<int>> trace[N];

    dfs(0, N-1, graph, trace);

    for(int i = 0; i < trace[0].size(); i++)
    {
        reverse(trace[0][i].begin(), trace[0][i].end());
    }

    return trace[0];
    }
};