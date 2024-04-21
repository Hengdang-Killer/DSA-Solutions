class Solution 
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if(source == destination)
            return true;
        vector<int> adj[n];
        vector<int> vis(n, 0);
        for(auto &itr : edges)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &itr : adj[node])
            {
                if(!vis[itr])
                {
                    if(itr == destination)
                        return true;
                    q.push(itr), vis[itr]++;
                }
            }
        }
        return false;
    }
};