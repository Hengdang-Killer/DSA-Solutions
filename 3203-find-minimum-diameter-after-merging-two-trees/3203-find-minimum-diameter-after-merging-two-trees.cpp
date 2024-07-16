class Solution 
{
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int v1 = 0, v2 = 0;
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> inDegree1(n, 0), inDegree2(m, 0), adj1[n], adj2[m];
        for(int i = 0; i < n-1; i++)
        {
            adj1[edges1[i][0]].push_back(edges1[i][1]), adj1[edges1[i][1]].push_back(edges1[i][0]); 
            inDegree1[edges1[i][0]]++, inDegree1[edges1[i][1]]++;
        }
        for(int i = 0; i < m-1; i++)
        {
            adj2[edges2[i][0]].push_back(edges2[i][1]), adj2[edges2[i][1]].push_back(edges2[i][0]); 
            inDegree2[edges2[i][0]]++, inDegree2[edges2[i][1]]++;
        }
        queue<pair<int, int>> q;
        q.push({0, -1});
        int idx = -1;
        while(!q.empty())
        {
            int node = q.front().first, par = q.front().second;
            q.pop();
            idx = node;
            for(auto itr : adj1[node])
            {
                if(itr != par)
                    q.push({itr, node});
            }
        }
        q.push({idx, -1});
        v1 = -1;
        while(!q.empty())
        {
            int sz = q.size();
            v1++;
            while(sz--)
            {
                int node = q.front().first, par = q.front().second;
                q.pop();
                for(auto itr : adj1[node])
                {
                    if(itr != par)
                        q.push({itr, node});
                }
            }
        }
        q.push({0, -1});
        idx = -1;
        while(!q.empty())
        {
            int node = q.front().first, par = q.front().second;
            q.pop();
            idx = node;
            for(auto itr : adj2[node])
            {
                if(itr != par)
                    q.push({itr, node});
            }
        }
        q.push({idx, -1});
        v2 = -1;
        while(!q.empty())
        {
            int sz = q.size();
            v2++;
            while(sz--)
            {
                int node = q.front().first, par = q.front().second;
                q.pop();
                for(auto itr : adj2[node])
                {
                    if(itr != par)
                        q.push({itr, node});
                }
            }
        }
        return max({v1, v2, v1/2 + v2/2 + v1%2 + v2%2 + 1});
    }
};