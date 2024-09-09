/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // Store the east, south, west, north movements in a matrix.
        int i = 0, j = 0, curDir = 0, dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (; head != NULL; head = head->next) 
        {
            ans[i][j] = head->val;
            
            int newi = i + dirs[curDir][0], newj = j + dirs[curDir][1];
            // If we bump into an edge or an already filled cell, change the direction.
            if (min(newi, newj) < 0 || newi >= m || newj >= n || ans[newi][newj] != -1)
                curDir = (curDir + 1) % 4;
            
            i += dirs[curDir][0];
            j += dirs[curDir][1];
        }
        return ans;
    }
};