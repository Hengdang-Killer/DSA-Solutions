class Solution 
{
public:
    string maximumOddBinaryNumber(string s) 
    {
        int n = s.size(), cnt = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == '0') cnt++;
        if(cnt == n || cnt == 0)
            return s;
        int cnt1 = n - cnt;
        cnt1--;
        s.clear();
        while(cnt1--)
            s.push_back('1');
        while(cnt--)
            s.push_back('0');
        s.push_back('1');
        return s;
    }
};