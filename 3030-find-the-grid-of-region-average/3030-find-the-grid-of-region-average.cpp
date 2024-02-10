class Solution 
{
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = image.size(), m = image[0].size();
        vector<vector<int>> mp(n, vector<int>(m, 0));
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        for(int i = 0; i <= n-3; i++)
        {
            for(int j = 0; j <= m- 3; j++)
            {
                bool ok1 = 1, ok2 = 1, ok3 = 1, ok4 = 1, ok5 = 1;
                int sum = 0;
                if(abs(image[i][j] - image[i][j+1]) > threshold)
                    continue;
                if(abs(image[i][j] - image[i+1][j]) > threshold)
                    continue;
                if(abs(image[i+1][j+1] - image[i+1][j+2]) > threshold)
                    continue;
                if(abs(image[i+1][j+1] - image[i+1][j]) > threshold)
                    continue;
                if(abs(image[i+1][j+1] - image[i][j+1]) > threshold)
                    continue;
                if(abs(image[i+1][j+1] - image[i+2][j+1]) > threshold)
                    continue;
                if(abs(image[i+2][j] - image[i+2][j+1]) > threshold)
                    continue;
                if(abs(image[i+2][j] - image[i+1][j]) > threshold)
                    continue;
                if(abs(image[i+2][j+2] - image[i+2][j+1]) > threshold)
                    continue;
                if(abs(image[i+2][j+2] - image[i+1][j+2]) > threshold)
                    continue;
                if(abs(image[i][j+2] - image[i][j+1]) > threshold)
                    continue;
                if(abs(image[i][j+2] - image[i+1][j+2]) > threshold)
                    continue;
                sum += image[i][j] + image[i][j+1] + image[i][j+2];
                sum += image[i+1][j] + image[i+1][j+1] + image[i+1][j+2];
                sum += image[i+2][j] + image[i+2][j+1] + image[i+2][j+2];
                sum = round(sum/9);
                mp[i][j] += sum, mp[i][j+1] += sum, mp[i][j+2] += sum; 
                mp[i+1][j] += sum, mp[i+1][j+1] += sum, mp[i+1][j+2] += sum; 
                mp[i+2][j] += sum, mp[i+2][j+1] += sum, mp[i+2][j+2] += sum; 
                cnt[i][j]++, cnt[i][j+1]++, cnt[i][j+2]++; 
                cnt[i+1][j]++, cnt[i+1][j+1]++, cnt[i+1][j+2]++; 
                cnt[i+2][j]++, cnt[i+2][j+1]++, cnt[i+2][j+2]++; 
            }
        }
        vector<vector<int>> ans = image;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(cnt[i][j])
                {
                    ans[i][j] = round(mp[i][j]/cnt[i][j]);
                }
            }
        }
        return ans;
    }
};