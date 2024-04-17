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
     void dfs(TreeNode* node, string &temp, string &ans) 
     {
        if (node == NULL) 
            return;
        temp.push_back(char('a' + node->val));
        if (node->left == NULL && node->right == NULL) 
        {
            reverse(temp.begin(), temp.end());
            if (ans.empty() || temp < ans)
                ans = temp;
            reverse(temp.begin(), temp.end());
        }
        dfs(node->left, temp, ans);
        dfs(node->right, temp, ans);
         temp.pop_back();
    }
public:
    string smallestFromLeaf(TreeNode* root) 
    {
        string ans = "", temp = "";
        dfs(root, temp, ans);
        return ans;
    }
};