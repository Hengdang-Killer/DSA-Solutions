class Solution 
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(n == 1)
            return {0};
        if(n == 2)
            return {0, 1};
        vector<int> deg(n, 0), adj[n];
        for(auto &itr : edges)
        {
            deg[itr[0]]++, deg[itr[1]]++;
            adj[itr[0]].push_back(itr[1]), adj[itr[1]].push_back(itr[0]);
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(deg[i] == 1)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.clear();
            int sz = q.size();
            while(sz--)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto &itr : adj[node])
                {
                    deg[itr]--;
                    if(deg[itr] == 1)
                        q.push(itr);
                }
            }
        }
        return ans;
    }
};