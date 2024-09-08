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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> ans(k);
        // find total size of linked list
        ListNode *cur = head;
        int n = 0;
        while(cur != NULL)
            n++, cur = cur->next;
        
        // size for k parts
        int size = n / k, rem = n % k; 
        cur = head;
        ListNode *prev = cur;
        for(int i = 0; i < k; i++)
        {
            ListNode *newHead = cur;
            int curSize = size;
            if(rem > 0)
                rem--, curSize++;
            while(curSize--)
            {
                prev = cur;
                cur = cur->next;
            }
            if(prev != NULL)
                prev->next = NULL;
            ans[i] = newHead;
        }
        return ans;
    }
};