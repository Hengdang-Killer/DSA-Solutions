class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int verticalPieces = 1, horizontalPieces = 1;
        sort(v.rbegin(), v.rend());
        sort(h.rbegin(), h.rend());
        int i = 0, j = 0;
        int ans = 0;
        while(i < v.size() && j < h.size())
        {
            if(v[i] >= h[j])
                ans += v[i]*verticalPieces, horizontalPieces++, i++;
            else
                ans += h[j]*horizontalPieces, verticalPieces++, j++;
        }
        while(i < v.size())
        {
            ans += v[i]*verticalPieces, i++;
        }
        while(j < h.size())
        {
            ans += h[j]*horizontalPieces, j++;
        }
        return ans;
    }
};