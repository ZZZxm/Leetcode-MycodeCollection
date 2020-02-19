/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* start = head;
        ListNode* p = head, * q = head;

        while (n--) q = q->next;
        if (q == NULL) return head->next;

        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;

        return start;
    }
};