class Solution 
{
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> trap(deadends.begin(), deadends.end());
        if (trap.count("0000"))
            return -1;
        if(target == "0000")
            return 0;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> vis;
        vis.insert("0000");
        while (!q.empty()) 
        {
            string currentCombination = q.front().first;
            int moves = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) 
            {
                for (int delta : {-1, 1}) 
                {
                    int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = '0' + newDigit;
                    if (vis.find(newCombination) == vis.end() && trap.find(newCombination) == trap.end()) 
                    {
                        if(newCombination == target)
                            return moves + 1;
                        vis.insert(newCombination), q.push({newCombination, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};