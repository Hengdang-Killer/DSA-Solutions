class Solution 
{
private:
    string recursion(int &i, string &s)
    {
        string ans = "";
        while(i < s.size() && s[i] != ']')
        {
            if(!isdigit(s[i]))
                ans.push_back(s[i++]);
            else
            {
                int n = 0;
                while(i < s.size() && isdigit(s[i]))
                    n = n*10 + (s[i++]-'0');
                i++; // '['
                string temp = recursion(i, s);
                i++; // ']'
                while(n--)
                    ans += temp;
            }
        }
        return ans;
    }
public:
    string decodeString(string &s) 
    {
        int i = 0;
        return recursion(i, s);
    }
};