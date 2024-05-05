class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    // Given N nodes, E edges ---> representing an UG 
    // with edgeweights => probability of success of traversing that edge = succProb[i].
    // find the path with the maximum probability of success to go from start to end and return its success probability.

    vector<pair<int, double>> adjList[n];

    for(int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    vector<double> maxProb(n, 0.00);
    maxProb[start_node] = 1.00;
    priority_queue<pair<double, int>> pq;
    pq.push({maxProb[start_node], start_node});

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        double P = it.first;

        for(int i = 0; i < adjList[node].size(); i++)
        {
            int adjNode = adjList[node][i].first;
            double p = adjList[node][i].second;

            if(P*p > maxProb[adjNode])
            {
                maxProb[adjNode] = P * p;
                pq.push({maxProb[adjNode], adjNode});
            }
        }
    }

    return maxProb[end_node];
    }
};