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
    ListNode* mergeNodes(ListNode* head) 
    {
        head = head->next;
        ListNode* root = new ListNode();
        ListNode* ans = root;
        int sum = 0;
        while(head != nullptr)
        {
            if(head->val == 0)
            {
                root->val = sum;
                sum = 0;
                if(head->next)
                {
                    ListNode* temp = new ListNode();
                    root->next = temp;
                    root = root->next;
                }
            }
            else
                sum += head->val;
            head = head->next;
        }
        return ans;
    }
};