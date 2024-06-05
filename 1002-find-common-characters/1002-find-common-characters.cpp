class Solution 
{
private:
    const vector<string> a = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"}; 
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<int> freq(26, 1000), temp(26, 0);
        for(auto &itr : words)
        {
            for(auto &itr2 : itr)
            {
                temp[itr2-'a']++;
            }
            for(int i = 0; i < 26; i++)
            {
                freq[i] = min(freq[i], temp[i]);
                temp[i] = 0;
            }
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++)
        {
            while(freq[i] > 0)
            {
                freq[i]--;
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};