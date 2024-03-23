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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int k = lists.size();
        if(k == 0)
            return NULL;
        ListNode *head = NULL, *cur;
        vector<ListNode*> v(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < k; i++)
        {
            v[i] = lists[i];
            if(v[i])
                pq.push({v[i]->val, i});
        }
        while(!pq.empty())
        {
            int val = pq.top().first;
            int idx = pq.top().second;
            ListNode *node = v[idx];
            pq.pop();
            if(head == NULL)
                head = node, cur = node;
            else
            {
                cur->next = node;
                cur = cur->next;
            }
            if(v[idx]->next)
            {
                v[idx] = v[idx]->next;
                pq.push({v[idx]->val, idx});
            }
            cur->next = NULL;
        }
        return head;
    }
};