#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

void merge(vector<ListNode*>& lists, int i, int j)
{
    ListNode* p1 = lists[i], * p2 = lists[j];
    ListNode* mergelist = new ListNode(0);
    ListNode* head = mergelist;


    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val <= p2->val)
        {
            mergelist->next = p1;
            mergelist = mergelist->next;
            p1 = p1->next;
        }
        else
        {
            mergelist->next = p2;
            mergelist = mergelist->next;
            p2 = p2->next;
        }
    }

    if (p1 == NULL)
        mergelist->next = p2;
    else
        mergelist->next = p1;

    lists[i] = head->next;
}


ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    int gap = (n + 1) / 2;

    if (n == 0) return NULL;

    while (n > 1)
    {
        int times = n / 2;
        for (int i = 0; i < times; i++)
        {
            if (i + gap < n)
            {
                merge(lists, i, i + gap);
            }
        }
        if (n == 2) break;
        n = (n + 1) / 2;
        gap = (n + 1) / 2;
    }

    return lists[0];
}