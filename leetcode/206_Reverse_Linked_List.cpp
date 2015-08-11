/**
** Reverse a singly linked list.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <iostream>
 using namespace std;
 struct ListNode 
 {
    int val;
    ListNode *next;
	ListNode(int x, ListNode *n) : val(x), next(n) {}
 };
// ͷ�巨
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *post, *curr;
		if(!head) return NULL;
		curr = head->next;
		head->next = NULL;
		while(curr)
		{
			post = curr->next;
			curr->next = head;
			head = curr;
			curr = post;
		}
		return head;
    }
	
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	ListNode *pre = head, *post, *curr, **tail;
	if(!head) return NULL;
	
	for(int i = 1; i < m && pre; i++)	
		pre = pre->next;
	cout << pre->val << endl;
	if(!pre->next) return NULL;
	curr = pre->next;
	tail = &curr;
	int count = m;
	while(curr && count < n)
	{
		cout << curr->val << endl;
		post = curr->next;
		curr->next = pre;
		pre = curr;
		curr = post;
		count++;
	}
	cout << curr->val << endl;
	if(!curr && count >= n)
	{
		*tail = curr;
	}
	return head;
}
};

void printList(struct ListNode *head)
{
	struct ListNode *cur = head;
	while(cur != NULL)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	ListNode *head = NULL, *tmp = NULL;
	Solution A;
	char a[] = {1, 2, 3, 4, 5, 6};
	for(int i = 0; i < 6; i++)
	{
		head = new ListNode(a[i], head);
	}
	printList(head);
	//A.reverseBetween(head, 2, 4);
	printList(A.reverseBetween(head, 2, 4));
}