/******* 24. Swap Nodes in Pairs ***********/

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
	if (head == NULL) return NULL;
	ListNode* p1 = head;
	ListNode* p2 = p1->next, * q, * r = NULL;
	ListNode* start = p2 == NULL ? p1 : p2;

	while (p1 != NULL && p2 != NULL)
	{
		q = p2->next;
		p2->next = p1;
		p1->next = q;
		if (r != NULL) r->next = p2;
		r = p1;
		p1 = q;
		if (p1 != NULL) p2 = p1->next;
	}

	return start;
}