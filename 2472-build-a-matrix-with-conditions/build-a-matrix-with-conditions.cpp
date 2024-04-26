class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    int V = k;

    vector<int> adjList_row[V+1];
    vector<int> adjList_col[V+1];

    // Preparing adjList
    vector<int> indegree_row(V+1, 0);
    vector<int> indegree_col(V+1, 0);

    for(int i = 0; i < rowConditions.size(); i++)
    {
        adjList_row[rowConditions[i][0]].push_back(rowConditions[i][1]);
        indegree_row[rowConditions[i][1]]++;
    }

    for(int i = 0; i < colConditions.size(); i++)
    {
        adjList_col[colConditions[i][0]].push_back(colConditions[i][1]);
        indegree_col[colConditions[i][1]]++;
    }

    // Kahn's Algorithm
    queue<int> q_row;
    queue<int> q_col;
    for(int i = 1; i <= V; i++)
    {
        if(indegree_row[i] == 0) q_row.push(i);
        if(indegree_col[i] == 0) q_col.push(i);
    }
    
    vector<int> row;
    while(!q_row.empty())
    {
        int node = q_row.front();
        row.push_back(node);
        q_row.pop();

        for(int i = 0; i < adjList_row[node].size(); i++)
        {
            indegree_row[adjList_row[node][i]]--;
            if(indegree_row[adjList_row[node][i]] == 0) q_row.push(adjList_row[node][i]);
        }
    }

    if(row.size() < k)
    {
        vector<vector<int>> ans;
        return ans;
    }

    vector<int> col;
    while(!q_col.empty())
    {
        int node = q_col.front();
        col.push_back(node);
        q_col.pop();

        for(int i = 0; i < adjList_col[node].size(); i++)
        {
            indegree_col[adjList_col[node][i]]--;
            if(indegree_col[adjList_col[node][i]] == 0) q_col.push(adjList_col[node][i]);
        }
    }

    if(col.size() < k)
    {
        vector<vector<int>> ans;
        return ans;
    }

    vector<pair<int, int>> coordinates(V+1, {0, 0});

    for(int i = 0; i < V; i++)
    {
        coordinates[row[i]].first = i;
        coordinates[col[i]].second = i;
    }

    vector<vector<int>> ans(V, vector<int>(V, 0));

    for(int i = 1; i <= V; i++)
    {
        ans[coordinates[i].first][coordinates[i].second] = i;
    }

    return ans;
    }
};