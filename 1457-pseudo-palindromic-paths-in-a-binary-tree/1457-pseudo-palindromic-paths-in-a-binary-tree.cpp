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
    void dfs(TreeNode* node, int &cnt, int &ans, unordered_map<int, int> &mp)
    {
        if(node->left)
        {
            mp[node->val]++;
            if(mp[node->val]%2)
                cnt++;
            else
                cnt--;
            dfs(node->left, cnt, ans, mp);
            if(mp[node->val]%2)
                cnt--;
            else
                cnt++;
            if(mp[node->val] == 1)
                mp.erase(node->val);
            else
                mp[node->val]--;
        }
        if(node->right)
        {
            mp[node->val]++;
            if(mp[node->val]%2)
                cnt++;
            else
                cnt--;
            dfs(node->right, cnt, ans, mp);
            if(mp[node->val]%2)
                cnt--;
            else
                cnt++;
            if(mp[node->val] == 1)
                mp.erase(node->val);
            else
                mp[node->val]--;
        }
        if(!node->left && !node->right)
        {
            mp[node->val]++;
            if(mp[node->val]%2)
                cnt++;
            else
                cnt--;
            if(cnt <= 1)
                ans++;
            if(mp[node->val]%2)
                cnt--;
            else
                cnt++;
            if(mp[node->val] == 1)
                mp.erase(node->val);
            else
                mp[node->val]--;
        }
        return;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> mp;
        int ans = 0, cnt = 0;
        dfs(root, cnt, ans, mp);
        return ans;
    }
};