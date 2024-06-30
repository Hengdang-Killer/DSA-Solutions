class UnionFind 
{
public:
    vector<int> par, sz;
    int components;
    UnionFind(int n) 
    {
        components = n;
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) 
            par[i] = i;
    }
    int find(int x) 
    {
        if (par[x] != x)
            par[x] = find(par[x]);
        return par[x];
    }
    // Union by Size
    bool unite(int x, int y) 
    {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY)
            return false;
        if (sz[rootX] < sz[rootY]) 
            swap(rootX, rootY);
        par[rootY] = rootX;
        sz[rootX] += sz[rootY];
        components--;
        return true;
    }
    bool isConnected() 
    {
        return components == 1;
    }
};
class Solution 
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        UnionFind alice(n), bob(n);
        int edgesRequired = 0;
        
        // Process type 3 edges first
        for (const auto& edge : edges) 
        {
            if (edge[0] == 3) 
            {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) 
                    edgesRequired++;
            }
        }
        
        // Process type 1 and type 2 edges
        for (const auto& edge : edges) 
        {
            if (edge[0] == 1) 
            {
                if (alice.unite(edge[1], edge[2]))
                    edgesRequired++;
            } 
            else if (edge[0] == 2) 
            {
                if (bob.unite(edge[1], edge[2]))
                    edgesRequired++;
            }
        }
        
        // Check if both are fully connected
        if (alice.isConnected() && bob.isConnected())
            return edges.size() - edgesRequired;
        
        return -1;
    }
};