class Solution 
{
private:
    int findPar(vector<int> &par, int x) 
    {
        if (par[x] == x) 
            return x;
        par[x] = findPar(par, par[x]);
        return par[x];
    }
    void unionSize(vector<int> &par, vector<int> &size, int x, int y) 
    {
        int xPar = findPar(par, x);
        int yPar = findPar(par, y);
        if (xPar == yPar) 
            return;
        if (size[xPar] < size[yPar]) 
            par[xPar] = yPar, size[yPar] += size[xPar];
        else 
            par[yPar] = xPar, size[xPar] += size[yPar];
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        if (n == 1) 
            return true;
        vector<int> par(n);
        vector<int> size(n, 1);
        unordered_map<int, int> firstOccurrence;
        for (int i = 0; i < n; i++) 
        {
            par[i] = i;
            int val = nums[i], div = 2;
            while (div * div <= val) 
            {
                if (val % div == 0) 
                {
                    if (firstOccurrence.find(div) != firstOccurrence.end())
                        unionSize(par, size, i, firstOccurrence[div]);
                    else 
                        firstOccurrence[div] = i;
                    while (val % div == 0) 
                        val /= div;
                }
                div++;
            }
            if (val > 1) 
            {
                if (firstOccurrence.find(val) != firstOccurrence.end())
                    unionSize(par, size, i, firstOccurrence[val]);
                else
                    firstOccurrence[val] = i;
            }
        }
        return size[findPar(par, 0)] == n;
    }
};
