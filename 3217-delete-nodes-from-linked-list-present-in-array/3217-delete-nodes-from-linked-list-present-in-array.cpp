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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_set<int> ust(nums.begin(), nums.end());
        while (head != NULL && ust.count(head->val) > 0) 
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if (head == NULL) 
            return NULL;
        ListNode *cur = head;
        while (cur->next != NULL) 
        {
            if (ust.contains(cur->next->val)) 
            {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } 
            else 
                cur = cur->next;
        }
        return head;
    }
};