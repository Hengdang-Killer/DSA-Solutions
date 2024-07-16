/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
private:
    int recursion(TreeNode* cur, unordered_map<TreeNode*, int> &dp)
    {
        if(dp.find(cur) != dp.end())
            return dp[cur];
        int notTake = 0;
        if(cur->left)
            notTake += recursion(cur->left, dp);
        if(cur->right)
            notTake += recursion(cur->right, dp);
        int take = cur->val;
        if(cur->left && cur->left->left)
            take += recursion(cur->left->left, dp);
        if(cur->left && cur->left->right)
            take += recursion(cur->left->right, dp);
        if(cur->right && cur->right->left)
            take += recursion(cur->right->left, dp);
        if(cur->right && cur->right->right)
            take += recursion(cur->right->right, dp);
        return dp[cur] = max(take, notTake);
    }
public:
    int rob(TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<TreeNode*, int> dp;
        return recursion(root, dp);
    }
};