class Solution 
{
public:
    int minimumTimeToInitialState(string word, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = word.length();
        int ans = 1, i = k;
        while(1)
        {
            bool flag = 1;
            int l = 0, r = i%n;
            while(r < n)
            {
                if(word[l] != word[r])
                {
                    flag = 0;
                    break;
                }
                l++,r++;
            }
            if(flag)
                break;
            i += k;
            ans++;
        }
        int ok = n/k;
        if(n%k)
            ok++;
        return min(ans, ok);
    }
};