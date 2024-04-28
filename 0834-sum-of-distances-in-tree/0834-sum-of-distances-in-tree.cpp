class Solution 
{
private:
    void dfs1(int node, int par, vector<int> adj[], vector<int> &cnt, vector<int> &ans) 
    {
        cnt[node] = 1;
        for (int &itr : adj[node]) 
        {
            if (itr != par) 
            {
                dfs1(itr, node, adj, cnt, ans);
                cnt[node] += cnt[itr];
                ans[node] += ans[itr] + cnt[itr];
            }
        }
    }
    void dfs2(int node, int par, vector<int> adj[], int &N, vector<int> &cnt, vector<int> &ans) 
    {
        for (int &itr : adj[node]) 
        {
            if (itr != par) 
            {
                ans[itr] = ans[node] + N - 2 * cnt[itr];
                dfs2(itr, node, adj, N, cnt, ans);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) 
    {
        vector<int> adj[n], ans(n, 0), cnt(n, 0);
        for (auto &itr : edges) 
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        dfs1(0, -1, adj, cnt, ans);
        dfs2(0, -1, adj, n, cnt, ans);
        return ans;   
    }
};