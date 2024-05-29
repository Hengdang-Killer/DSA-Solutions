class Solution 
{
public:
    int numSteps(string s) 
    {
        int ans = 0, carry = 0;
        for(int i = s.size()-1; i > 0; i--)
        {
            if(s[i]-'0' + carry == 0)
                carry = 0, ans++;
            else if(s[i] - '0' + carry == 2)
                carry = 1, ans++;
            else
                carry = 1, ans += 2;
        }
        if(carry > 0)
            ans++;
        return ans;
    }
};

// 1101 -> 1110 -> 111 -> 1000 -> 100 -> 10 -> 1