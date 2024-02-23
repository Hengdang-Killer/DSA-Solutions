class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<pair<int, int>> adj[n];
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (auto &itr : flights)
            adj[itr[0]].push_back({itr[1], itr[2]});
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
        while (!q.empty() && stops <= k) 
        {
            int sz = q.size();
            while (sz--) 
            {
                auto [node, distance] = q.front();
                q.pop();
                if (adj[node].empty()) 
                    continue;
                for (auto &[neighbour, price] : adj[node]) 
                {
                    if (price + distance >= dist[neighbour]) 
                        continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};