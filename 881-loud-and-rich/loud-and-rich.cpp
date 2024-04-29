class Solution {
private:
int RichandLoud(int node, vector<int> adjList[], vector<bool>& visited, vector<int>& quiet, vector<int>& ans)
{
    if(adjList[node].size() == 0) return ans[node];
    int q = quiet[node];
    for(int i = 0; i < adjList[node].size(); i++)
    {
        if(!visited[adjList[node][i]])
        {
            visited[adjList[node][i]] = 1;
            
            int child = RichandLoud(adjList[node][i], adjList, visited, quiet, ans);

            if(q > quiet[child]) 
            {
                q = quiet[child];
                ans[node] = child;
            }
            
        }
        else
        {
            int child = ans[adjList[node][i]];

            if(q > quiet[child]) 
            {
                q = quiet[child];
                ans[node] = child;
            }
        }
    }

    return ans[node];
}
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int N = quiet.size();
    vector<int> adjList[N];

    for(int i = 0; i < richer.size(); i++)
    {
        // poor --> richer
        adjList[richer[i][1]].push_back(richer[i][0]);
    }

    vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) ans[i] = i;

    vector<bool> visited(N, 0);
    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            RichandLoud(i, adjList, visited, quiet, ans);
        }
    }

    return ans;
    }
};