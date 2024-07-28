class Solution 
{
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> adj[n+1];
        for(auto &itr : edges)
            adj[itr[0]].push_back(itr[1]), adj[itr[1]].push_back(itr[0]);
        queue<pair<int, int>> q;
        vector<int> dist1(n+1, -1), dist2(n+1, -1);
        q.push({1, 1});
        dist1[1] = 0;
        while(!q.empty())
        {
            int node = q.front().first, type = q.front().second;
            q.pop();
            int timeTaken = (type == 1) ? dist1[node] : dist2[node];
            if((timeTaken / change) % 2) // red light
                timeTaken = change * (timeTaken / change + 1) + time;
            else // green light
                timeTaken += time;
            for(auto itr : adj[node])
            {
                if(dist1[itr] == -1)
                    dist1[itr] = timeTaken, q.push({itr, 1});
                else if(dist2[itr] == -1 && dist1[itr] != timeTaken)
                {
                    if(itr == n)
                        return timeTaken;
                    dist2[itr] = timeTaken, q.push({itr, 2});
                }
            }
        }
        return 0;
    }
};