class Solution {
bool isSafe(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& safe)
{
    if(graph[node].size() == 0) return safe[node] = true;

    for(int i = 0; i < graph[node].size(); i++)
    {
        if(!visited[graph[node][i]])
        {
            visited[graph[node][i]] = 1;
            if(isSafe(graph[node][i], graph, visited, safe) == false) return safe[node] = false;
        }
        else if(safe[graph[node][i]] == 0)
        {
            // if adj node is already visited then there exists a cycle.
            // a cycle will never lead to a terminal node.
            return safe[node] = false;
        }
    }

    return safe[node] = true;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<bool> visited(N, 0);
    vector<bool> safe(N, 0);

    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            isSafe(i, graph, visited, safe);
        }
    }

    vector<int> ans;

    for(int i = 0; i < N; i++)
    {
        if(safe[i] == 1) ans.push_back(i);
    }

    return ans;
    }
};