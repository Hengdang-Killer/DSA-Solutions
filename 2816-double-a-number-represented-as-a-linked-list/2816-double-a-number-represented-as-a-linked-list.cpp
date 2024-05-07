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
class Solution {
public:
    ListNode* doubleIt(ListNode* head) 
    {
        vector<int> nums;
        ListNode* p = head;
        while(p)
        {
            nums.push_back(p->val);
            p = p->next;
        }
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            int x = c + nums[i]*2;
            c = x/10;
            nums[i] = x%10;
        }
        if(c != 0)
        {
            nums.push_back(c);
        }
        if(n != nums.size())
            n = nums.size();
        reverse(nums.begin(), nums.end());
        ListNode* ans = new ListNode(nums[0]);
        p = ans;
        for(int i = 1; i < n; i++)
        {
            ListNode* q =  new ListNode(nums[i]);
            p->next = q;
            p = q;
        }
        return ans;
    }
};