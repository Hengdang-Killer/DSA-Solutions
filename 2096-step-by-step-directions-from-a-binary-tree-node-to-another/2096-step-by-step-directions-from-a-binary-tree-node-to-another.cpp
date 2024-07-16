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
    void findNode(TreeNode *root, int &node1, int &node2, string &s1, string &s2, string &cur)
    {
        if(root->val == node1)
            s1 = cur;
        if(root->val == node2)
            s2 = cur;
        if(root->left)
        {
            cur.push_back('L');
            findNode(root->left, node1, node2, s1, s2, cur);
            cur.pop_back();
        }
        if(root->right)
        {
            cur.push_back('R');
            findNode(root->right, node1, node2, s1, s2, cur);
            cur.pop_back();
        }
        return;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string s1 = "", s2 = "", ans = "";
        findNode(root, startValue, destValue, s1, s2, ans);
        int idx = -1;
        for(int i = 0; i < min(s1.size(), s2.size()); i++)
        {
            if(s1[i] != s2[i])
            {    
                idx = i;
                break;
            }
        }
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