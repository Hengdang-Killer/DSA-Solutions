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
    bool check(string &temp, string &ans)
    {
       int i = temp.size()-1, j = ans.size()-1;
        while(i >= 0 && j >= 0)
        {
            if(temp[i] < ans[j])
                return 1;
            else if(temp[i] > ans[j])
                return 0;
            i--, j--;
        }
        if(temp.size() < ans.size())
            return 1;
        return 0;
    }
    void dfs(TreeNode* node, string &temp, string &ans) 
    {
        if (node == NULL) 
            return;
        temp.push_back(char('a' + node->val));
        if (node->left == NULL && node->right == NULL) 
        {
            if (ans.empty() || check(temp, ans))
                ans = temp;
        }
        dfs(node->left, temp, ans);
        dfs(node->right, temp, ans);
        temp.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string ans = "", temp = "";
        dfs(root, temp, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};