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
    bool findNode(TreeNode *root, int &node, string &s)
    {
        if(root->val == node)
            return 1;
        if(root->left)
        {
            s.push_back('L');
            if(findNode(root->left, node, s))
                return 1;
            s.pop_back();
        }
        if(root->right)
        {
            s.push_back('R');
            if(findNode(root->right, node, s))
                return 1;
            s.pop_back();
        }
        return 0;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string s1 = "", s2 = "";
        findNode(root, startValue, s1), findNode(root, destValue, s2);
        int idx = -1;
        for(int i = 0; i < min(s1.size(), s2.size()); i++)
        {
            if(s1[i] != s2[i])
            {    
                idx = i;
                break;
            }
        }
        string ans = "";
        if(idx == -1)
        {
            if(s1.size() > s2.size())
            {
                for(int i = 0; i < max(s1.size(), s2.size()) - min(s1.size(), s2.size()); i++)
                    ans.push_back('U');
            }
            else
            {
                for(int i = s1.size(); i < s2.size(); i++)
                    ans.push_back(s2[i]);
            }
        }
        else
        {
            for(int i = idx; i < s1.size(); i++)
                ans.push_back('U');
            for(int i = idx; i < s2.size(); i++)
                ans.push_back(s2[i]);
        }
        return ans;
    }
};