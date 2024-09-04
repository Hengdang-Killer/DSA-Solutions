class Solution 
{
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        unordered_set<int> ust;
        for(auto &itr : obstacles)
            ust.insert(itr[0] + 30001*itr[1]); // hashed value to reduce memory
        pair<int, int> curPos = {0, 0};
        int ans = 0;
        // 0 : North, 1 : East, 2 : South, 3 : West 
        int curDir = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto &itr : commands)
        {
            if(itr == -1)
                curDir = (curDir + 1) % 4;
            else if(itr == -2)
                curDir = (curDir + 3) % 4;
            else
            {
                vector<int> direction = directions[curDir];
                for (int i = 0; i < itr; i++) 
                {
                    int nextX = curPos.first + direction[0];
                    int nextY = curPos.second + direction[1];
                    if (ust.find(nextX + 30001*nextY) != ust.end()) 
                        break;
                    curPos.first = nextX;
                    curPos.second = nextY;
                }
                ans = max(ans, curPos.first * curPos.first + curPos.second*curPos.second);
            }
        }
        return ans;
    }
};